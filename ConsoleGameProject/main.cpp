#include "Framework\MainProc.h"

#include "DemoScene.h"


#include <stdlib.h> 
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC 
#ifndef _DEBUG

#define new new(_CLIENT_BLOCK,__FILE__,__LINE)

#endif

void main() {
	//메모리 누수를 확인합니다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//메인 프로시저를 만듭니다.
	MainProc* mainProc = new MainProc("Demo", new DemoScene());
	//콘솔의 크기를 정합니다.
	mainProc->setColsoleSize(40, 30);

	//게임의 루프가 돌아가는 함수를 호출합니다.
	mainProc->OnFrame();


	/*****ESC는 게임에서 나가기!*****/


	//모든 사용이 끝나면 메모리 상에 지워줍니다.
	delete mainProc;
}