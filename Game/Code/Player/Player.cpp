#include "Player.h"

namespace Avoidant {
    Player::Player() {
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

        m_PlayerPosition += m_PlayerVelocity;

        m_DestRect.x = m_PlayerPosition.x;
        m_DestRect.y = m_PlayerPosition.y;
    }

    void Player::Render() {

        SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

    void Player::CheckInput() {

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);

        // TODO: Remove vertical movement
        if (keystates[SDL_SCANCODE_W]){

            m_PlayerVelocity.y = -1 * m_Data.PlayerSpeed;
        }

        else if (keystates[SDL_SCANCODE_S]){
            m_PlayerVelocity.x = 0;
            m_PlayerVelocity.y = 1 * m_Data.PlayerSpeed;
        }

        else if (keystates[SDL_SCANCODE_D]){
            m_PlayerVelocity.y = 0;
            m_PlayerVelocity.x = 1 * m_Data.PlayerSpeed;
        }


        else if (keystates[SDL_SCANCODE_A]){
            m_PlayerVelocity.y = 0;
            m_PlayerVelocity.x = -1 * m_Data.PlayerSpeed;
        }

        else
            m_PlayerVelocity = Vector2().Zero();
    }

    Vector2 Player::GetPlayerPosition() const {
        return m_PlayerPosition;
    }


} // Avoidant