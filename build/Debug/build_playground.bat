REM build script for playground
REM only build after engine dll is built
@ECHO OFF
SetLocal EnableDelayedExpansion

REM You can change project path to the location where repository was cloned
SET projpath=C:\dev\VulkanWin\

REM get a list of all source files
SET cfilenames=
FOR /R "%projpath%Playground\src" %%f in (*.c) do (SET cfilenames=!cfilenames! %%f)

ECHO "Files:" %cfilenames%

SET target=playground
SET cflags=-g
SET incflags=-I%projpath%Playground\src -I%projpath%Engine\src
SET lnkflags=-L%projpath%bin -lvkwin.lib
SET defines=-D_DEBUG -DVKW_IMPORT

ECHO "building %target%%..."
clang %cfilenames% %cflags% -o %projpath%bin/%target%.exe %defines% %incflags% %lnkflags%
