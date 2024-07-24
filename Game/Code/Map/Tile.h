#pragma once

#include <SDL.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/SpriteLoader.h>

#include "../Settings.h"

namespace Avoidant {

    class Tile {

    public:
        Tile(SDL_Rect source, SDL_Rect destination);

        ~Tile() = default;

    public:
        void Draw(SDL_Texture* tilesSheet);

    private:
        SDL_Rect m_Source{};
        SDL_Rect m_Destination{};
    };

} // Avoidant
