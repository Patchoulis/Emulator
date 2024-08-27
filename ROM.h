#include <fstream>
#include <cstring>

#pragma once

#define ROMSIZE 16384

class ROM {
    public:
        unsigned char* memory;
        ROM();
        void Load(std::ifstream& file);
        ~ROM();
};
