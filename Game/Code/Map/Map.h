#pragma once

#include <vector>
#include <iostream>
#include <box2d/box2d.h>

#include <Code/Utilities/SpriteLoader.h>
#include <Code/Math/Vector2.h>

#include "Tile.h"
#include "TileData.h"
#include "../DebugDraw.h"
#include "../Player/Player.h"

namespace Avoidant {

    class Map : public b2ContactListener {

    public:
        Map() = default;
        ~Map() override;

        void Init();
        void Draw();
        void Tick(double deltaTime);

    private:
        void DrawTiles();
        void InitMapTiles();
        void CreatePlayer();
        void InitBackground();

        void DrawBackground() const;

        void EndContact(b2Contact *contact) override;
        void BeginContact(b2Contact *contact) override;

    private:
        SDL_Texture *m_BackgroundTexture = nullptr;
        SDL_Texture *m_TilesTexture = nullptr;

        std::vector<Tile> m_TilesToDraw{};

        b2World* m_World = nullptr;
        Player* m_Player = nullptr;
        DebugDraw* m_DebugDraw = nullptr;

//      Vector coordinates corresponds to coordinates on sheet
        TileData m_Tiles [9][16] {

                {{0,0} ,{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},},
                {{0,0} ,{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},{9,11},{10,11},{11,11},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},},
                {{0,12} ,{1,12}, {2,12},{0,0},{0,0},{0,0},{0,0},{9,12},{10,12},{11,12},{0,0},{0,0},{0,0},{0,0},{4,13},{3,12},},
                {{10,1, true} ,{11,1, true}, {12,1, true},{0,0},{0,0},{0,0},{0,0},{9,13},{10,13},{11,13},{0,0},{0,0},{10,1, true},{11,1, true},{11,1, true},{12,1, true},},
                {{0,0} ,{0,0}, {0,0},{0,0},{0,0},{0,0},{2,13},{3,13},{10,14},{11,14},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},},
                {{0,0} ,{0,0}, {0,0},{0,0},{10,3, true},{11,3, true},{12,3, true},{13,3, true},{14,3, true},{15,3, true},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},},
                {{0,0} ,{0,0}, {0,0},{0,0},{0,0},{11,4},{12,4},{13,4},{14,4},{0,0},{0,0},{17,1, true},{18,1, true},{18,1, true},{18,1, true},{18,1, true},},
                {{24,1, true} ,{24,1, true}, {25,1, true},{0,0},{0,0},{0,0},{0,0},{13,5},{0,0},{0,0},{0,0},{17,2, true},{18,2},{18,2},{20,2},{21,2},},
                {{23,2} ,{24,2}, {25,2},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{17,3},{18,3},{19,3},{20,3},{21,3},},
        };
    };
}


