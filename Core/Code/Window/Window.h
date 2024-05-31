#include "SDL.h"
#include <iostream>

namespace Engine {

    class Window {
    public:
        Window(const char* title, int xPos, int yPos, int width, int height);
        ~Window();

        SDL_Renderer* m_Renderer = nullptr;

    private:

        SDL_Window* m_Window = nullptr;
        SDL_Surface* m_Surface = nullptr;
    };
}



