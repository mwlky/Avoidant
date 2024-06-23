#include "Player.h"

namespace Avoidant {
    Player::Player(b2Fixture *body) {
        m_Body = body;
        Settings settings;

        m_SourceRect = {0, 0, settings.xSize, settings.ySize};
        m_DestRect = {0, 0, settings.xSize * 3, settings.ySize * 3};
    }

    Player::~Player() {
        SDL_DestroyTexture(m_PlayerTexture);
    }

    void Player::Init() {
        Settings settings;

        m_PlayerTexture = Engine::SpriteLoader::LoadTexture(settings.SpritePath);
    }

    void Player::Tick() {
        CheckInput();
        UpdatePlayerPosition();

        LOG(m_IsGrounded)
    }

    void Player::Render() {

        if (m_IsFlipped)
            SDL_RenderCopyEx(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect, 0, NULL,
                             SDL_FLIP_HORIZONTAL);
        else
            SDL_RenderCopy(Engine::Window::Renderer, m_PlayerTexture, &m_SourceRect, &m_DestRect);
    }

#pragma region === Movement ===

    void Player::UpdatePlayerPosition() {
        Settings settings;

        float newPosX = m_Body->GetBody()->GetPosition().x / settings.ScalingFactor;
        float newPosY = m_Body->GetBody()->GetPosition().y / settings.ScalingFactor;

        m_DestRect.x = newPosX - settings.xGameSize * 0.5f;

        // Move sprite upward to fit into collider
        m_DestRect.y = newPosY - settings.yGameSize * 0.5f - 5;
    }

    void Player::CheckInput() {

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        float desiredX = 0;

        Settings settings;

        if (keystates[SDL_SCANCODE_SPACE] && m_IsGrounded)
            Jump();

        if (keystates[SDL_SCANCODE_D])
            desiredX = settings.PlayerSpeed * settings.ScalingFactor;
        else if (keystates[SDL_SCANCODE_A])
            desiredX = -settings.PlayerSpeed * settings.ScalingFactor;

        if (desiredX != 0)
            PlayMovementAnimation(desiredX);

        else
            PlayIdleAnimation();

        MovePlayer(desiredX);
    }

    void Player::MovePlayer(float desiredX) {
        b2Vec2 currentVelocity = m_Body->GetBody()->GetLinearVelocity();

        float velChangeX = desiredX - currentVelocity.x;
        float impulseX = m_Body->GetBody()->GetMass() * velChangeX;

        m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(impulseX, 0), true);
    }

    void Player::Jump() {
        Settings settings;

        float jumpImpulse = m_Body->GetBody()->GetMass() * settings.JumpSpeed;
        m_Body->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(0, -jumpImpulse), true);

        m_IsGrounded = false;
    }

#pragma endregion

#pragma region === Ground Detection ===

    void Player::BeginContact(b2Contact *contact) {
        b2Fixture *fixtureA = contact->GetFixtureA();
        b2Fixture *fixtureB = contact->GetFixtureB();

        if ((fixtureA->IsSensor() || fixtureB->IsSensor()) &&
            (fixtureA->GetBody() == m_Body->GetBody() || fixtureB->GetBody() == m_Body->GetBody()))
            m_IsGrounded = true;
    }

    void Player::EndContact(b2Contact *contact) {
//        b2Fixture *fixtureA = contact->GetFixtureA();
//        b2Fixture *fixtureB = contact->GetFixtureB();
//
//        if ((fixtureA->IsSensor() || fixtureB->IsSensor()) &&
//            (fixtureA->GetBody() == m_Body->GetBody() || fixtureB->GetBody() == m_Body->GetBody()))
//            m_IsGrounded = false;
    }


#pragma endregion

#pragma region === Animation ===

    void Player::PlayMovementAnimation(float movementDirection) {
        if (movementDirection > 0)
            m_IsFlipped = false;

        else
            m_IsFlipped = true;

        PlayRunAnimation();
    }

    void Player::PlayRunAnimation() {
        Settings settings;

        PlayAnimation(settings.RunAnimXPosOnSheet,
                      settings.RunAnimYPosOnSheet,
                      settings.RunSpritesAmount,
                      settings.RunAnimationDelay);
    }

    void Player::PlayIdleAnimation() {
        Settings settings;

        if(m_SourceRect.y != settings.IdleAnimationYPosOnSheet){
            m_SourceRect.y = settings.IdleAnimationYPosOnSheet;
            m_SourceRect.x = settings.IdleAnimationXPosOnSheet;
        }

        PlayAnimation(settings.IdleAnimationXPosOnSheet,
                      settings.IdleAnimationYPosOnSheet,
                      settings.IdleSpritesAmount,
                      settings.IdleAnimationDelay);
    }

    void Player::PlayAnimation(int xPosOnSheet, int yPosOnSheet, int spritesAmount, int delay) {
        uint32 currentTime = SDL_GetTicks();
        if (m_CurrentFrame >= spritesAmount)
            m_CurrentFrame = 0;

        if (currentTime - m_LastFrame > delay) {
            m_SourceRect.y = yPosOnSheet;
            m_SourceRect.x = xPosOnSheet + m_CurrentFrame * xPosOnSheet;
            m_CurrentFrame++;

            if (m_CurrentFrame >= spritesAmount)
                m_CurrentFrame = 0;

            m_LastFrame = currentTime;
        }
    }

#pragma endregion

} // Avoidant