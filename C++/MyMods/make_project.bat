@echo off

cd /d "%~dp0"

cmake -S . -B Output

pause

exit \b