#pragma once

#include <Code/Math/Vector2.h>

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

        const int StartLives = 3;

        const float BulletCollisionDelay = 0.1f;

        // Sprite size on sheet
        const int xSize = 50;
        const int ySize = 37;

        // In game size
        const int xGameSize = xSize * 3;
        const int yGameSize = ySize * 3;

        const int PlayerSpeed = 250;
        const float JumpSpeed = 6.f;

        // Ticks time between switching sprites
        const int RunAnimationDelay = 120;
        const int RunAnimXPosOnSheet = xSize;
        const int RunAnimYPosOnSheet = ySize;
        const int RunSpritesAmount = 6;

        const int IdleAnimationDelay = 350;
        const int IdleAnimationXPosOnSheet = xSize;
        const int IdleAnimationYPosOnSheet = 0;
        const int IdleSpritesAmount = 3;

        const int JumpAnimationDelay = 200;
        const int JumpAnimXPosOnSheet = xSize * 2;
        const int JumpAnimYPosOnSheet = ySize * 2;
        const int JumpSpritesAmount = 3;

        const int FallAnimationDelay = 100;
        const int FallAnimXPosOnSheet = xSize;
        const int FallAnimYPosOnSheet = ySize * 3;
        const int FallSpritesAmount = 2;

        // ====================== Map Settings =======================================
        const int InGameTileSize = 80;
        const int TileSize = 32;

        Engine::Vector2 Gravity {0.f, 9.81f};

        // ======================= Physics Settings ======================================
        const float ScalingFactor = 0.01f;

        // ======================= Bullets Settings =======================================
        const char* BulletSpritePath = "../../Assets/Bullet/bullet.png";

        const float CooldownBetweenBullets = 2.f;

        const float MaxBulletHeight = 5;
        const int LeftSpawnPosition = 1;
        const int RightSpawnPosition = Width * ScalingFactor;

        const int BulletSpriteSize = 32;
        const int InGameBulletSize = 92;

        const float BulletSpeed = 5.f;
        const float MaxBulletLifeTime = 3.f;

        // ======================= Hearts Settings =======================================
        const char* HeartsSpritePath = "../../Assets/Player/hearts.png";

        const int HearthSpriteSize = 16;
        const int HearthInGameSize = 64;
        const int HearthSpacing = HearthInGameSize * 0.9f;

        // ======================= UI=======================================
        const char* StartButtonPath = "../../Assets/UI/StartButton.png";

        const int ButtonInGameX = Width * 0.4f + 50;
        const int ButtonInGameY = Height * 0.5f + 100;
        const int ButtonInGameWidth = 128;
        const int ButtonInGameHeight = 128;

        const int ButtonWidth = 56;
        const int ButtonHeight = 56;

        const int FontSize = 25;
        const char* MainMenuFontPath = "../../Assets/UI/Pixels.ttf";

        const int TitleXPosition = 0;
        const int TitleYPosition = 0;
        const int TitleWidth = 600;
        const int TitleHeight = 300;

        const char* BackgroundPath = "../../Assets/UI/MenuBackground.png";
    };
}
