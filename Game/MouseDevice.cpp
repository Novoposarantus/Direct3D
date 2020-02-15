#include "SystemWin.h"
#include "MouseDevice.h"


std::pair<int, int> MouseDevice::GetPos() const noexcept
{
	return { x,y };
}

MouseDevice::RawDelta MouseDevice::ReadRawDelta() noexcept
{
	const RawDelta d = rawDeltaBuffer.front();
	rawDeltaBuffer.pop();
	return d;
}

int MouseDevice::GetPosX() const noexcept
{
	return x;
}

int MouseDevice::GetPosY() const noexcept
{
	return y;
}

bool MouseDevice::IsInWindow() const noexcept
{
	return isInWindow;
}

bool MouseDevice::LeftIsPressed() const noexcept
{
	return leftIsPressed;
}

bool MouseDevice::RightIsPressed() const noexcept
{
	return rightIsPressed;
}

MouseDevice::Event MouseDevice::Read() noexcept
{
	if (buffer.size() > 0u)
	{
		MouseDevice::Event e = buffer.front();
		buffer.pop();
		return e;
	}
}

void MouseDevice::Flush() noexcept
{
	buffer = std::queue<Event>();
}

void MouseDevice::EnableRaw() noexcept
{
	rawEnabled = true;
}

void MouseDevice::DisableRaw() noexcept
{
	rawEnabled = false;
}

bool MouseDevice::RawEnabled() const noexcept
{
	return rawEnabled;
}

void MouseDevice::OnMouseMove(int newx, int newy) noexcept
{
	x = newx;
	y = newy;

	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::Move, *this));
	TrimBuffer();
}

void MouseDevice::OnMouseLeave() noexcept
{
	isInWindow = false;
	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::Leave, *this));
	TrimBuffer();
}

void MouseDevice::OnMouseEnter() noexcept
{
	isInWindow = true;
	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::Enter, *this));
	TrimBuffer();
}

void MouseDevice::OnRawDelta(int dx, int dy) noexcept
{
	rawDeltaBuffer.push({ dx,dy });
	TrimBuffer();
}

void MouseDevice::OnLeftPressed(int x, int y) noexcept
{
	leftIsPressed = true;

	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::LPress, *this));
	TrimBuffer();
}

void MouseDevice::OnLeftReleased(int x, int y) noexcept
{
	leftIsPressed = false;

	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::LRelease, *this));
	TrimBuffer();
}

void MouseDevice::OnRightPressed(int x, int y) noexcept
{
	rightIsPressed = true;

	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::RPress, *this));
	TrimBuffer();
}

void MouseDevice::OnRightReleased(int x, int y) noexcept
{
	rightIsPressed = false;

	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::RRelease, *this));
	TrimBuffer();
}

void MouseDevice::OnWheelUp(int x, int y) noexcept
{
	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::WheelUp, *this));
	TrimBuffer();
}

void MouseDevice::OnWheelDown(int x, int y) noexcept
{
	buffer.push(MouseDevice::Event(MouseDevice::Event::Type::WheelDown, *this));
	TrimBuffer();
}

void MouseDevice::TrimBuffer() noexcept
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}

void MouseDevice::TrimRawInputBuffer() noexcept
{
	while (rawDeltaBuffer.size() > bufferSize)
	{
		rawDeltaBuffer.pop();
	}
}

void MouseDevice::OnWheelDelta(int x, int y, int delta) noexcept
{
	wheelDeltaCarry += delta;
	// generate events for every 120 
	while (wheelDeltaCarry >= WHEEL_DELTA)
	{
		wheelDeltaCarry -= WHEEL_DELTA;
		OnWheelUp(x, y);
	}
	while (wheelDeltaCarry <= -WHEEL_DELTA)
	{
		wheelDeltaCarry += WHEEL_DELTA;
		OnWheelDown(x, y);
	}
}