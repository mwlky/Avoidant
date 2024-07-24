#include "StartButton.h"
#include "../Settings.h"

namespace Avoidant {

    class MainMenu {
    public:
        MainMenu() = default;
        ~MainMenu();

        void Init();
        void Render();

        bool IsStartGameButtonClicked(int x, int y) const;

    private:

        void InitCredits();
        void InitTitleText();
        void InitTitleFont();
        void InitBackground();
        void InitStartButton();
        void InitCreditsFont();
        void DrawBackground() const;

    private:
        StartButton* m_StartButton = nullptr;

        TTF_Font* m_TitleFont = nullptr;
        TTF_Font* m_CreditsFont = nullptr;

        SDL_Rect m_TitleRect {};
        SDL_Texture* m_TitleTexture = nullptr;

        SDL_Rect m_CreditsRect {};
        SDL_Texture* m_CreditsTexture = nullptr;

        SDL_Texture* m_BackgroundTexture = nullptr;
    };

} // Avoidant
