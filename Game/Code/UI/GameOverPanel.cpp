#include "GameOverPanel.h"

namespace Avoidant {
    GameOverPanel::GameOverPanel() {

        LoadFont();
        LoadGameOverTexture();
    }

    GameOverPanel::~GameOverPanel() {
        TTF_CloseFont(m_Font);
        SDL_DestroyTexture(m_GameOverTexture);
    }

    void GameOverPanel::LoadGameOverTexture() {

        SDL_Color color = {13, 51, 34, 255};
        m_GameOverTexture = Engine::SpriteLoader::LoadText("Game Over!", m_Font, color);

        Settings settings;

        m_GameOverRect.x = settings.GameOverTextXPosition;
        m_GameOverRect.y = settings.GameOverTextYPosition;
        m_GameOverRect.w = settings.GameOverTextWidth;
        m_GameOverRect.h = settings.GameOverTextHeight;
    }

    void GameOverPanel::LoadFont() {
        Settings settings;

        m_Font = TTF_OpenFont(settings.CreditsFontPath, settings.GameOverTextSize);
    }

    void GameOverPanel::Render(float score) {

        Settings settings;
        SDL_Color color = {255, 255, 255, 255};

        std::string text = "Score: " + std::to_string((int)score);

        SDL_Texture *texture = Engine::SpriteLoader::LoadText(text.c_str(), m_Font, color);

        SDL_Rect scoreRect = {settings.ScoreDestinationX, settings.ScoreDestinationY, settings.ScoreDestinationWidth, settings.ScoreDestinationHeight};

        Engine::SpriteLoader::Draw(texture, scoreRect);
        SDL_DestroyTexture(texture);

        Engine::SpriteLoader::Draw(m_GameOverTexture, m_GameOverRect);
    }

    void GameOverPanel::ShowHighScore() {

    }
} // Avoidant