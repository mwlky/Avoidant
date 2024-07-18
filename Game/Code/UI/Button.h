#include <SDL.h>
#include <Code/Engine.h>

namespace Avoidant {

    class Button {

    public:
        Button(SDL_Rect destination, SDL_Rect source, const char* sprite);
        virtual ~Button() = default;

        bool CheckClicked(int x, int y);

        void Render();
        virtual void OnClicked();

    private:
        SDL_Rect m_Source;
        SDL_Rect m_Destination;

        SDL_Texture* m_Texture = nullptr;
    };
}

