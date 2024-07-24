#include "Bullet.h"

namespace Avoidant {

    Bullet::Bullet(int direction, int x, int y, b2Body *body) {
        m_Body = body;

        Settings settings;
        m_Texture = Engine::SpriteLoader::LoadTexture(settings.BulletSpritePath);

        m_Direction = direction;
        m_DestRect.x = x;
        m_DestRect.y = y;
        m_DestRect.h = m_DestRect.w = settings.InGameBulletSize;

        m_SourceRect.x = m_SourceRect.y = 0;
        m_SourceRect.w = m_SourceRect.h = settings.BulletSpriteSize;

        b2Vec2 speed = {GetRandomSpeed() * direction * 1.f ,0};

        m_Body->SetLinearVelocity(speed);
    }

    void Bullet::Tick(double deltaTime) {
        Settings settings;

        float newPosX = m_Body->GetPosition().x / settings.ScalingFactor;
        float newPosY = m_Body->GetPosition().y / settings.ScalingFactor;

        m_DestRect.x = newPosX - settings.InGameBulletSize * 0.5f;
        m_DestRect.y = newPosY - settings.InGameBulletSize * 0.5f;

        UpdateLifeTime(deltaTime);
    }

    void Bullet::Draw() {
        if (m_Direction == 1)
            SDL_RenderCopyEx(Engine::Window::Renderer, m_Texture, &m_SourceRect, &m_DestRect, 0, NULL,
                             SDL_FLIP_HORIZONTAL);
        else
            SDL_RenderCopy(Engine::Window::Renderer, m_Texture, &m_SourceRect, &m_DestRect);
    }

    bool Bullet::CheckLifetime() const {
        Settings settings;

        return m_LifeTime >= settings.MaxBulletLifeTime;
    }

    void Bullet::UpdateLifeTime(float deltaTime) {
        m_LifeTime += deltaTime;
    }

    Bullet::~Bullet() {
    }

    float Bullet::GetRandomSpeed() {
        Settings settings;

        float min = settings.MinBulletSpeed;
        float max = settings.MaxBulletSpeed;

        return Engine::Math::GenerateNumber(min,max);
    }
}


