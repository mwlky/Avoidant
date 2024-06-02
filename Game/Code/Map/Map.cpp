#include "Map.h"

namespace Avoidant {

    void Map::Init() {
        m_TilesTexture = Engine::SpriteLoader::LoadTexture(
                "../../Assets/Map/basic.png");

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

                int onSheetX = m_Vectors[y][x].x;
                int onSheetY = m_Vectors[y][x].y;

                int inSheetTileSize = m_Settings.TileSize;
                int InGameTileSize = m_Settings.InGameTileSize;

                SDL_Rect source{onSheetX * inSheetTileSize, onSheetY * inSheetTileSize, inSheetTileSize, inSheetTileSize};
                SDL_Rect destination = {x * InGameTileSize, y * InGameTileSize, InGameTileSize, InGameTileSize};

                Tile tile(source, destination, m_TilesTexture);
                m_MapTiles.push_back(tile);
            }
        }
    }

    void Map::DrawTiles() {
        for (Tile &tile: m_MapTiles)
            tile.Draw();
    }
}


