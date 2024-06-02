#pragma once

namespace Avoidant{

    struct PlayerData{
     const char* SpritePath = "../../Assets/Player/adventurer-Sheet.png";

     // Sprite size on sheet
     const int xSize = 50;
     const int ySize = 37;

     // In game size
     const int xGameSize = xSize * 3;
     const int yGameSize = ySize * 3;

     const int PlayerSpeed = 5;
    };
}
