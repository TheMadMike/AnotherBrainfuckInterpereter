/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#pragma once

#include <stack>
#include <map>
#include <functional>
#include "Types.hpp"

namespace abi {

  class Interpreter
  {
    using Operations_t = std::map<byte_t, std::function<void(Interpreter& interpreter)>>;
  public:
    Interpreter();
    virtual ~Interpreter() {}

    void run(byte_t* code, size_t size);

    std::stack<byte_t*> returnStack;

    byte_t* memoryPointer;
    byte_t* instructionPointer { nullptr };
  private:

    static const size_t MEMORY_SIZE = 30000;
    byte_t memory[MEMORY_SIZE];

    Operations_t operations;

  };

}
