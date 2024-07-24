#include <SDL.h>
#include <Code/Engine.h>
#include <box2d/b2_body.h>

#include "../Settings.h"
#include "BulletUserData.h"

namespace Avoidant {
    class Bullet {

    public:
        Bullet(int direction, int x, int y, b2Body *body);
        ~Bullet();

        void Draw();
        void Tick(double deltaTime);

        bool CheckLifetime() const;
        b2Body *GetBody() const { return m_Body; }

    private:
        float GetRandomSpeed();
        void UpdateLifeTime(float deltaTime);

    private:
        b2Body *m_Body = nullptr;
        SDL_Texture *m_Texture = nullptr;

        SDL_Rect m_SourceRect{0, 0, 32, 32};
        SDL_Rect m_DestRect{0, 0, 32, 32};

        int m_Direction = 0;
        double m_LifeTime = 0;
    };
}

