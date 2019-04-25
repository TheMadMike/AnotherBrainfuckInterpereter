/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#include "Interpreter.hpp"
#include <stdexcept>
#include <string>

#include <cstdio>

#include "Opcodes.hpp"

namespace abi {

  Interpreter::Interpreter(){
    memoryPointer = &memory[0];

    operations[Opcode::INC_MEM_PTR] = [](Interpreter& interpreter){
      ++interpreter.memoryPointer;
    };

    operations[Opcode::DEC_MEM_PTR] = [](Interpreter& interpreter){
      --interpreter.memoryPointer;
    };

    operations[Opcode::INC_BYTE] = [](Interpreter& interpreter){
      ++(*interpreter.memoryPointer);
    };

    operations[Opcode::DEC_BYTE] = [](Interpreter& interpreter){
      --(*interpreter.memoryPointer);
    };

    operations[Opcode::BYTE_OUT] = [](Interpreter& interpreter){
      std::putchar( static_cast<char>(*interpreter.memoryPointer) );
    };

    operations[Opcode::BYTE_IN] = [](Interpreter& interpreter){
      (*interpreter.memoryPointer) = static_cast<byte_t>(std::getchar());
    };

    operations[Opcode::START_LOOP] = [](Interpreter& interpreter){
      if(*interpreter.memoryPointer != 0) {
        interpreter.returnStack.push(interpreter.instructionPointer);
      } else {
        while(*interpreter.instructionPointer != Opcode::END_LOOP) {
          ++interpreter.instructionPointer;
        }
      }
    };

    operations[Opcode::END_LOOP] = [&](Interpreter& interpreter){
      if(*interpreter.memoryPointer == 0) {
        interpreter.returnStack.pop();
      } else {
        interpreter.instructionPointer = interpreter.returnStack.top();
      }
    };

  }

  void Interpreter::run(byte_t* code, size_t size){
    instructionPointer = &code[0];

    while(instructionPointer != &code[size]) {
      if(*instructionPointer >= Opcode::COUNT)
        throw std::runtime_error("Invalid opcode: "+std::to_string(*instructionPointer));

      operations[*instructionPointer](*this);

      ++instructionPointer;
    }

  }

}
