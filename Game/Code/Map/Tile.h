#include <SDL.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/SpriteLoader.h>

namespace Avoidant {

    class Tile {

    public:
        Tile(SDL_Rect source, SDL_Rect destination, SDL_Texture* texture);

        ~Tile();
        void Draw();

    private:
        SDL_Texture* m_Texture = nullptr;

        SDL_Rect m_Source;
        SDL_Rect m_Destination;

        Engine::Vector2 m_Position;
    };

} // Avoidant
