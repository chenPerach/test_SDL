#include "Loop.h"

Loop::Loop()
{
	is_finished = false;
}
void Loop::run() {
	init();
	while (!isFinished())
		execute();
	end();
}