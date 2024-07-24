#pragma once

namespace Avoidant {

    struct TileData {
    public:
        TileData() = default;

        TileData(int sheetX, int sheetY, bool hasCollision = false){
            SheetX = sheetX;
            SheetY = sheetY;
            HasCollision = hasCollision;
        }

    public:
        int SheetX;
        int SheetY;
        bool HasCollision = false;
    };
}