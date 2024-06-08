#include <Code/Engine.h>
#include "Player/Player.h"
#include "Data/WindowSettings.h"
#include "Map/Map.h"
#include "SDL2/SDL.h"

namespace Avoidant{

    class Game {

    public:
        Game();
        ~Game();

        void Init();
        void Tick(double deltaTime);
        void Render();
        void HandleEvents();

        bool IsRunning() const;

    private:

        bool m_IsRunning = false;

        Map m_Map;

        Engine::Engine* m_Engine = nullptr;
        SDL_Event m_Event;
    };
}

