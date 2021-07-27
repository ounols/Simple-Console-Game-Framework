#include "SceneManager.h"



SceneManager::SceneManager(KeyEventManager *keyMgr)
{
	m_keyMgr = keyMgr;
}


SceneManager::~SceneManager()
{
	if (m_scene->getChangeScene() != nullptr) {
		m_scene->delChangeScene();
	}
	delete m_scene;
}
