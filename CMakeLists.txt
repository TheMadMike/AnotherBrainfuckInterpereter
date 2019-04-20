# "Another Brainfuck Interpreter by TheMadMike"
#  Copyright (c) 2019 by Michał Gibas

cmake_minimum_required(VERSION 3.5)

project(abi CXX)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
src/main.cpp
src/Interpreter.cpp
)

add_executable(abi ${SOURCES})
