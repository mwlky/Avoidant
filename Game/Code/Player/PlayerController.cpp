#include "PlayerController.h"

namespace Avoidant {
    PlayerController::PlayerController() {
        LOG("Hello");
    }

    PlayerController::~PlayerController() {
        SDL_DestroyTexture(m_PlayerTexture);
    }

    void PlayerController::Init() {
        m_PlayerTexture = Engine::SpriteLoader::LoadTexture(m_Data.SpritePath);

        m_PlayerTextureRect.x = m_PlayerTextureRect.y = 0;
        m_PlayerTextureRect.w = 50;
        m_PlayerTextureRect.h = 37;
    }

    void PlayerController::Tick() {
    }

    void PlayerController::Render() {

        SDL_RenderCopy(Engine::Window::Renderer,m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

} // Avoidant