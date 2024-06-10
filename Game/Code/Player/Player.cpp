#include "Player.h"

namespace Avoidant {
    Player::Player(b2Fixture *body) {
        m_Body = body;
    }

    Player::~Player() {
        SDL_DestroyTexture(m_PlayerTexture);
    }

    void Player::Init() {
        m_PlayerTexture = Engine::SpriteLoader::LoadTexture(m_Data.SpritePath);
    }

    void Player::Tick() {
        CheckInput();
        UpdatePlayerPosition();

        LOG(m_IsGrounded);
    }

    void Player::UpdatePlayerPosition() {
        Settings settings;

        float newPosX = m_Body->GetBody()->GetPosition().x / settings.ScalingFactor;
        float newPosY = m_Body->GetBody()->GetPosition().y / settings.ScalingFactor;

        m_DestRect.x = newPosX - m_Data.xGameSize * 0.5f;

        // Move sprite upward to fit into collider
        m_DestRect.y = newPosY - m_Data.yGameSize * 0.5f - 5;
    }

    void Player::Render() {

        SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

    void Player::CheckInput() {

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        float desiredX = 0;

        Settings settings;

        if (keystates[SDL_SCANCODE_D])
            desiredX = m_Data.PlayerSpeed * settings.ScalingFactor;
        else if (keystates[SDL_SCANCODE_A])
            desiredX = -m_Data.PlayerSpeed * settings.ScalingFactor;

        if (keystates[SDL_SCANCODE_SPACE] && m_IsGrounded) {
            float jumpImpulse = m_Body->GetBody()->GetMass() * m_Data.JumpSpeed;
            m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(0, -jumpImpulse), true);

            m_IsGrounded = false;
        }

        b2Vec2 currentVelocity = m_Body->GetBody()->GetLinearVelocity();

        float velChangeX = desiredX - currentVelocity.x;
        float impulseX = m_Body->GetBody()->GetMass() * velChangeX;

        m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(impulseX, 0), true);
    }

    void Player::BeginContact(b2Contact *contact) {
        b2Fixture *fixtureA = contact->GetFixtureA();
        b2Fixture *fixtureB = contact->GetFixtureB();

        if (fixtureA == m_Body || fixtureB == m_Body) {
            if (fixtureA->IsSensor() || fixtureB->IsSensor()) {
                m_GroundContacts++;
                m_IsGrounded = true;
            }
        }
    }

    void Player::EndContact(b2Contact *contact) {
        b2Fixture *fixtureA = contact->GetFixtureA();
        b2Fixture *fixtureB = contact->GetFixtureB();

        if (fixtureA == m_Body || fixtureB == m_Body) {
            if (fixtureA->IsSensor() || fixtureB->IsSensor()) {
                m_GroundContacts--;

                if (m_GroundContacts == 0)
                    m_IsGrounded = false;
            }
        }
    }
} // Avoidant