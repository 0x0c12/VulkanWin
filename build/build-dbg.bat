@ECHO OFF

REM Build, debug mode

ECHO "Building everything with debug..."

SET rootpath=C:\dev\VulkanWin

PUSHD %rootpath%\build\Debug
CALL build_engine.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error: %ERRORLEVEL% && exit)

PUSHD %rootpath%\build\Debug
CALL build_playground.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error: %ERRORLEVEL% && exit)

ECHO "All targets built successfully!"
