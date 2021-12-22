#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
using namespace std;

struct ScreenSettings {
	string title;
	uint16_t WIDTH, HEIGHT;
	uint32_t screen_flag;
};

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Surface* load_BMP_image(const string& path); 
SDL_Surface* optimize_surface(SDL_Surface* surface, const SDL_Surface* window_surface);

SDL_Surface* load_PNG_image(const string& path);