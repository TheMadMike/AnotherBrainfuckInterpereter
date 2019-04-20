/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#include <iostream>
#include "Interpreter.hpp"

int main(int argc, char* argv[]){

  if(argc < 2) {
    std::cerr << "Usage: abi <file> \n";
    return 1;
  }

  abi::Interpreter interpreter;

  //TEST: should throw exception
  abi::byte_t code [4] = { 0x08, 0x00, 0x00, 0xff};

  interpreter.run(code, 4);

  return 0;
}
