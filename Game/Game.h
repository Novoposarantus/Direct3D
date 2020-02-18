#pragma once
#include "Window.h"
#include "Timer.h"
#include "Camera.h"

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
	Camera cam;
	std::vector<std::unique_ptr<class Drawable>> drawables;
};