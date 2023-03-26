#include "Frame.hpp"
#include <stdexcept>
#include <iostream>

Frame::Frame()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("SDLInit(SDL_INIT_VIDEO)");
    if(SDL_CreateWindowAndRenderer(720, 720, 0, &window, &renderer) != 0)
        throw std::runtime_error(SDL_GetError());
    SDL_SetWindowPosition(window, 65, 126);
}

Frame::~Frame()
{
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
}

int Frame::exec()
{
    SDL_Event e;
    for(;;)
    {
        while(SDL_WaitEvent(&e))
        {
            switch (e.type)
            {
            case SDL_MOUSEBUTTONUP:
                std::cout<<e.button.x<< " "<<e.button.y<<std::endl;
                break;
            
            case SDL_QUIT:
                return 0;

            default:
                break;
            }
        }
    }
    return 0;
}