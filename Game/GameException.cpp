#include "GameException.h";
#include <sstream>

GameException::GameException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* GameException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* GameException::GetType() const noexcept
{
	return "Game Exception";
}

int GameException::GetLine() const noexcept
{
	return line;
}

const std::string& GameException::GetFile() const noexcept
{
	return file;
}

std::string GameException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File ]" << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
