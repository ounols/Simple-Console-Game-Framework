#pragma once
#include "Singleton.h"
#include <Windows.h>

#define WINVARMGR WinVarMgr::getInstance()

class WinVarMgr :
	public Singleton<WinVarMgr>
{
public:

	WinVarMgr()
	{
		m_hdc = GetDC(GetConsoleWindow());
	}

	~WinVarMgr()
	{
		if (m_hdc != nullptr)
			DeleteDC(m_hdc);

		ReleaseDC(GetConsoleWindow(), m_hdc);

	}

	HDC m_hdc;
};

