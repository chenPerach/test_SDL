
#include "Context.h"
#include "util.h"

int main(int argc, char* args[])
{
	ScreenSettings settings = { "title",1240,720,SDL_WINDOW_SHOWN };
	Context g(settings);
	g.run();
	
	return 0;
}