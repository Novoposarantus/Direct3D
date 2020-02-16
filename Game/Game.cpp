#pragma once
#include "Game.h"
#include <iomanip>
#include <sstream>

Game::Game()
	:
	wnd(800, 600, "My Window")
{}

Game::Game(int width, int height, const char* name)
	:
	wnd(width, height, name)
{
}

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
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().DrawTestTriangle();
	wnd.Gfx().EndFrame();
}
