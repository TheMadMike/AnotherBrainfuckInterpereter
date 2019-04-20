/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#pragma once

#include <cstdint>
#include <cstddef>

namespace abi {

  using byte_t = uint8_t;

  class Interpreter
  {
  public:
    Interpreter();
    virtual ~Interpreter() {}

    void run(byte_t* code, size_t size);

  private:
    static const size_t MEMORY_SIZE = 30000;
    byte_t memory[MEMORY_SIZE];

    byte_t* memoryPointer;
    byte_t* instructionPointer { nullptr };
  };

}
