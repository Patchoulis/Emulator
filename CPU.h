#include "ROM.h"
#include "Cartridge.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <vector>

#pragma once

#define MAXROMS 512

struct Registers {
    uint16_t AF;
    uint16_t BC;
    uint16_t DE;
    uint16_t HL;
    uint16_t SP;
    uint16_t PC;
};

struct Interrupts {
    bool IME;
    bool IME_scheduled;
};

class CPU {
    public:
        ROM* roms;
        Cartridge* cart;
        unsigned long delay;
        Registers regs;
        unsigned char* currentROM;
        Interrupts interrupts;
        CPU(uint freq);
        void LoadBootRom(const char* file);
        void LoadCart(const char* file);
        uint8_t* GetRegisterByteByToken(const std::string& token);
        void Execute();
        ~CPU();
};
