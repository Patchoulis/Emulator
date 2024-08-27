#include "ROM.h"

ROM::ROM() {
    this->memory = new unsigned char[ROMSIZE];
    std::memset(this->memory, 0, ROMSIZE);
}

void ROM::Load(std::ifstream& file) {
    file.read(reinterpret_cast<char*>(this->memory), ROMSIZE);
}

ROM::~ROM() {
    delete[] memory;
}