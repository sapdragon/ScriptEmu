
![Image1](https://media.discordapp.net/attachments/1009521316694605845/1066370554875088966/photo_2023-01-21_16-55-23.jpg)

Utility demonstrating a way to combat Lua script obfuscation. The utility creates a full compliance of the environment with the original application API, then in the local environment emulates the entire script, after which you can see all the called functions in the main and additional callbacks.

## Where will it come in handy?
- Analyzing an obfuscated Lua script
- Running scripts in the API access environment
- Finding and correcting errors

## Building
You need the latest version of Visual Studio with the Clang compiler installed (LLVM 15), and the C++ version 20 Standard.

Run the build in Release x86 mode

## Usage
To start tracing the script, simply drop the .lua script into the application window

## Credits

[Sol2](https://github.com/ThePhD/sol2) 
[LuaJIT](https://github.com/LuaJIT/LuaJIT)
