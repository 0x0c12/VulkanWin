# Hi, welcome to VulkanWin

## Lack of proper documentation
As of current, VulkanWin lacks proper documentation and proper scaffolding.
This is just me following Travis Vroman's Kohi game engine series making minor adjustments as I go.
It's by no means a proper game engine, nor do I plan to make it one.
During the time of writing this, the project's visibility status is set to private.

## Prerequisites
As the title says, "VulkanWin", it is expected that you are using **Windows**.
The compiler being used in build scripts is **clang** but you can choose to use gcc.
However, I'm using the **Visual Studio** backend for clang so it's recommended you install that.
Also, if it isn't obvious, please install the **Vulkan SDK** from khronos' official website

### Clang Install
```sh
choco install llvm
```
P.S. Install visual studio from microsoft's official website if you haven't already

## Building!
The build system(if you would even call it that) is not at all robust and simply uses a batchfile system.
The only thing you have to alter is the absolute path for the variable "projpath" present in the upper lines of the build batchfiles.
The build directories are located in the folder:

```sh
VulkanWin\build\
```

The line to edit:
```bat
SET projpath=path\to\root\directory
```

## Pseudo-documentation so that I don't go insane
During this commit, the only features present are build-scripts for the project and defines.
Ofcourse, an entry-point is setup too.
