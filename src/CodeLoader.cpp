/*
"Another Brainfuck Interpreter by TheMadMike"
 Copyright (c) 2019 by Michał Gibas
*/

#include "CodeLoader.hpp"
#include "Opcodes.hpp"
#include <map>
#include <stdexcept>

namespace abi {

    byte_t* CodeLoader::loadFromFile(const std::string& fileName) {
        file.open(fileName);
        
        if(!file.is_open())
            throw std::ios_base::failure("Can't open file: "+fileName);

        byte_t* code = new byte_t[getFileSize()];

        size_t i = 0;
        while(!file.eof()){
            
            char buffer;
            file.get(buffer);

            code[i] = convertCharacterToOpcode(buffer);
            ++i;
        }

        return code;
    }

    size_t CodeLoader::getFileSize() {
        size_t size = 0;

        while(!file.eof())
        {
            char tmp;
            file.get(tmp);
            if(tmp != ' ') ++size;
        }

        file.clear();
        file.seekg(0, std::ios::beg);

        codeSize = size-1;
        return size-1;
    }

    byte_t CodeLoader::convertCharacterToOpcode(char x) {
        static const std::map<char, byte_t> opcodeTable { 
            {'>', Opcode::INC_MEM_PTR}, 
            {'<', Opcode::DEC_MEM_PTR},
            {'+', Opcode::INC_BYTE},
            {'-', Opcode::DEC_BYTE},
            {'.', Opcode::BYTE_OUT},
            {',', Opcode::BYTE_IN},
            {'[', Opcode::START_LOOP},
            {']', Opcode::END_LOOP},
            {'#', Opcode::DUMP_MEM} 
        };

        if(opcodeTable.find(x) == opcodeTable.end())
            throw std::runtime_error("Operation not found in opcode table!");

        return opcodeTable.at(x);
    }

}