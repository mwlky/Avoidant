#include "StartButton.h"

namespace Avoidant {
    StartButton::StartButton(SDL_Rect destination, SDL_Rect source, const char *sprite) : Button(destination, source,
                                                                                                 sprite) {
    }

    void StartButton::OnClicked() {
    }

} // Avoidant