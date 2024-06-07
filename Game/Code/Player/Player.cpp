#include "Player.h"

namespace Avoidant {
    Player::Player(){

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

        m_DestRect.x = m_Body->GetBody()->GetPosition().x;
        m_DestRect.y = m_Body->GetBody()->GetPosition().y;
    }

    void Player::Render() {

        SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

    void Player::CheckInput() {

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);

#if DEBUG
        if (keystates[SDL_SCANCODE_W]) {

            m_PlayerVelocity.y = -1 * m_Data.PlayerSpeed;
        } else if (keystates[SDL_SCANCODE_S]) {
            m_PlayerVelocity.y = 1 * m_Data.PlayerSpeed;
        } else
#endif
        if (keystates[SDL_SCANCODE_D]) {
//            m_PlayerVelocity.y = 0;
//            m_PlayerVelocity.x = 1 * m_Data.PlayerSpeed;
            m_Body->GetBody()->SetLinearVelocity(b2Vec2(1 * m_Data.PlayerSpeed, 0));

        } else if (keystates[SDL_SCANCODE_A]) {
            m_PlayerVelocity.y = 0;
            m_PlayerVelocity.x = -1 * m_Data.PlayerSpeed;
        } else
            m_PlayerVelocity = Vector2().Zero();
    }

    Vector2 Player::GetPlayerPosition() const {
        return m_PlayerPosition;
    }

    void Player::SetPlayerPosition(Vector2 a) {
        m_PlayerPosition = a;
    }

    Player::Player(b2Fixture *body) {
        m_Body = body;
    }


} // Avoidant