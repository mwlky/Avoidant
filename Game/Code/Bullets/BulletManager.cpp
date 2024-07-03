#include <algorithm>
#include "BulletManager.h"
#include "BulletUserData.h"

namespace Avoidant {
    BulletManager::BulletManager(b2World *world) {
        m_World = world;
    }

    BulletManager::~BulletManager() {
        m_Bullets.clear();
    }

    void BulletManager::Tick(double deltaTime) {
        m_CurrentTime += deltaTime;

        for (Bullet &bullet: m_Bullets)
            bullet.Tick(deltaTime);

        TrySpawnBullet();
        KillBullets();
    }

    void BulletManager::TrySpawnBullet() {
        Settings settings;

        if (m_CurrentTime < settings.CooldownBetweenBullets)
            return;

        SpawnBullet();
        m_CurrentTime = 0;
    }

    void BulletManager::Draw() {
        for (Bullet &bullet: m_Bullets)
            bullet.Draw();
    }

    void BulletManager::SpawnBullet() {
        Settings settings;

        int direction = GenerateDirection();

        int x = direction == -1 ? settings.RightSpawnPosition : settings.LeftSpawnPosition;
        float y = GenerateY();

        b2BodyDef bulletBodyDef;
        bulletBodyDef.fixedRotation = true;
        bulletBodyDef.type = b2_kinematicBody;
        bulletBodyDef.position.Set(x, y);

        b2Body *bulletBody = m_World->CreateBody(&bulletBodyDef);

        b2PolygonShape fixtureShape;
        fixtureShape.SetAsBox(settings.InGameBulletSize * 0.5f * settings.ScalingFactor,
                              settings.InGameBulletSize * 0.5f * settings.ScalingFactor);

        b2FixtureDef polygonShape;
        polygonShape.isSensor = true;
        polygonShape.shape = &fixtureShape;

        bulletBody->CreateFixture(&polygonShape);

        BulletUserData* bulletUserData = new BulletUserData();
        bulletBody->GetUserData().pointer = reinterpret_cast<uintptr_t>(bulletUserData);

        Bullet newBullet = Bullet(direction, x, y, bulletBody);
        m_Bullets.push_back(newBullet);
    }

    int BulletManager::GenerateDirection() {
        Engine::Math math;

        int randomNumber = math.GenerateNumber(0, 1);
        return randomNumber == 0 ? -1 : 1;
    }

    float BulletManager::GenerateY() {
        Engine::Math math;
        Settings settings;

        float randomNumber = math.GenerateNumber(0.f, settings.MaxBulletHeight);
        return randomNumber;
    }

    void BulletManager::KillBullets() {
        auto it = std::remove_if(m_Bullets.begin(), m_Bullets.end(), [this](Bullet& bullet) {
            if (bullet.CheckLifetime()) {
                b2Body* body = bullet.GetBody();
                BulletUserData* userData = reinterpret_cast<BulletUserData*>(body->GetUserData().pointer);

                if (userData)
                    delete userData;

                m_World->DestroyBody(body);
                return true;
            }
            return false;
        });

//        m_World->DestroyBody(b)

        m_Bullets.erase(it, m_Bullets.end());
    }
}