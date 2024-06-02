#include "Map.h"

namespace Avoidant {

    void Map::Init() {
        m_TilesTexture = Engine::SpriteLoader::LoadTexture(
                "/home/mwlky/Documents/Code/Avoidant/Game/Assets/Map/basic.png");

        InitBackground();
        InitMapTiles();
    }

    void Map::InitBackground() {

        m_BackgroundTexture = Engine::SpriteLoader::LoadTexture("../../Assets/Map/windrise-background-cut.png");
    }


    Map::~Map() {
        SDL_DestroyTexture(m_BackgroundTexture);
        SDL_DestroyTexture(m_TilesTexture);
    }

    void Map::Draw() {
        DrawBackground();
        DrawTiles();
    }

    void Map::DrawBackground() const {
        Engine::SpriteLoader::Draw(m_BackgroundTexture);
    }

    void Map::InitMapTiles() {

        for (int x = 0; x < 16; ++x) {
            for (int y = 0; y < 9; ++y) {

                // And this doesn't work?
                int onSheetX = m_Vectors[y][x].x;
                int onSheetY = m_Vectors[y][x].y;

                SDL_Rect source{onSheetX * 32, onSheetY * 32, 32, 32};
                SDL_Rect destination = {x * 80, y * 80, 80, 80};

                Tile tile(source, destination, m_TilesTexture);
                m_MapTiles.push_back(tile);
//                LOG(SDL_GetError());
            }
        }
    }

    void Map::DrawTiles() {
        for (Tile &tile: m_MapTiles) {
            tile.Draw();
        }
    }
}


