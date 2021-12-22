/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "Game.h"

using namespace std;
//Screen dimension constants
int main(int argc, char* args[])
{
	ScreenSettings settings = { "title",640,480,SDL_WINDOW_SHOWN };
	Context g(settings);
	g.run();
	
	return 0;
}