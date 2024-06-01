#include <Code/Engine.h>
#include <Code/Math/Vector2.h>
#include <Code/Utilities/SpriteLoader.h>
#include <Code/Utilities/Macros.h>

#include "PlayerData.h"

namespace Avoidant {

    using Engine::Vector2;

    class PlayerController {

    public:
        PlayerController();
        ~PlayerController();

        void Init();
        void Tick();
        void Render();

    private:
        void CheckInput();
        void UpdatePlayerPosition();
    private:
        PlayerData m_Data;

        Vector2 m_PlayerPosition {0,0};
        Vector2 m_PlayerVelocity {0 ,0};

        // Position in sheet file
        SDL_Rect m_SourceRect = {0,0, m_Data.xSize, m_Data.ySize};

        // In game position
        SDL_Rect m_DestRect = {0,0, m_Data.xSize * 3,m_Data.ySize * 3};

        SDL_Texture* m_PlayerTexture = nullptr;
    };

} // Avoidant
