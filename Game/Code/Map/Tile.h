#include <SDL.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/SpriteLoader.h>

#include "TileData.h"
#include "../Player/PlayerData.h"
#include <SDL.h>


namespace Avoidant {

    class Tile {

    public:
        Tile(SDL_Rect source, SDL_Rect destination);

        ~Tile() = default;

    public:
        void Draw(SDL_Texture* tilesSheet);

        bool IsColliding(Engine::Vector2 playerPosition);

    private:
        SDL_Rect m_Source{};
        SDL_Rect m_Destination{};

        Engine::Vector2 m_Position{};
    };

} // Avoidant
