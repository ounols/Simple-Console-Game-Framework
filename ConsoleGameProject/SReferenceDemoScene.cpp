#include "SReferenceDemoScene.h"
#include <math.h>


//2. SReference�� ������Ʈ�� �����ڿ��� �����Ҵ��մϴ�.
SReferenceDemoScene::SReferenceDemoScene()
{
	//2.
	m_object = new CTexture("demo.bmp");

	//�Ϲ����� ������
	m_object2 = new CTexture("demo.bmp");
}


//4. �� ���� ������ SReference�� �ڵ������� ������ϴ�.
SReferenceDemoScene::~SReferenceDemoScene()
{
	//�ڵ������� ������� ������
	//delete�Լ��� ȣ���� �ʿ䰡 ����
	//delete m_object.get()

	//�Ϲ����� �����ʹ�
	//������ �޸𸮸� ������ �� �����Ƿ�
	//���� �޸� ��ü�� �ؾ���
	delete m_object2;
}

void SReferenceDemoScene::Update(int deltaTime)
{
	Super::Update(deltaTime);

	//�ڵ峻��

}

//3. SReference�� ������Ʈ�� �����Ͽ� �̹����� �׸��ϴ�.
void SReferenceDemoScene::Render(int deltaTime)
{
	Super::Render(deltaTime);

	int moveY = 140 + sinf(deltaTime / 100.f) * 100;

	//3.
	RenderBitmap(m_object.get(), moveY, 100);

	// �Ϲ����� �����ͷ� �Լ��� ������ ����
	// (�̹� ������ �̹����� ��������Ƿ� �ּ�ó��)
	//RenderBitmap(m_object2, moveY, 100);
}
