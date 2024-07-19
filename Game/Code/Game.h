#include <SDL.h>
#include <Code/Engine.h>

#include "Map/Map.h"
#include "Player/Player.h"
#include "UI/StartButton.h"
#include "UI/UI.h"

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
        void StartGame();

    private:
        bool m_IsRunning = false;

        Map m_Map;
        SDL_Event m_Event;

        UI* m_Ui = nullptr;
        Engine::Engine* m_Engine = nullptr;
    };
}

