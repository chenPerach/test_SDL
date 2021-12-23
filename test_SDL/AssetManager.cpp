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
    SDL_Surface* optimized = SDL_ConvertSurface(surface, conf.format, 0);
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

SDL_Surface* AssetManager::load_image(const string& path, bool optimize)
{
    if (mSurfaces.contains(path))
        return mSurfaces[path];

    SDL_Surface* surface = load_asset_image(path);
    if (surface != NULL && optimize) {
        surface = optimize_surface(surface);
    }
    if (surface == NULL) {
        cout << "[" << __FILE__ << ":" << __LINE__ << "]: Failed to load asset: " << path << " \nError: " << IMG_GetError() << endl;
    }
    else {
        mSurfaces[path]= surface;
    }
    return surface;
}

SDL_Texture* AssetManager::load_texture(const string& path)
{

    if (mTextures.contains(path)) {
        return mTextures[path];
    }

    SDL_Surface* surface = load_image(path);
    if (surface == NULL) {
        cout << "unable to load texture: " << path << endl;
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(conf.renderer, surface);
    
    if (texture == NULL) {
        cout << "Unable to create texture from: " << path << "\nError: " << SDL_GetError() << endl;
        return NULL;
    }
    
    mTextures[path] = texture;

    return texture;
}



AssetManager::AssetManager(const AssetManagerConfig& config)
{
    conf = config;
    uint32_t flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!IMG_Init(flags)) 
        cout << "Failed to initialize SDL_Image Error: " << IMG_GetError() << endl;
    
}

AssetManager::~AssetManager()
{

    for (auto& [key, value] : mTextures) {
        SDL_DestroyTexture(value);
        mTextures.erase(key);
    }
    for (auto& [key, value] : mSurfaces) {
        SDL_FreeSurface(value);
        mSurfaces.erase(key);
    }
}
