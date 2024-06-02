#include "Map.h"

namespace Avoidant {

    void Map::InitBackground() {

       m_BackgroundTexture = Engine::SpriteLoader::LoadTexture("../../Assets/Map/windrise-background-cut.png");
    }


    Map::~Map() {
        SDL_DestroyTexture(m_BackgroundTexture);
    }

    void Map::Draw() {
        Engine::SpriteLoader::Draw(m_BackgroundTexture);
    }
}


