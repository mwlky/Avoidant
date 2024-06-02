#include "SpriteLoader.h"

namespace Engine {

    SDL_Texture *SpriteLoader::LoadTexture(const char *texturePath) {
        SDL_Surface *tempSurface = IMG_Load(texturePath);

        if (!tempSurface) {
            LOG_ERROR(SDL_GetError());
//            std::cerr << "Unable to load image " << texturePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
            return nullptr;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(Window::Renderer, tempSurface);

        if (!texture) {
//            std::cerr << "Unable to create texture from " << texturePath << "! SDL Error: " << SDL_GetError()
//                      << std::endl;

            LOG_ERROR(SDL_GetError());

            return nullptr;
        }
        SDL_FreeSurface(tempSurface);

        return texture;
    }

    void SpriteLoader::Draw(SDL_Texture *texture, SDL_Rect destinationPosition) {
        if(texture != nullptr)
            SDL_RenderCopy(Window::Renderer, texture, NULL, &destinationPosition);

        else
            LOG_ERROR("No found texture to draw");
//            std::cerr << "No texture find to draw" << std::endl;

    }

    void SpriteLoader::Draw(SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect position) {
        if(texture != nullptr)
            SDL_RenderCopy(Window::Renderer, texture, &sourceRect, &position);

         else
            LOG_ERROR("No found texture to draw");
//            std::cerr << "No texture find to draw" << std::endl;

    }

    void SpriteLoader::Draw(SDL_Texture *texture) {
        if(texture != nullptr)
            SDL_RenderCopy(Window::Renderer, texture, NULL, NULL);

        else
            LOG_ERROR("No found texture to draw");
    }
}


