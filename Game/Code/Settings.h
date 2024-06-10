#pragma once

namespace Avoidant {

    struct Settings {
        // ================== Window Settings =====================================

        int Width = 1280;
        int Height = 720;

        int XPosition = 2560;
        int YPosition = 300;

        const char* WindowName = "Avoidant";

        // ================ Player settings= ====================================
        const char *SpritePath = "../../Assets/Player/adventurer-Sheet.png";
        const Engine::Vector2 StartPosition {5.5f,3.4f};

        // Sprite size on sheet
        const int xSize = 50;
        const int ySize = 37;

        // In game size
        const int xGameSize = xSize * 3;
        const int yGameSize = ySize * 3;

        const int PlayerSpeed = 250;
        const float JumpSpeed = 6.f;

        // ====================== Map Settings =======================================
        const int InGameTileSize = 80;
        const int TileSize = 32;

        Engine::Vector2 Gravity {0.f, 9.81f};

        // ======================= Physics Settings ======================================
        const float ScalingFactor = 0.01f;
    };
}
