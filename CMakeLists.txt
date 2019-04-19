# "Another Brainfuck Interpreter by TheMadMike"
#  Copyright (c) 2019 by Michał Gibas

cmake_minimum_required(VERSION 3.5)

project(abi CXX)
set(CMAKE_CXX_STANDARD 14)

set(SOURCES
src/main.cpp
)

add_executable(abi ${SOURCES})
