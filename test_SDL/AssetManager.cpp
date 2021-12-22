#include "AssetManager.h"

SDL_Surface* AssetManager::load_BMP_image(const string& path)
{
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    if (surface == NULL)
        cout << "[" << __FILE__ << ":" << __LINE__ << "] " << "Failed to load image ''" << path << "'" << " Error: " << SDL_GetError() << endl;


    return surface;
}

SDL_Surface* AssetManager::optimize_surface(SDL_Surface* surface)
{
    SDL_Surface* optimized = SDL_ConvertSurface(surface, &format, 0);
    if (optimized == NULL)
        cout << "[" << __FILE__ << ":" << __LINE__ << "]: " << "Failed to optimize surface";
    else
        SDL_FreeSurface(surface);
    return optimized;
}

SDL_Surface* AssetManager::load_asset_image(const string& path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL) {
        cout << "[" << __FILE__ << ":" << __LINE__ << "]: Failed to load asset: " << path << " \nError: " << IMG_GetError() << endl;
    }
    return surface;
}

SDL_Surface* AssetManager::load_asset(const string& path, bool optimize)
{
    if (assets.contains(path))
        return assets[path];

    SDL_Surface* surface = load_asset_image(path);
    if (surface != NULL && optimize) {
        surface = optimize_surface(surface);
    }
    if (surface == NULL) {
        cout << "[" << __FILE__ << ":" << __LINE__ << "]: Failed to load asset: " << path << " \nError: " << IMG_GetError() << endl;
    }
    else {
        assets[path]= surface;
    }
    return surface;
}

void AssetManager::config(const SDL_PixelFormat* format)
{
    this->format = *format;
}

AssetManager::AssetManager()
{
    uint32_t flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!IMG_Init(flags)) 
        cout << "Failed to initialize SDL_Image Error: " << IMG_GetError() << endl;
    
}

AssetManager::~AssetManager()
{
    for (auto& [key, value] : assets) {
        SDL_FreeSurface(value);
    }
}
