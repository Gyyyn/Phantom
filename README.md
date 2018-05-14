# Phantom Engine
### 2D C++ game engine based around SFML

## Building

Building is done through CMake, this means it also works with CLion and Eclipse. Everything is already setup to work out of the box assuming you fulfill the following requirements:

* x64 operating system
* SFML 2.5.0
* CMake 3.11 or later

Build SFML as static and put it somewhere CMake can find and then you're ready to build.

## Folder Structure

1. ```/``` - You are here.
	1. ```/Phantom``` - Source code.
		2. ```/Media``` - Game assets.
		3. ```/Game``` - Scripting. *SEE TODO LIST.*
		
## Engine Specifications

### Code style.

The codings style follow the Linux kernel coding specs with the notable exception of CamelCase instead of under_score for variable names.

### Logical structure.

TODO...

## The Phantom Scripting Engine

Phantom uses it's own restrictive scripting language for game designing.

A full documentation of possible interactions with the Phantom engine can be found in ```PHANTOM_SCRIPT.MD```

## TODO List

0. Message bus for cross-function information
1. Screen change control and HUDs
2. Scripting for game events and maps
