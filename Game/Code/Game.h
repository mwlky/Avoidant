#include <SDL.h>
#include <Code/Engine.h>

#include "Map/Map.h"
#include "Player/Player.h"

namespace Avoidant{

    class Game : public Engine::Application {

    public:
        Game();
        ~Game();

        void Init();
        void Render();
        void HandleEvents();
        void Tick(double deltaTime);

        bool IsRunning() const;

    private:
        bool m_IsRunning = false;

        Map m_Map;

        Engine::Engine* m_Engine = nullptr;
        SDL_Event m_Event;
    };
}

