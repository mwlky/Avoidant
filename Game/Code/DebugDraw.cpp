#include "DebugDraw.h"

const float SCALE = 1;

void DebugDraw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
    SDL_SetRenderDrawColor(Engine::Window::Renderer, color.r * 255, color.g * 255, color.b * 255, 255);
    for (int32 i = 0; i < vertexCount - 1; ++i) {
        SDL_RenderDrawLine(Engine::Window::Renderer, vertices[i].x * SCALE, vertices[i].y * SCALE,
                           vertices[i + 1].x * SCALE, vertices[i + 1].y * SCALE);
    }
    SDL_RenderDrawLine(Engine::Window::Renderer, vertices[vertexCount - 1].x * SCALE,
                       vertices[vertexCount - 1].y * SCALE, vertices[0].x * SCALE, vertices[0].y * SCALE);
}

void DebugDraw::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
    SDL_SetRenderDrawColor(Engine::Window::Renderer, color.r * 255, color.g * 255, color.b * 255, 128); // Semi-transparent
    for (int32 i = 0; i < vertexCount - 1; ++i) {
        SDL_RenderDrawLine(Engine::Window::Renderer, vertices[i].x * SCALE, vertices[i].y * SCALE,
                           vertices[i + 1].x * SCALE, vertices[i + 1].y * SCALE);
    }
    SDL_RenderDrawLine(Engine::Window::Renderer, vertices[vertexCount - 1].x * SCALE,
                       vertices[vertexCount - 1].y * SCALE, vertices[0].x * SCALE, vertices[0].y * SCALE);
}

void DebugDraw::DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) {
    // Not implemented for simplicity
}

void DebugDraw::DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) {
    // Not implemented for simplicity
}

void DebugDraw::DrawPoint(const b2Vec2 &p, float size, const b2Color &color) {
    // Not implemented for simplicity
}

void DebugDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {
    SDL_SetRenderDrawColor(Engine::Window::Renderer, color.r * 255, color.g * 255, color.b * 255, 255);
    SDL_RenderDrawLine(Engine::Window::Renderer, p1.x * SCALE, p1.y * SCALE, p2.x * SCALE, p2.y * SCALE);
}

void DebugDraw::DrawTransform(const b2Transform &xf) {
    // Not implemented for simplicity
}
