#include "Map.h"

namespace Avoidant {

    Map::~Map() {
        SDL_DestroyTexture(m_BackgroundTexture);
        SDL_DestroyTexture(m_TilesTexture);

        delete m_World;
#if DEBUG
        delete m_DebugDraw;
#endif
        delete m_Player;
    }

    void Map::Init() {
        m_TilesTexture = Engine::SpriteLoader::LoadTexture(
                "../../Assets/Map/basic.png");

        b2Vec2 gravity(m_Settings.Gravity.x, m_Settings.Gravity.y);
        m_World = new b2World(gravity);

        InitBackground();
        InitMapTiles();

        CreatePlayer();
        m_Player->Init();

#if DEBUG
        m_DebugDraw = new DebugDraw();
        m_DebugDraw->SetFlags(b2Draw::e_shapeBit);
        m_World->SetDebugDraw(m_DebugDraw);
#endif
    }

    void Map::CreatePlayer() {
        Engine::Vector2 pos;
        PlayerData data;

        b2BodyDef bodyDef;
        bodyDef.fixedRotation = true;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(pos.x, pos.y);
        b2Body* playerBody = m_World->CreateBody(&bodyDef);

        b2PolygonShape playerDynamicBox;
        playerDynamicBox.SetAsBox(data.xSize / 1.7, data.ySize);

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

    void Map::Draw() {
        DrawBackground();
        DrawTiles();
        m_Player->Render();
#if DEBUG
        m_World->DebugDraw();
#endif
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
                    b2BodyDef tileBodyDef;
                    tileBodyDef.position.Set(x * InGameTileSize + (InGameTileSize * 0.5), y * InGameTileSize + (InGameTileSize * 0.5));

                    b2Body *tileBody = m_World->CreateBody(&tileBodyDef);
                    b2PolygonShape tileBox;

//                    b2FixtureDef fixtureDef;
//                    fixtureDef.shape = &tileBox;
//                    fixtureDef.restitution = 0.0f;

                    tileBox.SetAsBox(InGameTileSize / 2, InGameTileSize / 2);
                    tileBody->CreateFixture(&tileBox, 0.0f);
                }
            }
        }
    }

    void Map::DrawTiles() {
        for (Tile &tile: m_TilesToDraw)
            tile.Draw(m_TilesTexture);
    }

    void Map::Tick(double deltaTime) {
        m_World->Step(deltaTime, 8, 10);

        m_Player->Tick();
    }

}


