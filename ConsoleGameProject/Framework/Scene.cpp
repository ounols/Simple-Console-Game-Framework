#include "util.h"
#include "SceneManager.h"
#include <iostream>

Scene::Scene()
{
	//m_referenceMgr = new ReferenceManager();
}


Scene::~Scene()
{
	//delete m_referenceMgr;
}

void Scene::Update(int deltaTime)
{
	if(!m_textRenderClass.m_string.empty()) {
		m_textRenderClass.m_string.clear();
	}
}

void Scene::Render(int deltaTime)
{
}

void Scene::RenderText(int x, int y, char * string)
{
	ScreenPrint(x, y, string);
}

void Scene::RenderText(int x, int y, std::string string) {

	ScreenPrint(x, y, const_cast<char*>(string.c_str()));

}

void Scene::RenderText(int x, int y, TextRenderClass& _class) {

	RenderText(x, y, _class.m_string);
}

void Scene::RenderBitmap(const CTexture * bitmap, int x, int y)
{
	bitmap->RenderTexture(x, y);
}

void Scene::setColor(unsigned short color)
{
	SetColor(color);
}

void Scene::setScene(Scene *scene)
{
	b_isChange = true;
	m_changeScene = scene;
}
