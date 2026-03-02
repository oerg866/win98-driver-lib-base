import os
import argparse
import subprocess
import sys
import re

from wininfparser import WinINF, INFsection

# Retreive the real spelling of a key, case insensitive,  from an INF section 
def findKey(section: INFsection, toFind: str):
    for key, value, comment in section:
        if (key.lower() == toFind.lower()):
            return key

    return None

# Get INFsection from given section name, case-insensitively
def getSection(inf: WinINF, section: str):
    toFind = section.lower().strip()
    for sec in inf:
        if sec.GetName().lower().strip() == toFind:
            return sec
    return None

# Get the value for a given key in the given INF sectioni, case insensitively. Returns "" if nonexistant
def getValue(section: INFsection, toFind:str):
    for key, value, comment in section:
        if (key.lower() == toFind.lower()):
            return value
        
    return ""

def splitInfValue(value: str) -> list[str]:
    result = []
    current = []
    in_quotes = False

    for ch in value:
        if ch == '"':
            in_quotes = not in_quotes
            continue  # don't include the quote itself

        if ch == ',' and not in_quotes:
            result.append(''.join(current).strip())
            current = []
        else:
            current.append(ch)

    # append last field
    if current:
        result.append(''.join(current).strip())

    return result


def ndisInfIntParam(section: INFsection, paramName: str, valueRange:str, default: str):
    paramRange = splitInfValue(valueRange)
    min = paramRange[0]
    max = paramRange[1]
    step = paramRange[2]

    print(f'NDIS INF Param "{paramName}" (Int): Range {min}-{max}, step {step}, default {default}')

    section.AddData(f'HKR,Ndi\\params\\{paramName},default,,{default}')
    section.AddData(f'HKR,Ndi\\params\\{paramName},min,,{min}')
    section.AddData(f'HKR,Ndi\\params\\{paramName},max,,{max}')
    section.AddData(f'HKR,Ndi\\params\\{paramName},step,,{step}')
    section.AddData(f'HKR,Ndi\\params\\{paramName},base,,10')
    section.AddData(f'HKR,Ndi\\params\\{paramName},type,,int')

def ndisInfTextParam(section: INFsection, paramName: str, valueRange:str, default: str):
    # In text params, this isn't a range but just a CSV list of possible values.
    paramRange = splitInfValue(valueRange)

    print(f'NDIS INF Param "{paramName}" (Text/Enum): Values: {paramRange}, default {default}')

    section.AddData(f'HKR,Ndi\\params\\{paramName},default,,{default}')
    section.AddData(f'HKR,Ndi\\params\\{paramName},type,,enum')

    for val in paramRange:
        section.AddData(f'HKR,Ndi\\params\\{paramName},{val},,"{val}"')

def ndisInfCharsParam(section: INFsection, paramName: str, valueRange:str, default: str):
    # Chars param is a manual text field
    # The range param is the size of the text field
    limitText = int(valueRange, base=0)

    print(f'NDIS INF Param "{paramName}" (Chars/Edit): Maximum length {limitText} default {default}')

    section.AddData(f'HKR,Ndi\\params\\{paramName},default,,"{default}"')
    section.AddData(f'HKR,Ndi\\params\\{paramName},LimitText,,{limitText}')
    section.AddData(f'HKR,Ndi\\params\\{paramName},type,,edit')

def getPciParamsFromArg(arg: str):
    devSplit = arg.split(':')

    pciSubsys = None
    pciRev = None
    pciName = '%DEVICE%'

    if len(devSplit) < 2: raise Exception('ID parameter requires at least Vendor and Device ID')

    pciVen = devSplit[0]
    pciDev = devSplit[1]

    if len(devSplit) >= 3: pciSubsys = devSplit[2].strip()
    if len(devSplit) >= 4: pciRev    = devSplit[3].strip()
    if len(devSplit) >= 5: pciName   = f'"{splitInfValue(devSplit[4])[0].strip()} (NDIS2)"'

    if pciSubsys and len(pciSubsys) == 0: pciSubsys = None
    if pciRev    and len(pciRev)    == 0: pciRev    = None
    
    return pciVen, pciDev, pciSubsys, pciRev, pciName

