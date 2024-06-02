#include <Code/Utilities/SpriteLoader.h>

namespace Avoidant{

    class Map {

    public:
        Map() = default;
        ~Map();

        void InitBackground();
        void Draw();

    private:
        SDL_Texture* m_BackgroundTexture = nullptr;
    };
}


