#include "Game.h"

namespace Application{

    Game::Game() {
        Configs::WindowSettings settings;
        m_Engine = new Engine::Engine;

        m_Engine->OpenWindow(settings.WindowName, settings.XPosition, settings.YPosition, settings.Width, settings.Height);
        m_IsRunning = true;
    }

    void Game::Init() {

    }

    bool Game::IsRunning() const {
        return m_IsRunning;
    }

    void Game::Tick() {

    }

    void Game::Render() {

    }

    void Game::HandleEvents() {
        SDL_PollEvent(&m_Event);

        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

        switch (m_Event.type)
        {
            case SDL_QUIT:
                m_IsRunning = false;
        }
    }

    Game::~Game() {
        delete m_Engine;
    }
}

