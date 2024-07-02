#include <box2d/box2d.h>

#include "../Settings.h"
#include "Bullet.h"
#include <Code/Engine.h>

namespace Avoidant {


    class BulletManager {

    public:
        BulletManager(b2World *world);
        ~BulletManager();

        void Draw();
        void Tick(double deltaTime);

    private:

        void SpawnBullet();
        void TrySpawnBullet();
        void KillBullets();

        int GenerateDirection();
        float GenerateY();

    private:
        std::vector<Bullet> m_Bullets;

        b2World *m_World = nullptr;

        float m_CurrentTime = 0;
    };
}