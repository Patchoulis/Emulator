#include "Viewport.h"
#include <iostream>

Viewport::Viewport(uint WindowX, uint WindowY,uint scaleX, uint scaleY, const char* Name) : maxX(WindowX), maxY(WindowY), scaleX(scaleX), scaleY(scaleY) {
    SDL_Window* window = SDL_CreateWindow(Name,
                                      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      WindowX, WindowY,
                                      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    this->window = window;

    this->screen = SDL_CreateRGBSurface( 0, WindowX, WindowY, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    this->renderer = renderer;

    SDL_Texture* windowTexture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET, this->maxX, this->maxY);
    if (!windowTexture) {
        std::cerr << "Window Texture could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    this->texture = windowTexture;

    this->maxX = WindowX;
    this->maxY = WindowY;
}

void Viewport::drawTile(int x, int y, Color color) {
    SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, 0);
    SDL_RenderDrawPoint(this->renderer, x, y);
}

void* Viewport::lockAndGetPixels() {
    SDL_LockSurface(this->screen);
    return this->screen->pixels;
}

void Viewport::setDisplay() {
    SDL_UnlockSurface(this->screen);
    SDL_UpdateTexture(this->texture, NULL, this->screen->pixels, this->screen->pitch);
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
}

void Viewport::ClearScreen() {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

void Viewport::Update() {
    SDL_RenderPresent(this->renderer);
}

void Viewport::Quit() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}