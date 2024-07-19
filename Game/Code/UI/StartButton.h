#pragma once

#include "Button.h"

#include <Code/Utilities/Macros.h>

namespace Avoidant {

    class StartButton : public Button {

    public:
        StartButton(SDL_Rect destination, SDL_Rect source, const char* sprite);
        ~StartButton() override = default;

        void OnClicked() override;

    };

} // Avoidant
