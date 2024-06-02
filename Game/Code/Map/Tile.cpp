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

    bool Tile::IsColliding(Engine::Vector2 playerPosition) {
        PlayerData playerData;

        float playerLeft = playerPosition.x;
        float playerRight = playerPosition.x + playerData.xGameSize;
        float playerTop = playerPosition.y;
        float playerBottom = playerPosition.y + playerData.yGameSize;

        float tileLeft = m_Position.x;
        float tileRight = m_Position.x + m_Destination.w;
        float tileTop = m_Position.y;
        float tileBottom = m_Position.y + m_Destination.h;

        return playerRight > tileLeft && playerLeft < tileRight &&
               playerBottom > tileTop && playerTop < tileBottom;
    }

}