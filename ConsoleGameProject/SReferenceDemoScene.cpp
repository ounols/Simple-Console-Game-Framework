#include "SReferenceDemoScene.h"
#include <math.h>


//2. SReference의 오브젝트를 생성자에서 동적할당합니다.
SReferenceDemoScene::SReferenceDemoScene()
{
	//2.
	m_object = new CTexture("demo.bmp");

	//일반적인 포인터
	m_object2 = new CTexture("demo.bmp");
}


//4. 이 씬이 끝나면 SReference가 자동적으로 사라집니다.
SReferenceDemoScene::~SReferenceDemoScene()
{
	//자동적으로 사라지기 때문에
	//delete함수를 호출할 필요가 없음
	//delete m_object.get()

	//일반적인 포인터는
	//스스로 메모리를 해제할 수 없으므로
	//직접 메모리 해체를 해야함
	delete m_object2;
}

void SReferenceDemoScene::Update(int deltaTime)
{
	Super::Update(deltaTime);

	//코드내용

}

//3. SReference의 오브젝트를 참조하여 이미지를 그립니다.
void SReferenceDemoScene::Render(int deltaTime)
{
	Super::Render(deltaTime);

	int moveY = 140 + sinf(deltaTime / 100.f) * 100;

	//3.
	RenderBitmap(m_object.get(), moveY, 100);

	// 일반적인 포인터로 함수에 참조값 전달
	// (이미 위에서 이미지를 출력했으므로 주석처리)
	//RenderBitmap(m_object2, moveY, 100);
}
