#include <Windows.h>
#include <string>
#include "MainProc.h"
#include "util.h"
#include "KeyEventManager.h"

#define GET_HINSTANCE(hwnd)    ((HINSTANCE)::GetWindowLong((hwnd), GWL_HINSTANCE))

#pragma comment( lib, "winmm.lib" )

MainProc::MainProc(LPCSTR title, Scene *scene)
{
	ScreenInit();

	m_title = title;

	std::string tmp = "title ";
	tmp += title;

	system(tmp.c_str());

	dwStartTime = timeGetTime();

	m_keyMgr = new KeyEventManager();
	m_sceneMgr = new SceneManager(m_keyMgr);
	m_sceneMgr->setScene(scene);
}


MainProc::~MainProc()
{
	WINVARMGR->delInstance();

	b_isQuit = true;
	ScreenRelease();
	delete m_keyMgr;
	delete m_sceneMgr;
}

void MainProc::setColsoleSize(int width, int height)
{
	SetConsoleWindowSize(width * 2, height);
}

void MainProc::OnFrame()
{
	while (!b_isQuit) {
		DWORD dwDeltaTime = timeGetTime() - dwStartTime;

		Update(dwDeltaTime);
		Render(dwDeltaTime);

	}

}

void MainProc::Update(int deltaTime)
{
	
	b_isQuit = m_keyMgr->isDownKey(VK_ESCAPE);

	Scene* sceneTmp = m_sceneMgr->getScene();
	if (sceneTmp->isChange()) {
		m_sceneMgr->setScene(sceneTmp->getChangeScene());
	}
	else {
		sceneTmp->Update(deltaTime);
	}

}

void MainProc::Render(int deltaTime) const {

	ScreenFlipping();
	ScreenClear();
	
	m_sceneMgr->getScene()->Render(deltaTime);

	

}
