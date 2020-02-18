#pragma once
#include "Game.h"
#include <iomanip>
#include <sstream>

Game::Game()
	:
	wnd(800, 600, "My Window")
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
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().DrawTestTriangle(
		timer.Peek(),
		wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-wnd.mouse.GetPosY() / 300.0f + 1.0f
	);
	
	wnd.Gfx().EndFrame();
}
