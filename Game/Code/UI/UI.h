#include "StartButton.h"
#include "../Settings.h"


namespace Avoidant {

    class UI {
    public:
        UI() = default;
        ~UI();

        void Init();
        void Render();

        bool IsStartGameButtonClicked(int x, int y) const;

    private:
        void InitTitleText();
        void InitBackground();
        void InitStartButton();

    private:
        StartButton* m_StartButton = nullptr;
        TTF_Font* m_Font = nullptr;

        SDL_Rect m_TitleRect;
        SDL_Texture* m_TitleTexture = nullptr;

        SDL_Rect m_CreditsRect;
        SDL_Texture* m_CreditsTexture = nullptr;

        SDL_Rect m_BackgroundRect;
        SDL_Texture* m_BackgroundTexture = nullptr;

        void DrawBackground() const;
    };

} // Avoidant
