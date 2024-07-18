#include "Button.h"

namespace Avoidant {

    Button::Button(SDL_Rect destination, SDL_Rect source, const char* sprite) {
        m_Source = source;
        m_Destination = destination;

        m_Texture = Engine::SpriteLoader::LoadTexture(sprite);
    }

    bool Button::CheckClicked(int x, int y) {
        return x >= m_Destination.x && x <= m_Destination.x + m_Destination.w && y >= m_Destination.y &&
            y <= m_Destination.y + m_Destination.h;
    }

    void Button::OnClicked() {

    }

    void Button::Render() {
        Engine::SpriteLoader::Draw(m_Texture, m_Source, m_Destination);
    }
}

