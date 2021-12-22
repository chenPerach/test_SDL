
#include "Context.h"
#include "util.h"

int main(int argc, char* args[])
{
	ScreenSettings settings = { "title",640,480,SDL_WINDOW_SHOWN };
	Context g(settings);
	g.run();
	
	return 0;
}