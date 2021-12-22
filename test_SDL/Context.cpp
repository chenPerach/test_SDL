#include "Context.h"

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
	asset_manager.config(mSurface->format);
	string path = "assets/png_image.png";
	SDL_Surface* surface = asset_manager.load_asset(path,true);

	SDL_Rect scale_rect = { 0,0,screen_settings->WIDTH,screen_settings->HEIGHT };
	SDL_BlitScaled(surface, NULL, mSurface.get(), &scale_rect);

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

