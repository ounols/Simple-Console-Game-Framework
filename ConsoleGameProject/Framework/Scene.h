#pragma once
#include "KeyEventManager.h"
#include "Texture.h"
#include "SReference.h"
#include "TextRenderClass.h"

#define Super __super
#define KEY m_keyMgr
#define tout m_textRenderClass

class Scene
{
	bool b_isChange = false;
	Scene *m_changeScene = nullptr;
	//ReferenceManager* m_referenceMgr = nullptr;

protected:
	KeyEventManager *m_keyMgr = nullptr;
	TextRenderClass m_textRenderClass;

public:
	//생성자 (Super함수를 반드시 사용해야 함)
	Scene();
	virtual ~Scene();

	virtual void Update(int deltaTime = 0);
	virtual void Render(int deltaTime = 0);

	bool isChange() const {
		return b_isChange;
	}

	Scene* getChangeScene() const {
		return m_changeScene;
	}

	void delChangeScene() {
		delete m_changeScene;
		m_changeScene = nullptr;
	}

	void setKeyMgr(KeyEventManager *keyMgr) {
		m_keyMgr = keyMgr;
	}

protected:
	static void RenderText(int x, int y, char *string);
	static void RenderText(int x, int y, std::string string);
	static void RenderText(int x, int y, TextRenderClass& _class);
	static void RenderBitmap(const CTexture* bitmap, int x, int y);
	static void setColor(unsigned short color);

	//Scene을 교체합니다.
	void setScene(Scene *scene);

};
