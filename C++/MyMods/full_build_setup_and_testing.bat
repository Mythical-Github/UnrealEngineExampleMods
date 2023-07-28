@echo on
setlocal enabledelayedexpansion


set "latest_version="
set "latest_path="


cd "%~dp0%"


call make_project.bat


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


set solution=%cd%\Output\MyMods.sln


%ms_build_path% %solution% /p:Configuration=Release /p:Platform=x64


call remnant_ii_testing.bat


echo got to end of testing script


exit /b
