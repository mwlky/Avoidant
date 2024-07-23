#include "Game.h"

int main() {
    Engine::Engine engine;
    Avoidant::Game game;
    game.Init();

    uint32 lastTickTime = 0;
    Uint32 frameStart;
    double frameTime;
    double deltaTime = 0;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    while (game.IsRunning()){
#if DEBUG
        try {
#endif
        frameStart = SDL_GetTicks();
        deltaTime = frameStart - lastTickTime;

        game.HandleEvents();
        game.Tick(deltaTime * 0.001f);
        game.Render();

        frameTime = SDL_GetTicks() - frameStart;
        lastTickTime = frameStart;

        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);

#if DEBUG
        }
        catch (std::exception& e){
            std::cerr << "Error: " << e.what() << std::endl;
        }

#endif
    }
}
