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
        delete m_BulletsManager;
    }

#pragma region === Init ===

    void Map::Init() {
        Settings settings;
        m_IsInitialized = true;

        m_TilesTexture = Engine::SpriteLoader::LoadTexture(
                settings.TilesTexture);


        b2Vec2 gravity(settings.Gravity.x, settings.Gravity.y);
        m_World = new b2World(gravity);

        InitBackground();
        InitMapTiles();

        CreatePlayer();
        m_Player->Init();
        m_World->SetContactListener(this);

        m_BulletsManager = new BulletManager(m_World);
#if DEBUG
        m_DebugDraw = new DebugDraw();
        m_DebugDraw->SetFlags(b2Draw::e_shapeBit);
        m_World->SetDebugDraw(m_DebugDraw);
#endif
    }

    void Map::InitMapTiles() {
        Settings settings;

        for (int x = 0; x < 16; ++x) {
            for (int y = 0; y < 9; ++y) {

                TileData data = m_Tiles[y][x];
                int onSheetX = data.SheetX;
                int onSheetY = data.SheetY;

                int inSheetTileSize = settings.TileSize;
                int InGameTileSize = settings.InGameTileSize;

                SDL_Rect source{onSheetX * inSheetTileSize, onSheetY * inSheetTileSize, inSheetTileSize,
                                inSheetTileSize};
                SDL_Rect destination = {x * InGameTileSize, y * InGameTileSize, InGameTileSize, InGameTileSize};

                Tile tile(source, destination);
                m_TilesToDraw.push_back(tile);

                if (data.HasCollision) {
                    b2BodyDef tileBodyDef;
                    tileBodyDef.position.Set((x * InGameTileSize + (InGameTileSize * 0.5f)) * settings.ScalingFactor,
                                             (y * InGameTileSize + (InGameTileSize * 0.5f)) * settings.ScalingFactor);

                    b2Body *tileBody = m_World->CreateBody(&tileBodyDef);
                    b2PolygonShape tileBox;

                    tileBox.SetAsBox((InGameTileSize * 0.5) * settings.ScalingFactor,
                                     (InGameTileSize * 0.5f) * settings.ScalingFactor);
                    tileBody->CreateFixture(&tileBox, 0.0f);
                }
            }
        }
    }

    void Map::CreatePlayer() {
        Settings data;

        b2BodyDef bodyDef;
        bodyDef.fixedRotation = true;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(data.StartPosition.x, data.StartPosition.y);
        b2Body *playerBody = m_World->CreateBody(&bodyDef);

        b2PolygonShape playerDynamicBox;
        playerDynamicBox.SetAsBox(data.xSize * data.ScalingFactor * 0.5f, data.ySize * data.ScalingFactor);

        b2CircleShape playerCircleTop;
        playerCircleTop.m_radius = data.xSize * data.ScalingFactor * 0.5f;
        playerCircleTop.m_p.Set(0, data.ySize * data.ScalingFactor * 0.5f);

        b2CircleShape playerCircleBottom;
        playerCircleBottom.m_radius = data.xSize * data.ScalingFactor * 0.5f;
        playerCircleBottom.m_p.Set(0, -data.ySize * data.ScalingFactor * 0.5f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &playerDynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.0f;

        playerBody->CreateFixture(&fixtureDef);

        fixtureDef.shape = &playerCircleTop;
        playerBody->CreateFixture(&fixtureDef);

        fixtureDef.shape = &playerCircleBottom;
        playerBody->CreateFixture(&fixtureDef);

        b2PolygonShape footSensorBox;
        footSensorBox.SetAsBox(data.xSize * data.ScalingFactor * 0.5f, data.ySize * data.ScalingFactor * 0.1f,
                               b2Vec2(0, (-data.ySize + 80.f) * data.ScalingFactor), 0);

        b2FixtureDef sensorFixtureDef;
        sensorFixtureDef.shape = &footSensorBox;
        sensorFixtureDef.isSensor = true;

        playerBody->CreateFixture(&sensorFixtureDef);

        m_Player = new Player(playerBody->GetFixtureList());
    }

    void Map::InitBackground() {
        Settings settings;

        m_BackgroundTexture = Engine::SpriteLoader::LoadTexture(settings.BackgroundTexture);
    }

#pragma endregion

#pragma region === Draw ===

    void Map::DrawTiles() {
        for (Tile &tile: m_TilesToDraw)
            tile.Draw(m_TilesTexture);
    }

    void Map::Draw() {

        DrawBackground();
        DrawTiles();

        if (IsPlayerAlive()) {
            m_Player->Render();
            m_BulletsManager->Draw();
        }

#if DEBUG
        m_World->DebugDraw();
#endif
    }

    void Map::DrawBackground() const {
        Engine::SpriteLoader::Draw(m_BackgroundTexture);
    }

#pragma endregion

#pragma region === Tick ===

    void Map::Tick(double deltaTime) {

        m_Player->Tick(deltaTime);
        m_BulletsManager->Tick(deltaTime);
        m_World->Step(deltaTime, 6, 8);
        m_Score += deltaTime;
    }

#pragma endregion

#pragma region === Collision Detection ===

    void Map::BeginContact(b2Contact *contact) {
        m_Player->BeginContact(contact);
    }

    void Map::EndContact(b2Contact *contact) {
        m_Player->EndContact(contact);
    }

    bool Map::IsPlayerAlive() const {
        return m_Player->IsAlive();
    }

    bool Map::IsInitialized() const {
        return m_IsInitialized;
    }

    float Map::GetScore() const {
        return std::round(m_Score);
    }

#pragma endregion
}


