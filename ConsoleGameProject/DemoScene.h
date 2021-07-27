#pragma once
#include "Framework\Scene.h"
class DemoScene :
	public Scene
{
	bool b_isPressed = false;

public:
	//생성자
	DemoScene();
	//소멸자
	~DemoScene();

	//업데이트
	void Update(int deltaTime) override;
	//렌더링
	void Render(int deltaTime) override;
};

