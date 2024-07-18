#include <Code/Utilities/Macros.h>
#include "Window.h"

SDL_Renderer *Engine::Window::Renderer = nullptr;

namespace Engine{
    Window::Window(const char *title, int xPos, int yPos, int width, int height) {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
            std::cerr << "[SDL Initialize Error] " << SDL_GetError() << std::endl;

        if(IMG_Init(IMG_INIT_PNG) == 0)
            std::cerr << "[SDL_Image Initialize Error] " << SDL_GetError() << std::endl;

        if(TTF_Init() == -1)
            std::cerr << "[SDL_TTF Initialize Error] " << SDL_GetError() << std::endl;

        m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, SDL_WINDOW_SHOWN);
        if (m_Window) {
            m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
            m_Surface = SDL_GetWindowSurface(m_Window);
            Renderer = m_Renderer;

            if(m_Renderer == nullptr)
            {
                std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
                return;
            }


            SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
        }
    }

    Window::~Window() {
        SDL_DestroyWindowSurface(m_Window);
        SDL_DestroyWindow(m_Window);
        SDL_DestroyRenderer(m_Renderer);
    }
}

