#pragma once
#include <iostream>
#include <map>
#include <SDL_image.h>
#include "util.h"
using namespace std;

struct AssetManagerConfig {
	SDL_Renderer* renderer;
	const SDL_PixelFormat* format;
};
class AssetManager
{
private:
	map<string, SDL_Surface*> mSurfaces;
	map<string, SDL_Texture*> mTextures;

	AssetManagerConfig conf;
	
	SDL_Surface* load_BMP_image(const string& path);
	SDL_Surface* optimize_surface(SDL_Surface* surface);
	SDL_Surface* load_asset_image(const string& path);
public:
	SDL_Surface* load_image(const string& path,bool optimize = false);
	SDL_Texture* load_texture(const string& path);
	AssetManager(const AssetManagerConfig& config = {NULL,NULL});
	~AssetManager();
};

