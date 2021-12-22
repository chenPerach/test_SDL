#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
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

SDL_Surface* loadImage(const string& path);