#include <SDL.h>
#include <Code/Engine.h>

#include "../Settings.h"

namespace Avoidant {

    class GameOverPanel {

    public:
        GameOverPanel();
        ~GameOverPanel();

        void Render(float score);

    private:
        void LoadFont();
        void LoadBackground();
        void LoadGameOverTexture();

        void RenderBackground();
        void RenderScore(float score) const;

    private:

        SDL_Rect m_GameOverRect {};

        TTF_Font* m_Font = nullptr;
        SDL_Texture* m_GameOverTexture = nullptr;
        SDL_Texture* m_BackgroundTexture = nullptr;

    };

} // Avoidant
