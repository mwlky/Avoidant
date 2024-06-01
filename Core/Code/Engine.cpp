#include "Engine.h"

namespace Engine {

    void Engine::OpenWindow(const char* title, int x, int y, int width, int height) {
        m_Window = new Window(title, x, y, width, height);
    }

    Engine::~Engine() {
        delete m_Window;
    }

    Window* Engine::GetWindow() const {
        return m_Window;
    }
}

