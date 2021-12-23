#pragma once
#include <SDL.h>
#include <iostream>
#include "util.h"
#include "Loop.h"
#include "AssetManager.h"
using namespace std;

class Context : public Loop
{
private: 
	AssetManager mAssetManager;
	shared_ptr<SDL_Window> mWindow;
	shared_ptr<SDL_Surface> mSurface;
	shared_ptr<SDL_Renderer> mRenderer;
	shared_ptr<ScreenSettings> mSettings;
public:
	Context(const ScreenSettings& settings);
	~Context();
	void update_window_settings(const ScreenSettings& new_settings);
	// here you would load the scene, textures and much more
	void init() override;

	// this is the main loop, here most of the game logic happens.
	void execute() override;

	// this is the end of the game, here you should close all game threads and things like that.
	void end() override;
};

