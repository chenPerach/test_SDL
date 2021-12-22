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

inline bool Loop::isFinished() {
	return is_finished;
}