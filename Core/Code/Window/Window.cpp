#include "Window.h"

namespace Engine{
    Window::Window(const char *title, int xPos, int yPos, int width, int height) {
        SDL_Init(SDL_INIT_EVERYTHING);

        m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, SDL_WINDOW_SHOWN);
        if (m_Window) {
            m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            m_Surface = SDL_GetWindowSurface(m_Window);

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

