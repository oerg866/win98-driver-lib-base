                    OPTi 82C929 Windows 95 Drivers
                        Version 4.00.00 Beta
                                8/25/95


UPDATE NOTES

    This version supports the following:

    1) Full support for IDE plus propriatory CD-ROMs manufactured by
       SONY, PANASONIC, and MITSUMI (or their compatibles).

    2) Full Hot-Key support under Windows 95 DOS Box. Please see
       HOT-KEY SUPPORT section below for desciption of Hot Keys.

    3) Full mixer support on 929's mixer plus customization capabilities 
       on channel mappings and additions of ON/OFF controls. Please
       see MIXER CUSTOMIZATION section below for more details.



INSTALLATION PROCESS

    Please follow these steps below for a proper installation of the 
    drivers for Windows 95. It is hereby assumed that you already have
    Windows 95 installed and have properly plugged in your Sound Card.

    1. You should have the latest drivers on a floppy diskette ready
       for installation.

    2. Start Windows 95 and proceed to the Control Panel folder and 
       select (double click) the SYSTEM icon.

    3. Select the Device Manager tab to display the list of devices
       currently present on your system. 

    4. Check to see if you have previously installed the device.
       Usually, the device name starts with "OPTi .. Sound System."
       If a previous instance of the device does not exist, exit the
       System Properties dialog box and proceed to STEP 6.

    5. If the device has been installed previously, double click on 
       the device name to expand the list of sub-devices and select 
       "OPTi .. Sound System:..." to remove the set of devices plus
       this parent device. You will not be able to remove child 
       devices which are controlled by this parent device unless this
       parent device is removed. 

       Check also to see if you have previously installed any Windows 
       Sound System or Sound Blaster audio devices or their compatibles, 
       and if so, please remove them from the list.

       Once the devices has been removed, you must restart Windows 95
       and proceed to STEP 6.

    6. Select (double click) the Add New Hardware icon located in the 
       Control Panel folder to add/update the new device and it's
       associated drivers.

    7. When prompted by Windows 95 for the Auto-Scan option for 
       detecting new devices on your System - select NO and proceed
       to the next page.

    8. Windows 95 will display a list of known devices that you 
       currently wish to install. Select "Other Devices" eventhough
       the name of the device is included in the list. This forces
       Windows 95 to perform a fresh install for your device. Select
       Next to proceed.

    9. Windows 95 will again display a list containing manufacturer 
       names and at which point you should ignore the list and select
       the "Have Disk..." button. This tells Windows 95 to read
       special installation instructions from your diskette to 
       correctly install the drivers for your OPTi Sound device.
       You will have to direct Windows 95 to the proper location of 
       the floppy diskette.

   10. Once information from the floppy diskette has been read by
       Windows 95, a list of devices available for installation will
       be displayed. This list includes options such as what type
       of CD-ROM that you wish to connect to your Sound Card (meaning
       using the connectors on your Sound Card for your CD-ROM 
       interface). Select the correct CD-ROM type combination that
       you desire but make sure that the CD-ROM has already been 
       installed and connected to your Sound Card. If you do not wish 
       to use your Sound Card for CD-ROM support (as a CD-ROM controller),
       just select the basic option which includes only the Sound/Game
       support. 

   11. Select Next and Windows 95 will proceed to install the drivers
       needed for your device and configure your device accordingly.
       Once your device has been successfully configured, Windows 95
       will prompt you to restart your system - select No to skip this
       restart process since you should have your Sound Card properly
       plugged in and installed. If however your Sound Card has not 
       been correctly installed, you will have to select Yes to 
       restart Windows 95.



CONNECTING EXTERNAL DEVICES

    Wave Table Device

    To enable driver support for your Wave Table device, you will need
    to reconfigure the "OPTi .. Sound System: Sound/Game.." device
    properties and change the settings to use "Basic Configuration 0."



RECONFIGURATION OF RESOURCES

    The resources for OPTi 82C929 should be reconfigurable on-the-fly 
    unless due to a similar conflicting device present in the system.

    To reconfigure the resources, use the SYSTEM icon located in your
    Control Panel folder and choose Device Manager. From Device Manager,
    double click the "OPTi .. Sound System" option and the list of 
    sub-devices will be displayed. Double click on the "OPTi .. Sound
    System: Sound/Game..." device to change the desired resources for
    this parent and it's child devices.

    Once resources have been changed, the driver will be reconfigured 
    to operate with the new resources and function as before. You may 
    be asked to restart your system and at which point you may select
    No since Windows 95 should have reconfigured your device 
    accordingly.



AUDIO SUPPORT under REAL MODE DOS

    To enable support for DOS Games or multimedia applications under
    a REAL MODE DOS environment, please install the deluxe SNDINIT
    package for 82C929. When prompted during the installation for
    the path to your Windows directory, specify the path if you have
    Windows 3.1 installed on your system (under a seperate directory
    from Windows 95). Select None if you do not have Windows 3.1
    installed.



