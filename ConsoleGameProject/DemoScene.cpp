#include "DemoScene.h"

#include "SReferenceDemoScene.h"



DemoScene::DemoScene()
{
	//생성자
}


DemoScene::~DemoScene()
{
	//소멸자
}

void DemoScene::Update(int deltaTime)
{
	Super::Update(deltaTime);
	
	//코드내용

	//키보드가 눌렸을 때 발생하는 이벤트
	//엔터키를 누르거나 R을 눌렀을 때
	if (KEY->isDownKey(VK_RETURN) ||
		KEY->isDownKey(VkKeyScanA('r'))) {
		b_isPressed = true;

	}


	//씬 전환하는 방법!
	//5000밀리초 (5초)가 지나면 씬이 전환되도록
	if(deltaTime > 5000)
		setScene(new SReferenceDemoScene());

}

void DemoScene::Render(int deltaTime)
{
	Super::Render(deltaTime);

	//코드내용
	RenderText(15, deltaTime/1000, "안녕? 내이름은 신도하!");

	if (b_isPressed) {
		//RenderText(20, 10, "엔터나 R키를 눌러주었군!");
		RenderText(20, 10, tout << "엔터나" << " R키를 눌러주었군!" << 123 << 123.3);
	}
}
