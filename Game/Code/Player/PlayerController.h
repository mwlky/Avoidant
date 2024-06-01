#include <Code/Engine.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/SpriteLoader.h>
#include <Code/Utilities/Macros.h>

#include "PlayerData.h"

namespace Avoidant {

    class PlayerController {

    public:
        PlayerController();
        ~PlayerController();

        void Init();
        void Tick();
        void Render();
    private:
        PlayerData m_Data;

        Engine::Vector2 m_PlayerPosition;

        SDL_Rect m_SourceRect = {0,0, m_Data.xSize, m_Data.ySize};
        SDL_Rect m_DestRect = {0,0, m_Data.xSize * 3,m_Data.ySize * 3};

        SDL_Texture* m_PlayerTexture = nullptr;
        SDL_Rect m_PlayerTextureRect;
    };

} // Avoidant
