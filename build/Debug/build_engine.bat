REM Build script for VulkanWin
@ECHO OFF
SetLocal EnableDelayedExpansion

REM You can change project path to the location where repository was cloned
SET projpath=C:\dev\VulkanWin\

REM Get a list of all .c files
SET cfilenames=
FOR /R "%projpath%Engine\src" %%f in (*.c) do ( SET cfilenames=!cfilenames! %%f )

echo "Files:" %cfilenames%

SET target=vkwin
SET cflags=-g -shared -Wvarargs -Wall -Werror
SET incflags=-I%projpath%Engine/src -I%VULKAN_SDK%/Include
SET lnkflags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
SET defines=-D_DEBUG -DVKW_EXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building %target%%..."
rmdir /S /Q %projpath%bin
mkdir %projpath%bin
clang %cfilenames% %cflags% -o %projpath%bin/%target%.dll %defines% %incflags% %lnkflags%
