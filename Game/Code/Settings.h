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
        const int RunSpritesAmount = 6;
        const int RunAnimationDelay = 120;
        const int RunAnimXPosOnSheet = xSize;
        const int RunAnimYPosOnSheet = ySize;

        const int IdleSpritesAmount = 3;
        const int IdleAnimationDelay = 350;
        const int IdleAnimationYPosOnSheet = 0;
        const int IdleAnimationXPosOnSheet = xSize;

        const int JumpSpritesAmount = 3;
        const int JumpAnimationDelay = 200;
        const int JumpAnimXPosOnSheet = xSize * 2;
        const int JumpAnimYPosOnSheet = ySize * 2;

        const int FallSpritesAmount = 2;
        const int FallAnimationDelay = 100;
        const int FallAnimXPosOnSheet = xSize;
        const int FallAnimYPosOnSheet = ySize * 3;

        // ====================== Map Settings =======================================
        const int TileSize = 32;
        const int InGameTileSize = 80;

        Engine::Vector2 Gravity {0.f, 9.81f};

        // ======================= Physics Settings ======================================
        const float ScalingFactor = 0.01f;

        // ======================= Bullets Settings =======================================
        const char* BulletSpritePath = "../../Assets/Bullet/bullet.png";

        const float MaxBulletHeight = 3;
        const float CooldownBetweenBullets = 3.f;
        const float MinTimeToSpawnBullet = 1.f;
        const float MaxTimeToSpawnBullet = 2.f;

        const int MaxBullets = 10;
        const int LeftSpawnPosition = 1;
        const int RightSpawnPosition = Width * ScalingFactor;

        const int BulletSpriteSize = 32;
        const int InGameBulletSize = 92;

        const int MinBulletSpeed = 5.f;
        const int MaxBulletSpeed = 10.f;

        const float MaxBulletLifeTime = 3.f;

        // ======================= Hearts Settings =======================================
        const char* HeartsSpritePath = "../../Assets/Player/hearts.png";

        const int HearthSpriteSize = 16;
        const int HearthInGameSize = 64;
        const int HearthSpacing = HearthInGameSize * 0.9f;

        // ======================= MainMenu=======================================
        const char* StartButtonPath = "../../Assets/UI/StartButton.png";

        const int ButtonInGameX = Width * 0.4f + 50;
        const int ButtonInGameY = Height * 0.5f + 100;
        const int ButtonInGameWidth = 128;
        const int ButtonInGameHeight = 128;

        const int ButtonWidth = 56;
        const int ButtonHeight = 56;

        const int TitleSize = 200;
        const char* MainMenuFontPath = "../../Assets/UI/PixelFlag.ttf";

        const int TitleXPosition = Width * 0.5f - 300;
        const int TitleYPosition = Height * 0.5f - 200;

        const char* BackgroundPath = "../../Assets/UI/MenuBackground.png";
        const char* CreditsFontPath = "../../Assets/UI/Pixels.ttf";

        const int CreditsSize = 80;
        const int CreditsXPosition = Width * 0.685f;
        const int CreditsYPosition = Height * 0.9;

        const int GameOverTextSize = 200;
        const int GameOverTextXPosition = Width * 0.5f - 250;
        const int GameOverTextYPosition =  Height * 0.1f;
        const int GameOverTextWidth = 502;
        const int GameOverTextHeight = 132;

        const int ScoreDestinationX = Width * 0.5f - 160;
        const int ScoreDestinationY = Height * 0.7f;
        const int ScoreDestinationWidth = 311;
        const int ScoreDestinationHeight = 110;
    };
}
