#include "Framework\MainProc.h"

#include "DemoScene.h"


#include <stdlib.h> 
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC 
#ifndef _DEBUG

#define new new(_CLIENT_BLOCK,__FILE__,__LINE)

#endif

void main() {
	//�޸� ������ Ȯ���մϴ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//���� ���ν����� ����ϴ�.
	MainProc* mainProc = new MainProc("Demo", new DemoScene());
	//�ܼ��� ũ�⸦ ���մϴ�.
	mainProc->setColsoleSize(40, 30);

	//������ ������ ���ư��� �Լ��� ȣ���մϴ�.
	mainProc->OnFrame();


	/*****ESC�� ���ӿ��� ������!*****/


	//��� ����� ������ �޸� �� �����ݴϴ�.
	delete mainProc;
}