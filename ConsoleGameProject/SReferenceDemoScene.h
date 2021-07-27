#pragma once
#include "Framework\Scene.h"

//SReference의 사용법을 알리는 데모 씬 입니다.
class SReferenceDemoScene :
	public Scene
{
	//1. 클래스에 SRefernece로 오브젝트를 선언합니다.
	//예시 : CTexture (콘솔에 이미지를 띄우는 클래스)
	SReference<CTexture> m_object;

	//일반적인 포인터
	CTexture* m_object2;

public:
	//2. SReference의 오브젝트를 생성자에서 동적할당합니다.
	SReferenceDemoScene();

	//4. 이 씬이 끝나면 SReference가 자동적으로 사라집니다.
	~SReferenceDemoScene();

	
	void Update(int deltaTime) override;
	//3. SReference의 오브젝트를 참조하여 이미지를 그립니다.
	void Render(int deltaTime) override;
};