def getAdditionalPciIds(pciSection: INFsection) -> list[str]:
    intelVen = getValue(pciSection, 'VENDOR_ID')

    # Here we have a problem: The entries are separated by semicolon.
    # But semicolons in INFs mean everything afterwards is a COMMENT. 
    # So we have to stitch it back together manually XD

    intelDevList = []
    for key, value, comment in pciSection:
        if key.lower() == 'device_id':
            devListString = f'{value};{comment}'
            intelDevList = devListString.split(';')

    ret = []

    for dev in intelDevList:
        print(f'Adding extra PCI ID: {intelVen}:{dev}')
        ret.append(f'{intelVen}:{dev}')
    return ret

# pci.ids parser for python
# Written by SpareSimian
# https://gist.github.com/SpareSimian/7ced6ec92eb6566e8a0acce5591af0b9
def genPCIIdsDictionary():
    re_vendor = re.compile(r'(?P<vendor>[a-z0-9]{4})\s+(?P<vendor_name>.*)')
    re_device = re.compile(r'\t(?P<device>[a-z0-9]{4})\s+(?P<device_name>.*)')
    re_subsys = re.compile(r'\t\t(?P<subvendor>[a-z0-9]{4})\s+(?P<subdevice>[a-z0-9]{4})\s+(?P<subsystem_name>.*)')

    data = {}
    vendor = ''
    device = ''
    
    with open("pci.ids", "rt") as fp:
        for line in fp:
            m = re_vendor.match(line)
            if m:
                d = m.groupdict()
                d['devices'] = {}
                vendor = m.group('vendor')
                data[vendor] = d
            else:
                m = re_device.match(line)
                if m:
                    d = m.groupdict()
                    d['subdevices'] = []
                    device = m.group('device')
                    data[vendor]['devices'][device] = d
                else:
                    m = re_subsys.match(line)
                    if m:
                        data[vendor]['devices'][device]['subdevices'].append(m.groupdict())
    return data

def argToInfId(arg: str):
    ven, dev, subsys, rev, name = getPciParamsFromArg(arg)

    infID = f'PCI\\VEN_{ven.upper()}&DEV_{dev.upper()}'

    if subsys: infID += f'&SUBSYS_{subsys.upper()}'
    if rev:    infID += f'&REV_{rev.upper()}'

    return infID

def doesLineInListContain(lines: list[str], toFind: str):
    for line in lines:
        if toFind in line: return True
    return False


# Takes a ven:dev:name style string list and checks if the INF file infFileToFilter contains this ID
# if yes, the string is removed from the output list
def getFilteredPciIdsList(pciIds: list[str], infFileToFilter:str) ->list[str]:
    newList = []
    filterInf = WinINF()
    filterInf.ParseFile(infFileToFilter)

    allInfLines = []
    for section in filterInf:
        for k, v, c in section:
            stripped = v.strip()
            if len(v.strip()) > 0:
                allInfLines.append(v.lower())

    for id in pciIds:
        infId = argToInfId(id).lower()
        if (doesLineInListContain(allInfLines, infId)):
            # INF already contains this ID, so skip it
            print(f'Skipping already existing PCI ID {infId}')
        else:
            # Inf doesn't contain this ID! Hooray!
            newList.append(id)
                
    return newList

# Get a correctly capitalized filename in the source directory (so a case insensitive lookup)
def getFilenameCaseInsensitive(sourceDir: str, filename: str):
    if not os.path.exists(sourceDir):
        raise Exception(f"Source directory {sourceDir} doesn't exist?!")

    for f in os.listdir(sourceDir):
        if f.lower() == filename.lower():
            # File name matches, return full path
            return os.path.join(sourceDir, f)

    return None

################################################################################################################################################

parser = argparse.ArgumentParser(description='NDIS2 to Windows 9x INF converter v2.0', formatter_class=argparse.ArgumentDefaultsHelpFormatter)

