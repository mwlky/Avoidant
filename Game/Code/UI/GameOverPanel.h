#include "../Settings.h"

#include <SDL.h>
#include <Code/Engine.h>

namespace Avoidant {

    class GameOverPanel {

    public:
        GameOverPanel();
        ~GameOverPanel();

        void Render(float score);

    private:
        void LoadFont();
        void LoadGameOverTexture();
        void ShowHighScore();

    private:
        int m_Score = 0;

        TTF_Font* m_Font = nullptr;

        SDL_Rect m_GameOverRect {};

        SDL_Texture* m_ScoreTexture = nullptr;
        SDL_Texture* m_GameOverTexture = nullptr;
    };

} // Avoidant
