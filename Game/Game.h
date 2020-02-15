#pragma once
#include "Window.h"
#include "Timer.h"

class Game
{
public:
	Game();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
};