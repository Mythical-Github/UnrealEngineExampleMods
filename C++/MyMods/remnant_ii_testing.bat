@echo on
setlocal


set "old_dll=C:\games\manual_install\Remnant2\Remnant2\Binaries\Win64\Mods\ExampleMod\dlls\main.dll"
set "new_dll=C:\Users\Mythical\Documents\GitHub\Remnant2ExampleMods\C++\MyMods\Output\ExampleMod\Debug\ExampleMod.dll"
set "game_exe=C:\games\manual_install\Remnant2\Remnant2\Binaries\Win64\Remnant2-Win64-Shipping.exe"


cd "%~dp0%"


for %%A in ("%new_dll%" "%old_dll%") do (
    set "folder=%%~dpA"
    if not exist "!folder!" (
        echo Creating directory: "!folder!"
        mkdir "!folder!"
    )
)


if exist "%new_dll%" (
    if exist "%old_dll%" (
        del "%old_dll%"
    )
    copy "%new_dll%" "%old_dll%"
)


start "" "%game_exe%"

