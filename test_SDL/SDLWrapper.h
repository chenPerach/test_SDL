#pragma once
#include "global.h"

class SDLWrapper
{
private:
	shared_ptr<SDL_Window> mWindow;
	shared_ptr<SDL_Surface> mSurface;

public:
	SDLWrapper();
	~SDLWrapper();
	void init();
	void loadImage();
	void close();
};

