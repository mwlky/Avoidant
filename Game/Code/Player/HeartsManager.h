#include <SDL.h>
#include <Code/Engine.h>

#include "../Settings.h"

namespace Avoidant{
    class HeartsManager {
    public:
        HeartsManager();
        ~HeartsManager();

        void DrawHearts(int playerLives);

    private:

        SDL_Texture* m_HeartTexture = nullptr;
    };
}
