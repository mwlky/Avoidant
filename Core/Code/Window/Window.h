#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

namespace Engine {

    class Window {
    public:
        Window(const char* title, int xPos, int yPos, int width, int height);
        ~Window();

        static SDL_Renderer* Renderer;

    private:

        SDL_Window* m_Window = nullptr;
        SDL_Surface* m_Surface = nullptr;
        SDL_Renderer* m_Renderer = nullptr;
    };
}



