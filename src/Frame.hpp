#pragma once
#include <SDL2/SDL.h>

class Frame
{
    public:
        Frame();
        ~Frame();
        int exec();
    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
}; 