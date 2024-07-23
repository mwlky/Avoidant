#include "MainMenu.h"

namespace Avoidant {
    MainMenu::~MainMenu() {
        delete m_StartButton;

        TTF_CloseFont(m_TitleFont);
        SDL_DestroyTexture(m_TitleTexture);
        SDL_DestroyTexture(m_CreditsTexture);
    }

    void MainMenu::Init() {
        InitTitleFont();
        InitCreditsFont();

        InitCredits();
        InitBackground();
        InitStartButton();
        InitTitleText();
    }

    void MainMenu::InitStartButton() {
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

    bool MainMenu::IsStartGameButtonClicked(int x, int y) const {
        return m_StartButton->CheckClicked(x, y);
    }

    void MainMenu::Render() {
        DrawBackground();

        Engine::SpriteLoader::Draw(m_TitleTexture, m_TitleRect);
        Engine::SpriteLoader::Draw(m_CreditsTexture, m_CreditsRect);

        m_StartButton->Render();
    }

    void MainMenu::DrawBackground() const {
        Settings settings;

        int width = std::round(settings.Width * 1.1f);
        int height = std::round(settings.Height * 1.1f);

        SDL_Rect backgroundDestination {-2, 0, width, height};

        Engine::SpriteLoader::Draw(m_BackgroundTexture, backgroundDestination);
    }

    void MainMenu::InitTitleText() {
        Settings settings;

        SDL_Color color = {255, 255, 255, 255};

        SDL_Surface *surface = TTF_RenderText_Blended(m_TitleFont, "Avoidant", color);
        if (!surface) {
            LOG_ERROR("Surface creating error" << TTF_GetError());
            return;
        }

        m_TitleTexture = SDL_CreateTextureFromSurface(Engine::Window::Renderer, surface);

        m_TitleRect.x = settings.TitleXPosition;
        m_TitleRect.y = settings.TitleYPosition;
        m_TitleRect.w = surface->w;
        m_TitleRect.h = surface->h;

        SDL_FreeSurface(surface);
    }

    void MainMenu::InitBackground() {
        Settings settings;

        m_BackgroundTexture = Engine::SpriteLoader::LoadTexture(settings.BackgroundPath);
    }

    void MainMenu::InitCredits() {
        Settings settings;

        SDL_Color color = {255, 255, 255, 255};

        SDL_Surface *surface = TTF_RenderText_Blended(m_CreditsFont, "by Damian Gorenski", color);
        if (!surface) {
            LOG_ERROR("Surface creating error " << TTF_GetError());
            return;
        }

        m_CreditsTexture = SDL_CreateTextureFromSurface(Engine::Window::Renderer, surface);

        m_CreditsRect.x = settings.CreditsXPosition;
        m_CreditsRect.y = settings.CreditsYPosition;
        m_CreditsRect.w = surface->w;
        m_CreditsRect.h = surface->h;

        SDL_FreeSurface(surface);
    }

    void MainMenu::InitTitleFont() {
        Settings settings;
        m_TitleFont = TTF_OpenFont(settings.MainMenuFontPath, settings.TitleSize);
        if (!m_TitleFont) {
            LOG_ERROR("[Font loading error] " << TTF_GetError());
            return;
        }
    }

    void MainMenu::InitCreditsFont() {
        Settings settings;
        m_CreditsFont = TTF_OpenFont(settings.CreditsFontPath, settings.CreditsSize);
        if (!m_TitleFont) {
            LOG_ERROR("[Font loading error] " << TTF_GetError());
            return;
        }
    }
} // Avoidant