AUDIO SUPPORT under WINDOWS 95 DOS BOX

    DOS Game support has been added for this release and is fully 
    functional. During the setup for your DOS games, you must ensure that
    the current resources assigned to the sound card matches with the
    current settings requested by your DOS game. To find out what resources
    are currently assigned to the sound card, proceed to open the properties
    box associated with the "OPTi .. Sound System" (Device Manager)
    and select the Resource tab. From the Resources box, you should see the
    current I/O Address range for Input/Output Range Number 1. We recommend 
    the 220 Hex address range as opposed to the 240 Hex be selected as most 
    games support 220 Hex by default. We also recommend the Interrupt and 
    Direct Memory Access settings of 7 and 1 respectively. Reconfigure these 
    resources as appropriate and select OK for Device Manager to dynamically 
    change and update your current resources and configure the hardware. 
    At this point, you may setup your DOS game with the settings which you 
    have just configured.

    Also, if you have a Wave Table Device on board or attached to your
    sound card, you should also follow the recommended steps above but
    this time check on the "OPTi .. MPU-401" device settings
    instead. You will need it's current settings if you wish to enable
    General MIDI support in your DOS games.

    To ensure an ideal environment for DOS games, it is recommended that
    you modify the Idle Sensitivity property of your DOS Game environment
    to High. To do this, press the ALT+ENTER keys to change to a DOS Box
    Window (if not already in a Windowed session) and click on the top left
    hand corner of the DOS Box Window. A drop down menu will appear and
    at which point you should select Properties. Select the Misc tab and
    proceed to modify the above mentioned property.



HOT-KEY SUPPORT under WINDOWS 95 DOS BOX

    The following are the Hot-Keys and their associated channel controls.

    <CNTRL>+<ALT>+M     = Decrease Master Volume
    <SHIFT>+<ALT>+M     = Increase Master Volume
    <CNTRL>+<SHIFT>+M   = Mute Master Volume

    <CNTRL>+<ALT>+V     = Decrease Voice (Digital Sound) Volume
    <SHIFT>+<ALT>+V     = Increase Voice (Digital Sound) Volume
    <CNTRL>+<SHIFT>+V   = Mute Voice (Digital Sound) Volume

    <CNTRL>+<ALT>+F     = Decrease FM Music Volume
    <SHIFT>+<ALT>+F     = Increase FM Music Volume
    <CNTRL>+<SHIFT>+F   = Mute FM Music Volume



MIXER CUSTOMIZATION

    Mixer driver customization info should be specified in the SND929P.IN_
    file which is located in the installation diskette and is required by
    Windows 95 during installation of the drivers. 

    By default, this file instructs the Mixer driver not to support
    any customizations and only the manufacturer's default channel
    mappings and controls are supported.

    To enable mixer customizations, proceed to the [CUSTOM.AddReg]
    section in this file and modify the "Default_Codec_Mapping"
    field from "Yes" to "No". This tells the mixer driver not to
    use the manufacturer's default mixer mappings but to expect
    customized channels mappings and controls instead.


    TYPE 1) Channel Mapping Customization

      The following are defaults:
      ..,AUX1_Src_Name,,"CD"                // For AUX 1 Channel
      ..,AUX2_Src_Name,,"Synth"             // For AUX 2 Channel
      ..,DAC_Src_Name,,"Wave"               // For LOC and ROC channels

      Below are supported only if you have the extended CODEC on board
      such as CS4231 or AD1845.

      ..,LINE_Src_Name,,"Line"              // For LINE Channel

      ..,MIC_Src_Name,,"Mic"                // For Microphone Channel
                                            // Supported by AD1845 Only

      ..,MONOIN_Src_Name,,"Alarm"           // 


      Channel mapping customization allows renaming of a source to
      a different name thus changing the original assumed source
      mapping of the channel. 


    TYPE 2) Extra internal controls through existing H/W resource 
            - for controls using general purpose output bits of CODEC 
            or MC device.

      These internal controls are of the ON/OFF type controlled by a
      single toggling bit.

      The following are valid:

      ..,Total_Internal_Controls,1,n    // Total number of controls desired,
                                        // maximum is 3.
                                        // Default is assumed to be none.

      ..,Internal_Control_1_Name,,"SRS-3D"    // Name to call this control.
      ..,Internal_Control_1_OnVal,1,00 or 01   // What is the default ON bit.
      ..,Internal_Control_1_By,,"XCTL0" or "XCTL1"

         // What bits to use for control based on the following
         // available on the default H/W.
         XCTL0 - OUT 0 bit located at index 10 of CODEC registers
         XCTL1 - OUT 1 bit located at index 10 of CODEC registers

        
      ..,Internal_Control_2_Name,,""
      ..,Internal_Control_2_OnVal,1,00 or 01
      ..,Internal_Control_2_By,,""

        .
        .

      ..,Internal_Control_n_Name,,""
      ..,Internal_Control_n_OnVal,1,00 or 01
      ..,Internal_Control_n_By,,""


    TYPE 3) Extra external controls through external logic 
            (Requires DLL from third party).

      ..,Total_External_Controls,1,n  // Total number of controls desired,
                                      // maximum is 3.
                                      // Default is assumed to be none.

      ..,External_Control_1_Name,,"SRS-3D"    // Name to call this control.
      ..,External_Control_1_By,,"XCONT_1.DLL" // The accompanying DLL. Each
                                              // external control has it's own
                                              // unique DLL.

      ..,External_Control_2_Name,,""          // Name to call this control.
      ..,External_Control_2_By,,"XCONT_2.DLL"

      ..,External_Control_3_Name,,""          // Name to call this control.
      ..,External_Control_3_By,,"XCONT_3.DLL"


      Each external control has it's own set of exported functions for 
      the driver to call. For example, external control 1 will have the
      following 3 functions:

                XControl_1_Init();
                XControl_1_On();
                XControl_1_Off();

      The accompanying DLL must export these functions exactly as 
      named above.



    ** NOTES **

    1) Internal and External Controls must be of the ON/OFF control types; 
       any other types are not supported for now.



                                %% END %%
