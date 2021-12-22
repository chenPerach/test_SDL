#include "util.h"
SDL_Surface* load_BMP_image(const string& path) {
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    if (surface == NULL) 
        cout << "[" << __FILE__ << ":" << __LINE__ << "] " << "Failed to load image ''" << path << "'" << " Error: " << SDL_GetError() << endl;
    

    return surface;
}

SDL_Surface* optimize_surface(SDL_Surface* surface,const SDL_Surface* window_surface) {
    SDL_Surface* optimized = SDL_ConvertSurface(surface,window_surface->format,0);
    if (optimized == NULL)
        cout << "[" << __FILE__ << ":" << __LINE__ << "]: " << "Failed to optimize surface";
    else
        SDL_FreeSurface(surface);
    return optimized;
}
SDL_Surface* load_PNG_image(const string& path) {
    return NULL; 
}