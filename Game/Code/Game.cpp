#include "Game.h"

namespace Avoidant {

    Game::Game() {
        Settings settings;
        m_Engine = new Engine::Engine;

        m_Engine->OpenWindow(settings.WindowName, settings.XPosition, settings.YPosition, settings.Width,
                             settings.Height);

        InitUI();

        m_IsRunning = true;
    }

    void Game::InitUI() {
        Settings settings;

        SDL_Rect source;
        source.x = 0;
        source.y = 0;
        source.w = settings.ButtonWidth;
        source.h = settings.ButtonHeight;

        SDL_Rect destination;
        destination.x = settings.ButtonInGameX;
        destination.y = settings.ButtonInGameY;
        destination.w = settings.ButtonInGameWidth;
        destination.h = settings.ButtonInGameHeight;

        m_StartButton = new StartButton(destination, source, settings.StartButtonPath);
    }

    Game::~Game() {
        delete m_Engine;
        delete m_StartButton;
    }

    bool Game::IsRunning() const {
        return m_IsRunning;
    }

#pragma region === Game Loop ===

    void Game::Init() {

    }

    void Game::Tick(double deltaTime) {

        if (!m_Map.IsInitialized())
            return;

        if (m_Map.IsPlayerAlive())
            m_Map.Tick(deltaTime);
    }

    void Game::Render() {

        if (SDL_RenderClear(Engine::Window::Renderer) != 0) {
            LOG_ERROR("[Renderer Error] ");
            LOG_ERROR(SDL_GetError());
            return;
        }

        if (m_Map.IsInitialized())
            m_Map.Draw();

        else {
            if (m_StartButton)
                m_StartButton->Render();
        }


        SDL_RenderPresent(Engine::Window::Renderer);
    }

    void Game::HandleEvents() {
        SDL_PollEvent(&m_Event);

        SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

        switch (m_Event.type) {
            case SDL_QUIT:
                m_IsRunning = false;
                break;

            case SDL_MOUSEBUTTONDOWN: {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (m_StartButton->CheckClicked(x, y))
                    StartGame();

                break;
            }
        }
    }

    void Game::StartGame() {
        LOG("START!!!!!!!!");
        m_Map.Init();
        delete m_StartButton;
    }

#pragma endregion
}

