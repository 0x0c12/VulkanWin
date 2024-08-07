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

# Pseudo-documentation so that I don't go insane
Second proper commit!

## Conventions
I decided to place this here in the readme since it's much easier on the eyes.
The conventions for VKWin are as follows:

### Within code
- **Functions**: FunctionName() - The functions are named in PascalCase.
- **MACROS**: MACRO - The macros are named in the ALL_CAPS version of snake_case.
- **variables**: var_name - The variables are all named in snake_case.
***note**: Hungarian notation will be used for variables in snake_case. eg: \*p_ptr_name would be a pointer*
- **structs**: structName - All structs/enums will be named in camelCase.

### Outside code
- **Folders**: FolderName - Similar to functions, folders too will be named in PascalCase
- **files**: file_name - Again, similar to variables, files(mostly source_files/header_files) will be named in snake_case

## Log utilities
The log utilities in the engine use macros to access logging.
The pattern is something like:
```c
VKW_LOGLEVEL("message string");
```

To use the logger in your project for now, link the engine project into your own and include the "core/logger.h" interface

```c
#include <Core/logger.h>
```

For further information, check the logger header. I know, it's not conveneint.

***note**: All utilities are subject to change*

## Assertion
This one took such a long time to make but it's finally done!
The pattern for using assertions:
```c
VKW_ASSERT_TYPE(const char* expression, const char* msg);
```
Don't be fooled by the interface. The expression is supposed to return a boolean.

Also, like before, to use the assertion utility, include it in your code. For now...

```c
#include <Core/asserts.h>
```

## Footer notes/TODOs
- Instead of having to use the `#include <core/module.h>`, make a single proper include.
- Separate interfaces from source-files
