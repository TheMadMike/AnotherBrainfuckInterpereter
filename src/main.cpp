/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#include <iostream>
#include "Interpreter.hpp"
#include "CodeLoader.hpp"

template<class T, size_t N>
constexpr size_t size(T (&)[N]) { return N; }

int main(int argc, char* argv[]){

  if(argc < 2) {
    std::cerr << "Usage: abi <file> \n";
    return 1;
  }

  abi::Interpreter interpreter;
  abi::CodeLoader loader;

  auto code = loader.loadFromFile(std::string(argv[1]));

  interpreter.run(code, loader.getCodeSize());

  std::cout<<"\n";

  return 0;
}
