#include "Context.h"

Context::Context(const ScreenSettings& settings) {

	mSettings = make_shared<ScreenSettings>(settings);

	const ScreenSettings* s = mSettings.get();

	mWindow = shared_ptr<SDL_Window>(SDL_CreateWindow(s->title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, s->WIDTH, s->HEIGHT, s->screen_flag), SDL_DestroyWindow);
	mSurface = shared_ptr<SDL_Surface>(SDL_GetWindowSurface(mWindow.get()), SDL_FreeSurface);
	mRenderer = shared_ptr<SDL_Renderer>(SDL_CreateRenderer(mWindow.get(),-1,SDL_RENDERER_ACCELERATED),SDL_DestroyRenderer);
	
	AssetManagerConfig conf = { mRenderer.get(),mSurface->format };
	mAssetManager = AssetManager(conf);
}

Context::~Context()
{
	mSurface.reset();
	mRenderer.reset();
	mWindow.reset();
	IMG_Quit();
	SDL_Quit();
}

void Context::update_window_settings(const ScreenSettings& new_settings)
{
	mWindow.get();
	mSettings.reset();
	mSettings = make_shared<ScreenSettings>(new_settings.title, new_settings.WIDTH, new_settings.HEIGHT, new_settings.screen_flag);
	
	SDL_SetWindowSize(mWindow.get(),mSettings->WIDTH,mSettings->HEIGHT);
	SDL_SetWindowFullscreen(mWindow.get(),mSettings->screen_flag);
}

void Context::init()
{
	
}


void Context::execute()
{
	string path = "assets/png_image.png";
	SDL_Texture* texture = mAssetManager.load_texture(path);


	SDL_Event e;
	while (SDL_PollEvent(&e)!=0) {
		if (e.type == SDL_QUIT)
			is_finished = true;
	}

	SDL_RenderClear(mRenderer.get());

	SDL_RenderCopy(mRenderer.get(), texture, NULL, NULL);

	SDL_RenderPresent(mRenderer.get());

	
}

void Context::end()
{
}

