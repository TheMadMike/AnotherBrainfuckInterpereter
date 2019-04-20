/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#include "Interpreter.hpp"
#include <stdexcept>
#include <string>

#include "Opcodes.hpp"

namespace abi {

  Interpreter::Interpreter(){
    memoryPointer = &memory[0];
  }

  void Interpreter::run(byte_t* code, size_t size){
    instructionPointer = &code[0];

    byte_t buffer = 0;
    while(instructionPointer != &code[size]) {

      buffer = ((*instructionPointer) & 0xF0)>>4;
      if(buffer >= Opcode::COUNT)
        throw std::runtime_error("Invalid opcode! Opcode number: "+std::to_string(buffer));

      

      buffer = (*instructionPointer) & 0x0F;
      if(buffer >= Opcode::COUNT)
        throw std::runtime_error("Invalid opcode! Opcode number: "+std::to_string(buffer));

      ++instructionPointer;
    }

  }

}
