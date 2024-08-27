#include <SDL2/SDL.h>

#pragma once

struct Color {
    uint8_t r,g,b;
};

class Viewport {
    private:
        uint maxY;
        uint maxX;
        uint scaleY;
        uint scaleX;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* screen;
        SDL_Texture* texture;
    public:
        Viewport(uint WindowX, uint WindowY,uint scaleX, uint scaleY, const char* Name);
        void ClearScreen();
        void Update();
        void drawTile(int x, int y, Color color);
        void setDisplay();
        void* lockAndGetPixels();
        void Quit();
};