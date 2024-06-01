#pragma once

#include <iostream>
#include "SDL_image.h"
#include "../Window/Window.h"

namespace Engine{
    class SpriteLoader {

    public:
        SpriteLoader() = default;

    public:
        static SDL_Texture* LoadTexture(const char* texturePath);

        static void Draw(SDL_Texture *texture, SDL_Rect destinationPosition);
        static void Draw(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect position);
    };
}


