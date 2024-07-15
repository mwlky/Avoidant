#include "HeartsManager.h"

namespace Avoidant {


    HeartsManager::HeartsManager() {
        Settings settings;

        m_HeartTexture = Engine::SpriteLoader::LoadTexture(settings.HeartsSpritePath);
    }

    HeartsManager::~HeartsManager() {

        SDL_DestroyTexture(m_HeartTexture);
    }

    void HeartsManager::DrawHearts(int playerLives) {
        Settings settings;

        SDL_Rect source = {0, settings.HearthSpriteSize, settings.HearthSpriteSize, settings.HearthSpriteSize};

        for (int i = 0; i < playerLives; ++i) {
            SDL_Rect destiny = {settings.HearthSpacing * i, 0, settings.HearthInGameSize,
                                settings.HearthInGameSize};

            Engine::SpriteLoader::Draw(m_HeartTexture, source, destiny);
        }
    }
}