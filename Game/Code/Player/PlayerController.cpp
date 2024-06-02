#include "PlayerController.h"

namespace Avoidant {
    PlayerController::PlayerController() {
    }

    PlayerController::~PlayerController() {
        SDL_DestroyTexture(m_PlayerTexture);
    }

    void PlayerController::Init() {
        m_PlayerTexture = Engine::SpriteLoader::LoadTexture(m_Data.SpritePath);
    }

    void PlayerController::Tick() {
        CheckInput();
        UpdatePlayerPosition();

    }

    void PlayerController::UpdatePlayerPosition() {

        m_PlayerPosition += m_PlayerVelocity;

        m_DestRect.x = m_PlayerPosition.x;
        m_DestRect.y = m_PlayerPosition.y;
    }

    void PlayerController::Render() {

        SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

    void PlayerController::CheckInput() {

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


} // Avoidant