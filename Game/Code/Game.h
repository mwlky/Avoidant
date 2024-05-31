#include "../../Core/Code/Engine.h"
#include "Data/WindowSettings.h"
#include "SDL2/SDL.h"

namespace Application{

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

        Engine::Engine* m_Engine = nullptr;
        SDL_Event m_Event;
    };
}

