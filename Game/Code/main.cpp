#include "Game.h"

int main() {
    Application::Game game;
    game.Init();

    while (game.IsRunning()){

        game.HandleEvents();
        game.Render();
        game.Tick();
    }
}
