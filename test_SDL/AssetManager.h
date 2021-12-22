#pragma once
#include <iostream>
#include <map>
#include <SDL_image.h>
#include "util.h"
using namespace std;

//enum AssetType {
//	BMP,
//	PNG,
//	JPG
//};

class AssetManager
{
private:
	map<string, SDL_Surface*> assets;
	SDL_PixelFormat format;

	SDL_Surface* load_BMP_image(const string& path);
	SDL_Surface* optimize_surface(SDL_Surface* surface);

	SDL_Surface* load_asset_image(const string& path);
public:
	SDL_Surface* load_asset(const string& path,bool optimize = false);
	void config(const SDL_PixelFormat* format);
	AssetManager();
	~AssetManager();
};

