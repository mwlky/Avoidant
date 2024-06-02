#include "Player.h"

namespace Avoidant {
    Player::Player(const Map &map) : m_Map(map) {

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

        Engine::Vector2 currentPosition = m_PlayerPosition;
        Engine::Vector2 newPosition = currentPosition + m_PlayerVelocity;

        if (m_Map.IsColliding(newPosition))
            return;

        m_PlayerPosition = newPosition;
        m_DestRect.x = m_PlayerPosition.x;
        m_DestRect.y = m_PlayerPosition.y;
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
            m_PlayerVelocity.y = 0;
            m_PlayerVelocity.x = 1 * m_Data.PlayerSpeed;
        } else if (keystates[SDL_SCANCODE_A]) {
            m_PlayerVelocity.y = 0;
            m_PlayerVelocity.x = -1 * m_Data.PlayerSpeed;
        } else
            m_PlayerVelocity = Vector2().Zero();
    }

    Vector2 Player::GetPlayerPosition() const {
        return m_PlayerPosition;
    }


} // Avoidant