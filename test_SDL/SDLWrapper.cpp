#include "SDLWrapper.h"

SDLWrapper::SDLWrapper()
{
	init();
}

SDLWrapper::~SDLWrapper()
{
	close();
}

void SDLWrapper::init()
{

}

void SDLWrapper::loadImage()
{
}

void SDLWrapper::close()
{

	SDL_FreeSurface(mSurface.get());

	SDL_DestroyWindow(mWindow.get());
	SDL_Quit();
}
