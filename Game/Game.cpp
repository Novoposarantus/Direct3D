#pragma once
#include "Game.h"
#include <iomanip>
#include <sstream>

Game::Game()
	:
	wnd(800, 600, "My Window"),
	width(800),
	height(600)
{}

Game::Game(int width, int height, const char* name)
	:
	wnd(width, height, name),
	width(width),
	height(height)
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
	//Pong
	/*if (wnd.Gfx().gameStop) {
		const float c = sin(timer.Peek()) / 2.0f + 0.5f;
		wnd.Gfx().ClearBuffer(c, c, 1.0f);
	}
	else
	{
		wnd.Gfx().ClearBuffer(0, 0, 0);
		wnd.Gfx().PongBlock(
			wnd.kbd.KeyIsPressed(VK_UP),
			wnd.kbd.KeyIsPressed(VK_DOWN),
			false
		);
		wnd.Gfx().PongBlock(
			wnd.kbd.KeyIsPressed('W'),
			wnd.kbd.KeyIsPressed('S'),
			true
		);

		wnd.Gfx().PongBall(timer.Peek());
	}*/
	//End Pong

	//Отрисовка треугольника
	wnd.Gfx().ClearBuffer(0, 0, 0);
	wnd.Gfx().DrawTestTriangle(timer.Peek(), wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
	
	wnd.Gfx().EndFrame();
}
