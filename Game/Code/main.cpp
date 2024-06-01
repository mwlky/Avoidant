#include "Game.h"

int main() {
    Avoidant::Game game;
    game.Init();

    Uint32 frameStart;
    double frameTime;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    while (game.IsRunning()){
        frameStart = SDL_GetTicks();

        game.HandleEvents();
        game.Render();
        game.Tick();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
}