parser.add_argument('--id', type=str, help='PCI Vendor/device ID (hexadecimal string in the format of ven:dev:subsys:rev:name, params can be skipped, i.e. "10EC:8139::4:"Realtek 8139 PCI Fast Ethernet"") - the ":name" part is optional, if not present it will use the default name', action="append", required=False)
parser.add_argument('--inf', type=str, help='NDIS 2 driver OEMSETUP.INF file')
parser.add_argument('--dir', type=str, help='NDIS 2 driver dir containing OEMSETUP.INF file')
parser.add_argument('--out', type=str, help='Windows 9x INF output file name', required=True)
parser.add_argument('--rel', action='store_true', help='Treat --out parameter as relative to source directory', default=False)
parser.add_argument('--lookup', help='Look up device names in pci.ids', required=False, default=False, action='store_true')
parser.add_argument('--exclude', type=str, help='Exclude all PCI IDs found in this INF file', required=False)

args = parser.parse_args()

if args.inf is None and args.dir is None:
    raise Exception('Need either --inf or --dir parameter')

if args.inf and args.dir:
    raise Exception('--inf and --dir cannot be specified together')

if args.dir:
    infFile = getFilenameCaseInsensitive(args.dir, 'oemsetup.inf')
else:
    infFile = args.inf

if args.rel:
    outFile = os.path.join(os.path.dirname(os.path.abspath(infFile)), args.out)
else:
    outFile = args.out

if infFile is None or os.path.exists(infFile) == False:
    raise Exception('Cannot find OEMSETUP.INF')

# Parse the PCI IDs table
if args.lookup:
    pciIdDict = genPCIIdsDictionary()

# Read the OEMSETUP file

inf = WinINF()
inf.ParseFile(infFile)

# Get netcard section.
netcardSec = getSection(inf, 'netcard')

if not netcardSec:
    raise Exception('File has no netcard section!')

drvSection = None
nifSection = None

for key,value,comment in netcardSec:
    infValues = splitInfValue(value)

    # Value field 0 = Device name
    # Value field 5 is driver file info section
    # Value field 6 is the NIF section we need.

    deviceName = infValues[0]
    drvSection = getSection(inf, infValues[5])
    nifSection = getSection(inf, infValues[6])

    # We can only handle one device.
    break

if not drvSection:
    raise Exception('File has no driver section!')
if not nifSection:
    raise Exception('File has no NIF section!')

print(f'DRV Section: {drvSection.GetName()}')
print(f'NIF Section: {nifSection.GetName()}')

# First try to find the driver name (e.g. EB100$) and file (e.g. EB100.DOS)
driverName = splitInfValue(getValue(nifSection, 'DriverName'))[0]
driverFile = splitInfValue(getValue(drvSection, 'device'))[0]

print(f'Driver Name: {driverName}')
print(f'Driver File: {driverFile}')

# Parse additional PCI IDs from intel style INFs
pciIds = list[str]()

if args.id:
    pciIds += args.id

pciSection = getSection(inf, 'PCI')

if pciSection:
    print('Intel-Style Network Driver detected, adding PCI IDs')
    pciIds += getAdditionalPciIds(pciSection)

# Now we must check for exclusion

if args.exclude:
    pciIds = getFilteredPciIdsList(pciIds, args.exclude)

# If we have nothing after that, we quit
if len(pciIds) < 1:
    raise Exception('No PCI IDs provided and none found in OEMSETUP!')

# Create inf file
outInf = WinINF()
outVersion = INFsection()
outVersion.SetName('Version')
outVersion.AddComment('NDIS2 Wrapper INF v2.0')
outVersion.AddComment('(C) 2026 Eric Voirin (oerg866@googlemail.com)')
outVersion.AddComment('http://github.com/oerg866/ndis2infer9x')
outVersion.AddComment(f'Command Line: [{subprocess.list2cmdline(sys.argv)}]')
outVersion.AddData('LayoutFile', 'layout.inf')
outVersion.AddData('Signature', '$CHICAGO$')
outVersion.AddData('Class', 'Net')
outVersion.AddData('Provider', '%VENDOR%')
outInf.AddSection(outVersion)

