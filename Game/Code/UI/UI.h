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
        StartButton* m_StartButton = nullptr;

        void InitStartButton();
    };

} // Avoidant
