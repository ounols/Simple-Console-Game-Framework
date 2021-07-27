#pragma once
#include "Framework\Scene.h"

//SReference�� ������ �˸��� ���� �� �Դϴ�.
class SReferenceDemoScene :
	public Scene
{
	//1. Ŭ������ SRefernece�� ������Ʈ�� �����մϴ�.
	//���� : CTexture (�ֿܼ� �̹����� ���� Ŭ����)
	SReference<CTexture> m_object;

	//�Ϲ����� ������
	CTexture* m_object2;

public:
	//2. SReference�� ������Ʈ�� �����ڿ��� �����Ҵ��մϴ�.
	SReferenceDemoScene();

	//4. �� ���� ������ SReference�� �ڵ������� ������ϴ�.
	~SReferenceDemoScene();

	
	void Update(int deltaTime) override;
	//3. SReference�� ������Ʈ�� �����Ͽ� �̹����� �׸��ϴ�.
	void Render(int deltaTime) override;
};

