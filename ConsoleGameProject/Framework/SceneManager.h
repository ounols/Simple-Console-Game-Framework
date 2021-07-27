#pragma once
#include "Scene.h"
#include "KeyEventManager.h"

class SceneManager
{
	Scene *m_scene = nullptr;
	KeyEventManager *m_keyMgr = nullptr;

public:
	SceneManager(KeyEventManager *keyMgr);
	~SceneManager();

	void setScene(Scene *scene) {

		if (m_scene != nullptr) {
			delete m_scene;
			m_scene = nullptr;
		}

		m_scene = scene;
		m_scene->setKeyMgr(m_keyMgr);
	}

	Scene *getScene() {
		return m_scene;
	}
};

