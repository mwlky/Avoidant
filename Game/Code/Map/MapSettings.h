#pragma once

namespace Avoidant{

    struct MapSettings{

        int InGameTileSize = 80;
        int TileSize = 32;

        Engine::Vector2 Gravity {0.f, 9.81f};
    };
}
