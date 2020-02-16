#pragma once
#include "Window.h"
#include "Timer.h"

class Game
{
public:
	Game();
	Game(int width, int height, const char* name);
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
};