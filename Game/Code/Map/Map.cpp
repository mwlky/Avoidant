#include "Map.h"

namespace Avoidant {

    void Map::Init() {
        m_TilesTexture = Engine::SpriteLoader::LoadTexture(
                "../../Assets/Map/basic.png");

        b2Vec2 gravity(m_Settings.Gravity.x, m_Settings.Gravity.y);

        m_World = new b2World(gravity);

        InitBackground();
        InitMapTiles();

        CreatePlayer();
        m_Player->Init();
    }

    void Map::CreatePlayer() {
        Engine::Vector2 pos;

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(pos.x, pos.y);
        b2Body* playerBody = m_World->CreateBody(&bodyDef);

        PlayerData data;

        b2PolygonShape playerDynamicBox;
        playerDynamicBox.SetAsBox(data.xGameSize / 2, data.yGameSize / 2);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &playerDynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;

        b2Fixture* playerFixture = playerBody->CreateFixture(&fixtureDef);
        m_Player = new Player(playerFixture);
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
        m_Player->Render();
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

                SDL_Rect source{onSheetX * inSheetTileSize, onSheetY * inSheetTileSize, inSheetTileSize,
                                inSheetTileSize};
                SDL_Rect destination = {x * InGameTileSize, y * InGameTileSize, InGameTileSize, InGameTileSize};

                Tile tile(source, destination);
                m_TilesToDraw.push_back(tile);

                if (data.HasCollision) {
                    m_CollisionalTiles.push_back(tile);

                    b2BodyDef tileBodyDef;
                    tileBodyDef.position.Set(x * InGameTileSize, y * InGameTileSize);

                    b2Body *tileBody = m_World->CreateBody(&tileBodyDef);
                    b2PolygonShape tileBox;
                    tileBox.SetAsBox(InGameTileSize / 2, InGameTileSize / 2);
                    tileBody->CreateFixture(&tileBox, 0);
                }


            }
        }
    }

    void Map::DrawTiles() {
        for (Tile &tile: m_TilesToDraw)
            tile.Draw(m_TilesTexture);
    }

    bool Map::IsColliding(Engine::Vector2 playerPosition) const {

        for (const Tile &tile: m_CollisionalTiles) {
            if (tile.IsColliding(playerPosition)) {
                return true;
            }
        }

        return false;
    }

    void Map::Tick() {
        m_World->Step(1.0f / 60.0f, 1, 1);

        m_Player->Tick();
    }

}

