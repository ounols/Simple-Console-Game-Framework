#pragma once
#include "Framework\Scene.h"
class DemoScene :
	public Scene
{
	bool b_isPressed = false;

public:
	//������
	DemoScene();
	//�Ҹ���
	~DemoScene();

	//������Ʈ
	void Update(int deltaTime) override;
	//������
	void Render(int deltaTime) override;
};

