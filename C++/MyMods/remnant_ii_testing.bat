@echo on
setlocal


set "old_ue4ss_cpp_dll=C:\games\manual_install\Remnant2\Remnant2\Binaries\Win64\Mods\UE4SS-cppsdk.dll"
set "new_ue4ss_cpp_dll=C:\Users\Mythical\Documents\GitHub\Remnant2ExampleMods\C++\MyMods\Output\ue4ss\Binaries\x64\Release\UE4SS-cppsdk_xinput.dll"
set "old_ue4ss_xinput_dll=C:\games\manual_install\Remnant2\Remnant2\Binaries\Win64\xinput1_3.dll"
set "new_ue4ss_xinput_dll=C:\Users\Mythical\Documents\GitHub\Remnant2ExampleMods\C++\MyMods\Output\ue4ss\Binaries\x64\Release\xinput1_3.dll"
set "old_example_mod_dll=C:\games\manual_install\Remnant2\Remnant2\Binaries\Win64\Mods\ExampleMod\dlls\main.dll"
set "new_example_mod_dll=C:\Users\Mythical\Documents\GitHub\Remnant2ExampleMods\C++\MyMods\Output\ExampleMod\Debug\ExampleMod.dll"
set "game_exe=C:\games\manual_install\Remnant2\Remnant2\Binaries\Win64\Remnant2-Win64-Shipping.exe"


cd "%~dp0%"


for %%A in ("%new_ue4ss_cpp_dll%" "%old_ue4ss_cpp_dll%") do (
    set "folder=%%~dpA"
    if not exist "!folder!" (
        echo Creating directory: "!folder!"
        mkdir "!folder!"
    )
)


for %%A in ("%new_ue4ss_xinput_dll%" "%old_ue4ss_xinput_dll%") do (
    set "folder=%%~dpA"
    if not exist "!folder!" (
        echo Creating directory: "!folder!"
        mkdir "!folder!"
    )
)


for %%A in ("%new_example_mod_dll%" "%old_example_mod_dll%") do (
    set "folder=%%~dpA"
    if not exist "!folder!" (
        echo Creating directory: "!folder!"
        mkdir "!folder!"
    )
)


if exist "%new_ue4ss_cpp_dll%" (
    if exist "%old_ue4ss_cpp_dll%" (
        del "%old_ue4ss_cpp_dll%"
    )
    copy "%new_ue4ss_cpp_dll%" "%old_ue4ss_cpp_dll%"
)


if exist "%new_ue4ss_xinput_dll%" (
    if exist "%old_ue4ss_xinput_dll%" (
        del "%old_ue4ss_xinput_dll%"
    )
    copy "%new_ue4ss_xinput_dll%" "%old_ue4ss_xinput_dll%"
)


if exist "%new_example_mod_dll%" (
    if exist "%old_example_mod_dll%" (
        del "%old_example_mod_dll%"
    )
    copy "%new_example_mod_dll%" "%old_example_mod_dll%"
)


start "" "%game_exe%"


exit /b