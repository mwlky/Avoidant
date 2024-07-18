#pragma once

#include <Code/Math/Math.h>
#include <Code/Utilities/Application.h>

#include "SDL2/SDL.h"
#include "Code/Window/Window.h"
#include "Code/Utilities/SpriteLoader.h"

namespace Engine {

    class Engine {

    public:
        Engine() = default;
        ~Engine();

        void OpenWindow(const char *title, int x, int y, int width, int height);

        Window* GetWindow() const;

        SDL_Texture* LoadTexture(const char* path);

    private:
        Window *m_Window = nullptr;
    };

}
