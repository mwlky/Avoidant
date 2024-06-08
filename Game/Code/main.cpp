#include "Game.h"

int main() {
    Avoidant::Game game;
    game.Init();

    uint32 lastTickTime = 0;
    Uint32 frameStart;
    double frameTime;
    double deltaTime = 0;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    while (game.IsRunning()){
        frameStart = SDL_GetTicks();
        deltaTime = frameStart - lastTickTime;

        game.HandleEvents();
        game.Tick(deltaTime * 0.001f);
        game.Render();

        frameTime = SDL_GetTicks() - frameStart;
        lastTickTime = frameStart;

        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
}
