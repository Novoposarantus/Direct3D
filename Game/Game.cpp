#include "Game.h"
#include "Box.h"
#include "Box2.h"
#include <memory>
#include "CameraChangeEnum.h"

const float cameraSpeed = 0.1f;

Game::Game()
	:
	wnd(800, 600, "My Window")
{
	drawables.push_back(new Box(
		wnd.Gfx(), 
		7,
		0, //вокруг себя
		2, //вокруг себя
		0, //вокруг себя
		-1, //вокруг цента
		0, //вокруг цента
		0, //вокруг цента
		0, //начальное значение воруг центра
		1, 
		0, 
		1, //размер по X
		1, //размер по Y
		1  //размер по Z
	));
	drawables.push_back(new Box(
		wnd.Gfx(),
		0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 5, 5, 5
		));
	drawables.push_back(new Box(
		wnd.Gfx(),
		9, 0, 1, 1, 1, -2, 0, 0, 0, 0, 2, 2, 2
		));
	drawables.push_back(new Box(
		wnd.Gfx(),
		12, 0, 0, 1, 0, 0, -2, 0, 0, 0, 2, 2, 2
		));
	Drawable* parent = new Box(
		wnd.Gfx(),
		16, 0, 1, 1, 0.5, 0, 0, 0, 0, 0, 3, 3, 3
		);
	drawables.push_back(parent);
	drawables.push_back(new Box2(
		wnd.Gfx(),
		4, 0, 1, 1, 4, 0, 0, 0, 0, 0, 2, 2, 2, parent
		));
	cam.AdjustPosition(cam.GetBackwardVector() * 25);
	cam.AdjustPosition(0.0f, 8, 0.0f);
	cam.AdjustRotation(0.5, 0, 0);
	wnd.Gfx().SetProjection(DirectX::XMMatrixPerspectiveLH(1.0f, 3.0f / 4.0f, 0.5f, 40.0f));
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

Game::~Game()
{}

void Game::DoFrame()
{
	wnd.Gfx().ClearBuffer(0.07f, 0.0f, 0.12f);
#pragma region CameraUpdate

	CHE_VALUES cheValues = {};
	auto dt = timer.Mark();

	if (wnd.kbd.KeyIsPressed('W')) 
	{
		cam.AdjustPosition(cam.GetForwardVector() * cameraSpeed);
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		cam.AdjustPosition(cam.GetBackwardVector() * cameraSpeed);
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		cam.AdjustPosition(cam.GetLeftVector() * cameraSpeed);
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		cam.AdjustPosition(cam.GetRightVector() * cameraSpeed);
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		cam.AdjustRotation( -0.01f, 0, 0);
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		cam.AdjustRotation(0.01f, 0, 0);
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		cam.AdjustRotation(0, -0.01f, 0);
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		cam.AdjustRotation(0, 0.01f, 0);
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		cam.AdjustPosition(0.0f, cameraSpeed, 0.0f);
	}
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		cam.AdjustPosition(0.0f, -cameraSpeed, 0.0f);
	}
	wnd.Gfx().SetCamera(cam.GetViewMatrix());
#pragma endregion CameraUpdate

	for (auto& b : drawables)
	{
		b->Update(dt);
		b->Draw(wnd.Gfx());
	}
	wnd.Gfx().EndFrame();
}