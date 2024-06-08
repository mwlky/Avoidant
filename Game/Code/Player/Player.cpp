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

        m_DestRect.x = m_Body->GetBody()->GetPosition().x - m_Data.ySize * 2;
        m_DestRect.y = m_Body->GetBody()->GetPosition().y - m_Data.xSize - 20;
    }

    void Player::Render() {

        SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

    void Player::CheckInput() {

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        b2Vec2 currentVelocity = m_Body->GetBody()->GetLinearVelocity();
        float desiredX = 0;

        if (keystates[SDL_SCANCODE_D])
            desiredX = m_Data.PlayerSpeed;
        else if (keystates[SDL_SCANCODE_A])
            desiredX = -m_Data.PlayerSpeed;

        if (keystates[SDL_SCANCODE_SPACE]) {
            float impulse = m_Body->GetBody()->GetMass() * 100000;
            m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(0, impulse), false);
        }


        float velChangeX = desiredX - currentVelocity.x;
        float impulseX = m_Body->GetBody()->GetMass() * velChangeX;

        m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(impulseX, 0), true);
    }
} // Avoidant