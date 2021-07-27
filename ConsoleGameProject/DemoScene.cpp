#include "DemoScene.h"

#include "SReferenceDemoScene.h"



DemoScene::DemoScene()
{
	//������
}


DemoScene::~DemoScene()
{
	//�Ҹ���
}

void DemoScene::Update(int deltaTime)
{
	Super::Update(deltaTime);
	
	//�ڵ峻��

	//Ű���尡 ������ �� �߻��ϴ� �̺�Ʈ
	//����Ű�� �����ų� R�� ������ ��
	if (KEY->isDownKey(VK_RETURN) ||
		KEY->isDownKey(VkKeyScanA('r'))) {
		b_isPressed = true;

	}


	//�� ��ȯ�ϴ� ���!
	//5000�и��� (5��)�� ������ ���� ��ȯ�ǵ���
	if(deltaTime > 5000)
		setScene(new SReferenceDemoScene());

}

void DemoScene::Render(int deltaTime)
{
	Super::Render(deltaTime);

	//�ڵ峻��
	RenderText(15, deltaTime/1000, "�ȳ�? ���̸��� �ŵ���!");

	if (b_isPressed) {
		//RenderText(20, 10, "���ͳ� RŰ�� �����־���!");
		RenderText(20, 10, tout << "���ͳ�" << " RŰ�� �����־���!" << 123 << 123.3);
	}
}
