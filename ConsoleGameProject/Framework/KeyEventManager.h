#pragma once
#include <Windows.h>


class KeyEventManager
{
public:
	KeyEventManager();
	~KeyEventManager();

	BOOL KeyEventManager::isDownKey(int VK)
	{
		return GetAsyncKeyState(VK) & 0x0001;
	}

	BOOL KeyEventManager::isDownKeyAllState(int VK)
	{
		return GetAsyncKeyState(VK);
	}
};

