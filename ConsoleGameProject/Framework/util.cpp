#include "util.h"
#include <Windows.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

void gotoxy(int x, int y)
{
	COORD CursorPosition = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}


 
void ScreenInit()
{
     CONSOLE_CURSOR_INFO cci;
        
     // 화면 버퍼 2개를 만든다.
     g_hScreen[0] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0,
                                            NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
     g_hScreen[1] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0,
                                            NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
 
     // 커서 숨기기
     cci.dwSize = 1;
     cci.bVisible = FALSE;
     SetConsoleCursorInfo( g_hScreen[0], &cci );
     SetConsoleCursorInfo( g_hScreen[1], &cci );
}
 
void ScreenFlipping()
{               
     SetConsoleActiveScreenBuffer( g_hScreen[g_nScreenIndex] );    
     g_nScreenIndex = !g_nScreenIndex; 
}
 
void ScreenClear()
{               
     COORD Coor = { 0, 0 };
     DWORD dw;
     FillConsoleOutputCharacter( g_hScreen[g_nScreenIndex], ' ', 5000, Coor, &dw );
}
 
void ScreenRelease()
{
     CloseHandle( g_hScreen[0] );
     CloseHandle( g_hScreen[1] );
}
 
void ScreenPrint( int x, int y, char *string )
{
     DWORD dw;
     COORD CursorPosition = { x, y };
     SetConsoleCursorPosition( g_hScreen[g_nScreenIndex], CursorPosition );    
     WriteFile( g_hScreen[g_nScreenIndex], string, strlen( string ), &dw, NULL );
}
// 1 ~ 15 까지 색상 설정 가능
void SetColor( unsigned short color )
{               
     SetConsoleTextAttribute( g_hScreen[g_nScreenIndex], color );
}

void SetConsoleWindowSize(const int& width,const int& height)
{
	SMALL_RECT rectTmp;
	COORD size = {width, height};
	rectTmp.Left = rectTmp.Top = 0;
	rectTmp.Bottom = height - 1;
	rectTmp.Right = width - 1;

	SetConsoleScreenBufferSize(g_hScreen[0], size);
	SetConsoleScreenBufferSize(g_hScreen[1], size);

	SetConsoleWindowInfo(g_hScreen[0], TRUE, &rectTmp);
	SetConsoleWindowInfo(g_hScreen[1], TRUE, &rectTmp);
}
