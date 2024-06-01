#include "SpriteLoader.h"

namespace Engine {

    SDL_Texture *SpriteLoader::LoadTexture(const char *texturePath) {
        SDL_Surface *tempSurface = IMG_Load(texturePath);

        if (!tempSurface) {
            std::cerr << "Unable to load image " << texturePath << "! SDL_image Error: " << IMG_GetError() << std::endl;
            return nullptr;
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(Window::Renderer, tempSurface);

        if (!texture) {
            std::cerr << "Unable to create texture from " << texturePath << "! SDL Error: " << SDL_GetError()
                      << std::endl;
            return nullptr;
        }
        SDL_FreeSurface(tempSurface);

        return texture;
    }

    void SpriteLoader::Draw(SDL_Texture *texture, SDL_Rect destinationPosition) {
        if(texture != nullptr){
            SDL_RenderCopy(Window::Renderer, texture, NULL, &destinationPosition);
        } else{
            std::cerr << "No texture find to draw" << std::endl;
        }
    }

    void SpriteLoader::Draw(SDL_Texture *texture, SDL_Rect sourceRect, SDL_Rect position) {
        if(texture != nullptr){
            SDL_RenderCopy(Window::Renderer, texture, &sourceRect, &position);
        } else{
            std::cerr << "No texture find to draw" << std::endl;
        }
    }
}


