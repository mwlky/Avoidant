#pragma once

#include "../Settings.h"
#include <box2d/box2d.h>

#include <Code/Engine.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/Macros.h>
#include <Code/Utilities/SpriteLoader.h>

namespace Avoidant {

    using Engine::Vector2;

    class Player {

    public:
        explicit Player(b2Fixture* body);
        ~Player();

        void Init();
        void Tick();
        void Render();

        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);

    private:

        void Jump();
        void CheckInput();
        void PlayRunAnimation();
        void PlayIdleAnimation();
        void UpdatePlayerPosition();
        void PlayMovementAnimation(float movementDirection);

        void CheckPlayerJumpAnimation();
        void MovePlayer(float desiredX);
        void PlayAnimation(int xPosOnSheet, int yPosOnSheet, int spritesAmount, int delay, bool loop = true, bool noDelay = true);

    private:
        b2Fixture* m_Body = nullptr;
        SDL_Texture* m_PlayerTexture = nullptr;

    private:
        bool m_IsGrounded = false;
        bool m_IsFlipped = false;

        int m_CurrentFrame {};
        uint32 m_LastFrame {};

        SDL_Rect m_DestRect;    // In game position
        SDL_Rect m_SourceRect;  // Position in sheet file
    };

} // Avoidant
