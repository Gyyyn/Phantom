# Phantom Engine
### 2D C++ game engine based around SFML

## Building

Building is based around Visual Studio for now, this is due to be replaced to a more universal build system later.

Just clone the project and open with VC Community 2017, the rest should take care of itself.

If when debugging it complains about not finding SFML DLLs copy the files in SFML/bin to the active debug folder.

## Requirements

SFML Version 2.4.2 is required to build. A build of the library is provided in the Libs folder since the official SFML website does not yet provide downloads for VC++ 2017.

Engine is x86 only for now, support for x64 is planned.

## Folder Structure

1. ```/``` - You are here.
	1. ```/Phantom``` - Source code.
		1. ```/Libs``` - Libraries (SFML).
		2. ```/Media``` - Game assets.
		3. ```/Game``` - Scripting. *SEE TODO LIST.*
		
## Engine Specifications

### Code style.

The codings style follow the Linux kernel coding specs with the notable exception of CamelCase instead of under_score for variable names.

### Logical structure.

## TODO List

0. Message bus for cross-function information
1. Screen change control and HUDs
2. Scripting for game events and maps