outManufacturer = INFsection()
outManufacturer.SetName('Manufacturer')
outManufacturer.AddData('%VENDOR%', 'ND2WRAP')
outInf.AddSection(outManufacturer)

outNd2wrap = INFsection()
outNd2wrap.SetName('ND2WRAP')

# Iterate through every supplied ID (we have to do this again later for the NDI device reg key section)
idCount = 0


for id in pciIds:
    pciVen, pciDev, pciSubsys, pciRev, pciName = getPciParamsFromArg(id)

    # If we specified the lookup, we look up the PCI ID and get the name from pci.ids
    if args.lookup:
        pciVenL = pciVen.lower()
        pciDevL = pciDev.lower()

        if pciVenL in pciIdDict and pciDevL in pciIdDict[pciVenL]['devices']:
            pciName = '"' + pciIdDict[pciVenL]['devices'][pciDevL]['device_name'] + ' (NDIS2)"'

    outNd2wrap.AddData(f'{pciName}', f'nd2wrap{idCount}.ndi,{argToInfId(id)}')
    idCount +=1

outInf.AddSection(outNd2wrap)

outSDNames = INFsection()
outSDNames.SetName('SourceDisksNames')
outSDNames.AddData('1', '"Oerg866 NDIS2INFER9X Driver",,')
outInf.AddSection(outSDNames)

outSDFiles = INFsection()
outSDFiles.SetName('SourceDisksFiles')
outSDFiles.AddData(f'{driverFile}', '1')
outInf.AddSection(outSDFiles)

# Now iterate for every HW ID and add an NDI Section for each of them
idCount = 0

ndiSections = list[INFsection]()
regSections = list[INFsection]()

for id in pciIds:
    pciVen, pciDev, pciSubsys, pciRev, pciName = getPciParamsFromArg(id)
    tmpNdiSection = INFsection()
    tmpNdiSection.SetName(f'nd2wrap{idCount}.ndi')
    tmpNdiSection.AddData(f'AddReg', f'nd2wrap{idCount}.ndi.reg,nd2wrap.ndi.reg')
    ndiSections.append(tmpNdiSection)

    tmpRegSection = INFsection()
    tmpRegSection.SetName(f'nd2wrap{idCount}.ndi.reg')
    tmpRegSection.AddData(f'HKR,Ndi,DeviceID,,"{argToInfId(id)}"')
    ndiSections.append(tmpRegSection)
    idCount +=1

for s in ndiSections:
    outInf.AddSection(s)

for s in regSections:
    outInf.AddSection(s)

# Now add general nd2wrap.ndi.reg section
driverNameWithoutDollar = driverName.replace('$', '')

nd2wrapNdiRegSection = INFsection()
nd2wrapNdiRegSection.SetName('nd2wrap.ndi.reg')
nd2wrapNdiRegSection.AddData(f'HKR,,DevLoader,,*ndis')
nd2wrapNdiRegSection.AddData(f'HKR,,EnumPropPages,,"netdi.dll,EnumPropPages"')
nd2wrapNdiRegSection.AddComment(f' NDIS Info')

nd2wrapNdiRegSection.AddData(f'HKR,NDIS,LogDriverName,,"{driverNameWithoutDollar}"')
nd2wrapNdiRegSection.AddData(f'HKR,NDIS,MajorNdisVersion,1,03')
nd2wrapNdiRegSection.AddData(f'HKR,NDIS,MinorNdisVersion,1,0A')
nd2wrapNdiRegSection.AddData(f'HKR,NDIS\\NDIS2,DriverName,,"{driverName}"')
nd2wrapNdiRegSection.AddData(f'HKR,NDIS\\NDIS2,FileName,,"{driverFile}"')
nd2wrapNdiRegSection.AddComment(f' Interfaces')
nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\Interfaces,DefUpper,,"ndis2"')
nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\Interfaces,DefLower,,"ethernet"')
nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\Interfaces,UpperRange,,"ndis2"')
nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\Interfaces,LowerRange,,"ethernet"')
nd2wrapNdiRegSection.AddComment(f' Install sections')
nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\Install,ndis2,,"nd2wrap.inst.ndis2"')
nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\Remove,ndis2,,"nd2wrap.rmv.ndis2"')

