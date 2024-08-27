#include <string>
#include <iostream>
#include "ROM.h"

#pragma once

class Cartridge {
    private:
        bool loaded;
    public:
        std::string game;
        std::string cartType;
        std::string licensee;
        uint banks;
        bool japan;
        Cartridge(std::ifstream& file, ROM* roms);
};