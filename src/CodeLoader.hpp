/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#pragma once

#include "Types.hpp"
#include <fstream>

namespace abi {

    class CodeLoader 
    {
    public:
        byte_t* loadFromFile(const std::string& fileName);
        inline size_t getCodeSize() { return codeSize; }
    private:
        size_t getFileSize();
        byte_t convertCharacterToOpcode(char x);
        
        size_t codeSize;
        std::ifstream file;
    };

}