# Now add parameters

for key, value, comment in nifSection:
    if key.lower() != 'param':
        continue

    # Split the parameter
    splitParam = splitInfValue(value)

    paramType = splitParam[2].lower()
    paramDesc = splitParam[1]
    paramName = splitParam[0]
    valueRange = splitParam[3]
    default = splitParam[4]
    flags = int(splitParam[5], base=0)

    if paramType == 'static': 
        print('Skipping unimplemented "static" param')
        continue

    nd2wrapNdiRegSection.AddComment(f'Original NDIS2 Parameter: {value}')
    nd2wrapNdiRegSection.AddData(f'HKR,Ndi\\params\\{paramName},ParamDesc,,"{paramDesc}"')

    if (paramType == 'int'):
        ndisInfIntParam(nd2wrapNdiRegSection, paramName, valueRange, default)
    elif (paramType == 'text'):
        ndisInfTextParam(nd2wrapNdiRegSection, paramName, valueRange, default)
    elif (paramType == 'chars'):
        ndisInfCharsParam(nd2wrapNdiRegSection, paramName, valueRange, default)
    else:
        raise Exception(f'Unknown parameter type {paramType}')
    
    nd2wrapNdiRegSection.AddData('')
    # Empty line after every parameter


nd2wrapNdiRegSection.AddData(f'HKR,,MsPciScan,0,"2"')
outInf.AddSection(nd2wrapNdiRegSection)

nd2wrapInstSection = INFsection()
nd2wrapInstSection.SetName('nd2wrap.inst.ndis2')
nd2wrapInstSection.AddData('CopyFiles', 'nd2wrap.ndis2.CopyFiles')
nd2wrapInstSection.AddData('AddReg', 'nd2wrap.inst.ndis2.reg')
outInf.AddSection(nd2wrapInstSection)

nd2wrapRmvSection = INFsection()
nd2wrapRmvSection.SetName('nd2wrap.rmv.ndis2')
nd2wrapRmvSection.AddData('AddReg', 'nd2wrap.rmv.ndis2.reg')
outInf.AddSection(nd2wrapRmvSection)

nd2wrapInstReg = INFsection()
nd2wrapInstReg.SetName('nd2wrap.inst.ndis2.reg')
nd2wrapInstReg.AddData(f'HKLM,"Software\\Microsoft\\Windows\\CurrentVersion\\Network\\Real Mode Net",{driverFile},,low')
outInf.AddSection(nd2wrapInstReg)

nd2wrapRmvReg = INFsection()
nd2wrapRmvReg.SetName('nd2wrap.rmv.ndis2.reg')
nd2wrapRmvReg.AddData(f'HKLM,"Software\\Microsoft\\Windows\\CurrentVersion\\Network\\Real Mode Net",{driverFile}')
outInf.AddSection(nd2wrapRmvReg)

nd2wrapCopyFiles = INFsection()
nd2wrapCopyFiles.SetName('nd2wrap.ndis2.CopyFiles')
nd2wrapCopyFiles.AddData(f'{driverFile}')
outInf.AddSection(nd2wrapCopyFiles)

destinationDirs = INFsection()
destinationDirs.SetName('DestinationDirs')
destinationDirs.AddData(f'nd2wrap.ndis2.CopyFiles', '26')
outInf.AddSection(destinationDirs)

strings = INFsection()
strings.SetName('Strings')
strings.AddData(f'VENDOR', '"NDIS2INFER by Oerg866"')
strings.AddData(f'DEVICE', f'"{deviceName} (NDIS2)"')
outInf.AddSection(strings)


# Add empty line in every section for readability
for s in outInf:
    s.AddData('')

outInf.Save(outFile, 'cp1252')

