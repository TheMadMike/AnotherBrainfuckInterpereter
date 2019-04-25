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

  //test
  abi::byte_t code [4] = {0, 0, 0, 0};

  interpreter.run(code, 4);

  return 0;
}
