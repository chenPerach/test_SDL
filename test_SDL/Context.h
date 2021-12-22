#pragma once
#include <SDL.h>
#include <iostream>
#include "util.h"
#include "Loop.h"
using namespace std;

class Context : public Loop
{
private: 
	shared_ptr<SDL_Window> mWindow;
	shared_ptr<SDL_Surface> mSurface;
	shared_ptr<ScreenSettings> screen_settings;
public:
	Context(const ScreenSettings& settings);
	~Context();
	void update_window_settings(const ScreenSettings& new_settings);
	void init() override;
	void execute() override;
	void end() override;
};

