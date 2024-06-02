#include "Tile.h"

namespace Avoidant {


    Tile::Tile(SDL_Rect source, SDL_Rect destination, SDL_Texture* texture) {

        m_Position = Engine::Vector2(destination.x, destination.y);
        m_Texture = texture;

        m_Source = source;
        m_Destination = destination;
    }

    Tile::~Tile() {
//        SDL_DestroyTexture(m_Texture);
    }

    void Tile::Draw() {
        Engine::SpriteLoader::Draw(m_Texture, m_Source, m_Destination);
    }
}