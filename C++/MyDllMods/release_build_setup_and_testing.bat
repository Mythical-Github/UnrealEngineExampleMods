@echo on
setlocal enabledelayedexpansion


rem These are the ones you need to manually specify


rem This is the main game folder, like "../steamapps/common/Remnant2"
rem Example:
rem "game_dir=C:\games\manual_install\Remnant2"
set "game_dir=C:\games\manual_install\Remnant2"


rem This is the game project name, like the latter dir here "../steamapps/common/Remnant2/Remnant2"
rem Example:
rem set "game_project_name=Remnant2"
set "game_project_name=Remnant2"


rem This is the name of the game's exe in the Binaries/Win64 directory
rem Example:
rem set "%game_project_name%=Remnant2-Win64-Shipping.exe"
set "game_exe_name=Remnant2-Win64-Shipping.exe"


rem Code below this shouldn't need manual changes


rem Changes the working dir to the one the script is in
cd "%~dp0%"


set "latest_path="
set "latest_version="
set "output_dir=Output"
set "solution=Output\MyDllMods.sln"
set "game_exe=%game_dir%\%game_project_name%\Binaries\Win64\%game_exe_name%"
set "old_ue4ss_cpp_dll=%game_dir%\%game_project_name%\Binaries\Win64\Mods\UE4SS-cppsdk.dll"
set "old_ue4ss_xinput_dll=%game_dir%\%game_project_name%\Binaries\Win64\xinput1_3.dll"
set "old_example_mod_dll=%game_dir%\%game_project_name%\Binaries\Win64\Mods\ExampleMod\dlls\main.dll"
set "new_ue4ss_xinput_dll=Output\ue4ss\Binaries\x64\Release\xinput1_3.dll"
set "new_ue4ss_cpp_dll=Output\ue4ss\Binaries\x64\Release\UE4SS-cppsdk_xinput.dll"
set "new_example_mod_dll=Output\ExampleMod\Release\ExampleMod.dll"
set "old_ue4ss_cpp_pdb=%game_dir%\%game_project_name%\Binaries\Win64\Mods\UE4SS-cppsdk.pdb"
set "old_ue4ss_xinput_pdb=%game_dir%\%game_project_name%\Binaries\Win64\xinput1_3.pdb"
set "old_example_mod_pdb=%game_dir%\%game_project_name%\Binaries\Win64\Mods\ExampleMod\pdbs\main.pdb"


rem Only generates the solution if it already hasn't been
if not exist "%solution%" (
    cmake -S . -B %output_dir%
) else (
    echo "Solution already exists. Skipping CMake."
)


rem Searching for MSBuild.exe for automated building
for /f "tokens=*" %%i in ('dir /b /s "%ProgramFiles%\Microsoft Visual Studio\*" "%ProgramFiles(x86)%\Microsoft Visual Studio\*" 2^>nul ^| findstr /i "\\MSBuild\\Current\\Bin\\MSBuild.exe"') do (
    for /r "%%~dpi" %%f in (MSBuild.exe) do (
        set "msbuild_version=%%~nf"
        set "msbuild_path=%%~dpi"
        if "!msbuild_version!" gtr "!latest_version!" (
            set "latest_version=!msbuild_version!"
            set "latest_path=!msbuild_path!"
        )
    )
)


if defined latest_path (
    echo MSBuild version: %latest_version%
    echo MSBuild path:   %latest_path%\MSBuild.exe
	set ms_build_path="%latest_path%\MSBuild.exe"
) else (
    echo MSBuild not found on this system.
)


rem Building solution
%ms_build_path% %solution% /p:Configuration=Release /p:Platform=x64


rem Copying newly built files over
setlocal


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


if exist "%old_ue4ss_cpp_pdb%" (
    del "%old_ue4ss_cpp_pdb%"
)


if exist "%old_ue4ss_xinput_pdb%" (
    del "%old_ue4ss_xinput_pdb%"
)


if exist "%old_example_mod_pdb%" (
    del "%old_example_mod_pdb%"
)


rem Running game with newly built files
"%game_exe%"


exit /b
