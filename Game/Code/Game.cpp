#include "Game.h"

namespace Avoidant{

    Game::Game() {
        Configs::WindowSettings settings;
        m_Engine = new Engine::Engine;

        m_Engine->OpenWindow(settings.WindowName, settings.XPosition, settings.YPosition, settings.Width, settings.Height);
        m_IsRunning = true;
    }

    void Game::Init() {
        m_Map.Init();
        m_PlayerController.Init();
    }

    bool Game::IsRunning() const {
        return m_IsRunning;
    }

    void Game::Tick() {
        m_PlayerController.Tick();
    }

    void Game::Render() {

        if(SDL_RenderClear(Engine::Window::Renderer) != 0){
//            std::cerr << "[Renderer Error] " << SDL_GetError() << std::endl;
            LOG_ERROR("[Renderer Error] ")
            LOG_ERROR(SDL_GetError());
            return;
        }

        SDL_SetRenderDrawColor(Engine::Window::Renderer, 150, 150, 185, 255);
        m_Map.Draw();
        m_PlayerController.Render();

        SDL_RenderPresent(Engine::Window::Renderer);

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

