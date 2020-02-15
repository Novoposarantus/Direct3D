#pragma once
#include "Game.h"
#include <iomanip>
#include <sstream>

Game::Game()
	:
	wnd(800,600, "My Window")
{}

int Game::Go()
{
	while (true)
	{
		int code;
		if ((code = Window::ProcessMessages()) < 0) {
			return code;
		}
		DoFrame();
	}
}

void Game::DoFrame()
{
}