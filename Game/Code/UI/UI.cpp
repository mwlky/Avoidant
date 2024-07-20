#include "UI.h"

namespace Avoidant {
    UI::~UI() {
        delete m_StartButton;

        TTF_CloseFont(m_Font);
        SDL_DestroyTexture(m_TitleTexture);
        SDL_DestroyTexture(m_CreditsTexture);
        TTF_Quit();
    }

    void UI::Init() {
        Settings settings;
        m_Font = TTF_OpenFont(settings.MainMenuFontPath, settings.FontSize);
        if (!m_Font) {
            LOG_ERROR("[Font loading error] " << TTF_GetError());
            return;
        }

        InitBackground();
        InitStartButton();
        InitTitleText();
    }

    void UI::InitStartButton() {
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

    bool UI::IsStartGameButtonClicked(int x, int y) const {
        return m_StartButton->CheckClicked(x, y);
    }

    void UI::Render() {
        DrawBackground();

        Engine::SpriteLoader::Draw(m_TitleTexture, m_TitleRect);

        m_StartButton->Render();
    }

    void UI::DrawBackground() const {
        Settings settings;

        int width = std::round(settings.Width * 1.1f);
        int height = std::round(settings.Height * 1.1f);

        SDL_Rect backgroundDestination {-2, 0, width, height};

        Engine::SpriteLoader::Draw(m_BackgroundTexture, backgroundDestination);
    }

    void UI::InitTitleText() {
        Settings settings;

        SDL_Color color = {255, 255, 255, 255};

        SDL_Surface *surface = TTF_RenderText_Blended(m_Font, "Avoidant", color);
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

    void UI::InitBackground() {
        Settings settings;

        m_BackgroundTexture = Engine::SpriteLoader::LoadTexture(settings.BackgroundPath);
    }
} // Avoidant