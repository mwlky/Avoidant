#include "../../Core/Code/Engine.h"
#include "Player/PlayerController.h"
#include "Data/WindowSettings.h"
#include "SDL2/SDL.h"

namespace Avoidant{

    class Game {

    public:
        Game();
        ~Game();

        void Init();
        void Tick();
        void Render();
        void HandleEvents();

        bool IsRunning() const;

    private:

        bool m_IsRunning = false;

        PlayerController m_PlayerController;

        Engine::Engine* m_Engine = nullptr;
        SDL_Event m_Event;
    };
}

