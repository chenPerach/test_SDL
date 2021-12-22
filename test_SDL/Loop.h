#pragma once

/**
	this simple object is a while-loop-like structure
	that will (probobly idk) be used in creating threads with loops in them

	btw what the hell are atomic methods?
*/
class Loop
{
protected:
	bool is_finished;
public:
	Loop();
	inline bool isFinished() {
		return is_finished;
	}
	virtual void init() = 0;
	virtual void execute() = 0;
	virtual void end()=0;
	void run();
};

