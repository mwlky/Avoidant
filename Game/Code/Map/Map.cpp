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

                TileData data = m_Tiles[y][x];
                int onSheetX = data.SheetX;
                int onSheetY = data.SheetY;

                int inSheetTileSize = m_Settings.TileSize;
                int InGameTileSize = m_Settings.InGameTileSize;

                SDL_Rect source{onSheetX * inSheetTileSize, onSheetY * inSheetTileSize, inSheetTileSize, inSheetTileSize};
                SDL_Rect destination = {x * InGameTileSize, y * InGameTileSize, InGameTileSize, InGameTileSize};

                Tile tile(source, destination);
                m_TilesToDraw.push_back(tile);

                if(data.HasCollision)
                    m_CollisionalTiles.push_back(tile);
            }
        }
    }

    void Map::DrawTiles() {
        for (Tile &tile: m_TilesToDraw)
            tile.Draw(m_TilesTexture);
    }

    bool Map::IsColliding(Engine::Vector2 playerPosition) const{

        for (const Tile& tile : m_CollisionalTiles) {
            if(tile.IsColliding(playerPosition)){
                return true;
            }
        }

        return false;
    }

}


