#include <SDL.h>
#include <Code/Engine.h>

#include "Map/Map.h"
#include "Player/Player.h"
#include "UI/StartButton.h"

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
        void InitUI();
        void StartGame();

    private:
        bool m_IsRunning = false;

        Map m_Map;
        SDL_Event m_Event;

        Engine::Engine* m_Engine = nullptr;
        StartButton* m_StartButton = nullptr;
    };
}

