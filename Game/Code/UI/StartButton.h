#pragma once

#include "Code/UI/Button.h"

#include <Code/Utilities/Macros.h>

namespace Avoidant {

    class StartButton : public Engine::Button {

    public:
        StartButton(SDL_Rect destination, SDL_Rect source, const char *sprite);
        ~StartButton() override = default;

        void OnClicked() override;
    };

} // Avoidant
