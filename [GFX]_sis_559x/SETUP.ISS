[InstallShield Silent]
Version=v3.00.000
File=Response File

[Application]
Name=SiS Multimedia Package
Version=1.13.53
Company=Silicon Integrated Systems Corp.

[DlgOrder]
Dlg0=SdWelcome-0
Count=5
Dlg1=SdSetupType-0
Dlg2=SdSelectFolder-0
Dlg3=SdStartCopy-0
Dlg4=SdFinishReboot-0

[SdWelcome-0]
Result=1

[SdSetupType-0]
szDir=C:\Program Files\SiS_MM1.13.53
Result=301

[SdSelectFolder-0]
szFolder=SiS Multimedia V1.13.53
Result=1

[SdStartCopy-0]
Result=1

[SdFinishReboot-0]
Result=1
BootOption=0
