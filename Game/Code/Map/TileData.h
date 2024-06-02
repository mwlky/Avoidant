#pragma once

namespace Avoidant {

    struct TileData{

        TileData() = default;

        TileData(int sheetX, int sheetY, bool hasCollision = false){
            SheetX = sheetX;
            SheetY = sheetY;
            HasCollision = hasCollision;
        }

        int SheetX;
        int SheetY;
        bool HasCollision;
    };
}