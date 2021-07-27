#pragma once
#include "SceneManager.h"
#include "KeyEventManager.h"

#include "WinVarMgr.h"

class MainProc
{
	bool b_isQuit = false;
	DWORD dwStartTime = 0;
	LPCSTR m_title;

	

	KeyEventManager * m_keyMgr = nullptr;
	SceneManager * m_sceneMgr = nullptr;

public:
	MainProc(LPCSTR title, Scene *scene);
	~MainProc();

	static void setColsoleSize(int width, int height);
	void OnFrame();

	bool isQuit() {
		return b_isQuit;
	}

	KeyEventManager& getKeyMgr() {
		return *m_keyMgr;
	}

	LPCSTR getTitle() {
		return m_title;
	}


private:
	void Update(int deltaTime = 0);
	void Render(int deltaTime = 0) const;

};

