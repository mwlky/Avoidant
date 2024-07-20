#pragma once

#include "SDL_image.h"
#include "../Window/Window.h"
#include <Code/Utilities/Macros.h>

namespace Engine{
    class SpriteLoader {

    public:
        SpriteLoader() = default;

    public:
        static SDL_Texture* LoadTexture(const char* texturePath);
        static SDL_Texture* LoadText(const char* text, TTF_Font * font, SDL_Color textColor);

        static void Draw(SDL_Texture* texture);
        static void Draw(SDL_Texture *texture, SDL_Rect destinationPosition);
        static void Draw(SDL_Texture* texture, SDL_Rect& sourceRect, SDL_Rect& position);
    };
}


