#pragma once

#include <Code/Engine.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/SpriteLoader.h>
#include <Code/Utilities/Macros.h>
#include <box2d/box2d.h>

#include "PlayerData.h"

namespace Avoidant {

    using Engine::Vector2;

    class Player {

    public:
        Player(b2Fixture* body);
        ~Player();

        void Init();
        void Tick();
        void Render();

    private:
        void CheckInput();
        void UpdatePlayerPosition();

    private:
        b2Fixture* m_Body = nullptr;
        SDL_Texture* m_PlayerTexture = nullptr;

        PlayerData m_Data;

        // Position in sheet file
        SDL_Rect m_SourceRect = {0,0, m_Data.xSize, m_Data.ySize};
        // In game position
        SDL_Rect m_DestRect = {0,0, m_Data.xSize * 3,m_Data.ySize * 3};


    };

} // Avoidant
