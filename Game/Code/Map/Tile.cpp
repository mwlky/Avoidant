#include "Tile.h"

namespace Avoidant {


    Tile::Tile(SDL_Rect source, SDL_Rect destination) {

        m_Position = Engine::Vector2(destination.x, destination.y);

        m_Source = source;
        m_Destination = destination;
    }

    void Tile::Draw(SDL_Texture *tilesSheet) {
        Engine::SpriteLoader::Draw(tilesSheet, m_Source, m_Destination);
    }

    bool Tile::IsColliding(Engine::Vector2 playerPosition) const {
        PlayerData playerData;

//        int xBox = m_Position.x + m_Destination.h;
//        int yBox = m_Position.y + m_Destination.h;
//
//        // hard coded value are displacement value of sprite in the whole image. Player sprite is not exactly
//        // at the middle of the sprite
//        bool horizontal = playerPosition.x + playerData.xSize + 40 > m_Position.x && playerPosition.x + 40 < xBox;
//        bool vertical = playerPosition.y + playerData.yGameSize > m_Position.y && playerPosition.y + 15 < yBox;
//
//        return vertical & horizontal;
        return false;
    }
}