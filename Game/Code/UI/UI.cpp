#include "UI.h"

namespace Avoidant {
    UI::~UI() {
        delete m_StartButton;
    }

    void UI::Init() {
        InitStartButton();

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
        return m_StartButton->CheckClicked(x,y);
    }

    void UI::Render() {
        m_StartButton->Render();
    }
} // Avoidant