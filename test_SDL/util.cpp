#include "util.h"
SDL_Surface* loadImage(const string& path) {
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    if (surface == NULL)
        cout << "[" << __FILE__ << ":" << __LINE__ << "] " << "Failed to load image ''" << path << "'" << " Error: " << SDL_GetError() << endl;
    return surface;
}