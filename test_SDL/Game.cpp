#include "Game.h"

Context::Context(const ScreenSettings& settings) {

	screen_settings = make_shared<ScreenSettings>(settings);
}

Context::~Context()
{
	mSurface.reset();
	mWindow.reset();
	SDL_Quit();

}

void Context::update_window_settings(const ScreenSettings& new_settings)
{
	mWindow.get();
	screen_settings.reset();
	screen_settings = make_shared<ScreenSettings>(new_settings.title, new_settings.WIDTH, new_settings.HEIGHT, new_settings.screen_flag);
	
	SDL_SetWindowSize(mWindow.get(),screen_settings->WIDTH,screen_settings->HEIGHT);
	SDL_SetWindowFullscreen(mWindow.get(),screen_settings->screen_flag);
}

void Context::init()
{
	const ScreenSettings* s = screen_settings.get();

	mWindow = shared_ptr<SDL_Window>(SDL_CreateWindow(s->title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, s->WIDTH, s->HEIGHT, s->screen_flag),SDL_DestroyWindow);
	
	mSurface = shared_ptr<SDL_Surface>(SDL_GetWindowSurface(mWindow.get()),SDL_FreeSurface);
	
	string path = "assets/press_x.bmp";
	SDL_Surface* img = SDL_LoadBMP(path.c_str());
	SDL_BlitSurface(img,NULL,mSurface.get(),NULL);

}


void Context::execute()
{
	SDL_Event e;
		while (SDL_PollEvent(&e)!=0) {
			if (e.type == SDL_QUIT)
				is_finished = true;
		}
		SDL_UpdateWindowSurface(mWindow.get());
}

void Context::end()
{
}

