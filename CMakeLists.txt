cmake_minimum_required(VERSION 3.10)
project(Phantom)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(SFML_STATIC_LIBRARIES TRUE)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Phantom)

find_package(SFML REQUIRED COMPONENTS audio graphics window system)

include_directories(Phantom Phantom/Engine ${SFML_DIR}/../../include)

add_executable(Phantom
        Phantom/Engine.cpp
		Phantom/Engine.h
		Phantom/Game.cpp
		Phantom/Game.h
		Phantom/main.cpp
		Phantom/Player.cpp
		Phantom/Player.h
		Phantom/Resources.cpp
		Phantom/Resources.h
		Phantom/Script.cpp
		Phantom/Script.h
		Phantom/Engine/Console.cpp
		Phantom/Engine/Console.h)
		
target_link_libraries(Phantom sfml-graphics sfml-audio sfml-system sfml-network sfml-window)