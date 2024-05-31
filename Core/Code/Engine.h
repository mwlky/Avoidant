#include "SDL2/SDL.h"
#include "Code/Window/Window.h"

namespace Engine {

    class Engine {

    public:
        Engine() = default;

        ~Engine();

        void OpenWindow(const char *title, int x, int y, int width, int height);

    private:
        Window *m_Window = nullptr;

    };

}
