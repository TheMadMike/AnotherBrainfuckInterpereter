/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#pragma once

namespace abi {

  enum Opcode {
    INC_MEM_PTR = 0,
    DEC_MEM_PTR,
    INC_BYTE,
    DEC_BYTE,
    BYTE_OUT,
    BYTE_IN,
    START_LOOP,
    END_LOOP,
    DUMP_MEM,

    COUNT
  };

}
