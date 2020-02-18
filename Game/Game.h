#pragma once
#include "Window.h"
#include "Timer.h"

class Game
{
public:
	Game();
	int Go();
	~Game();
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};