cmake_minimum_required(VERSION 2.6)

project(FlappyClone)

set(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0015 NEW) #Convert Relative paths to new paths

#set Defines
add_definitions(-DSFML_STATIC)

#Include Directories
include_directories(include)

#Library Directories
link_directories(dependencies/SFML)

#add libraries
set(LINK_LIBS 
	sfml-graphics-s
	sfml-window-s
	sfml-system-s
	)

#Add src files
file(GLOB SOURCES "src/*.cpp")
set(SOURCES ${SOURCES} main.cpp)

#create exe
add_executable(FlappyClone ${SOURCES})


	

