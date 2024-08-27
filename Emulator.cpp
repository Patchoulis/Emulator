#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "CPU.h"

#define FREQUENCY 8388608

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }
    CPU cpu(FREQUENCY);
    cpu.LoadBootRom("BOOT.gbc");
    cpu.LoadCart("Pokemon.gbc");
    

    return 0;
}
