#include "Tile.h"

namespace Avoidant {
    Tile::Tile(SDL_Rect source, SDL_Rect destination) {

        m_Source = source;
        m_Destination = destination;
    }

    void Tile::Draw(SDL_Texture *tilesSheet) {
        Engine::SpriteLoader::Draw(tilesSheet, m_Source, m_Destination);
    }
}