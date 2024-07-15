#include "Game.h"

namespace Avoidant {

    Game::Game() {
        Settings settings;
        m_Engine = new Engine::Engine;

        m_Engine->OpenWindow(settings.WindowName, settings.XPosition, settings.YPosition, settings.Width,
                             settings.Height);
        m_IsRunning = true;
    }

    Game::~Game() {
        delete m_Engine;
    }

    bool Game::IsRunning() const {
        return m_IsRunning;
    }

#pragma region === Game Loop ===

    void Game::Init() {
        m_Map.Init();
    }

    void Game::Tick(double deltaTime) {

        if (m_Map.IsPlayerAlive())
            m_Map.Tick(deltaTime);
    }

    void Game::Render() {

        if (SDL_RenderClear(Engine::Window::Renderer) != 0) {
            LOG_ERROR("[Renderer Error] ")
            LOG_ERROR(SDL_GetError());
            return;
        }

        m_Map.Draw();

        SDL_RenderPresent(Engine::Window::Renderer);
    }

    void Game::HandleEvents() {
        SDL_PollEvent(&m_Event);

        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

        switch (m_Event.type) {
            case SDL_QUIT:
                m_IsRunning = false;
        }
    }

#pragma endregion
}

