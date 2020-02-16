#include "SystemWin.h";
#include "Triangle.h"

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow)
{
	try
	{
		return Triangle{}.Go();
	}
	catch (const GameException & e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK
			| MB_ICONEXCLAMATION);
	}
	catch (const std::exception & e)
	{
		MessageBox(nullptr, e.what(), "Standart Exception", MB_OK
			| MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknawn Exception", MB_OK
			| MB_ICONEXCLAMATION);
	}

	return -1;
}