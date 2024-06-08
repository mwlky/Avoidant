#include "Player.h"

namespace Avoidant {
    Player::Player(b2Fixture *body) {
        m_Body = body;
    }

    Player::~Player() {
        SDL_DestroyTexture(m_PlayerTexture);
    }

    void Player::Init() {
        m_PlayerTexture = Engine::SpriteLoader::LoadTexture(m_Data.SpritePath);
    }

    void Player::Tick() {
        CheckInput();
        UpdatePlayerPosition();
    }

    void Player::UpdatePlayerPosition() {
        Settings settings;

        float newPosX = m_Body->GetBody()->GetPosition().x / settings.ScalingFactor;
        float newPosY = m_Body->GetBody()->GetPosition().y / settings.ScalingFactor;

        m_DestRect.x = newPosX - m_Data.xGameSize * 0.5f;
        m_DestRect.y = newPosY - m_Data.yGameSize * 0.5f - 14;
    }

    void Player::Render() {

        SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

    void Player::CheckInput() {

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        b2Vec2 currentVelocity = m_Body->GetBody()->GetLinearVelocity();
        float desiredX = 0;

        Settings settings;

        if (keystates[SDL_SCANCODE_D])
            desiredX = m_Data.PlayerSpeed * settings.ScalingFactor;
        else if (keystates[SDL_SCANCODE_A])
            desiredX = -m_Data.PlayerSpeed * settings.ScalingFactor;
//
//        if (keystates[SDL_SCANCODE_SPACE]) {
//            float impulse = m_Body->GetBody()->GetMass() * 100000;
//            m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(0, impulse), false);
//        }


        float velChangeX = desiredX - currentVelocity.x;
        float impulseX = m_Body->GetBody()->GetMass() * velChangeX;

        m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(impulseX, 0), true);
    }
} // Avoidant