#include "Texture.h"
#include "WinVarMgr.h"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define PIXEL_SIZE   3    // 픽셀 한 개의 크기 3바이트(24비트)
#define PIXEL_ALIGN  4    // 픽셀 데이터 가로 한 줄은 4의 배수 크기로 저장됨



CTexture::CTexture()
{

}

CTexture::CTexture(const CTexture & other) : m_fileName(other.m_fileName)
{

	m_width = other.m_width;
	m_height = other.m_height;

}

CTexture::CTexture(std::string fileName) : m_fileName(fileName)
{
	Load();
}

CTexture::~CTexture()
{
	DeleteDC(m_Hdc);
	DeleteObject(m_hBitmap);
}

bool CTexture::Load()
{
	m_Hdc = CreateCompatibleDC(WINVARMGR->m_hdc);
	m_hBitmap = (HBITMAP)LoadImageA(NULL, m_fileName.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(m_hBitmap, sizeof(BITMAP), &m_bitmap);
	SelectObject(m_Hdc, m_hBitmap);

	m_width = m_bitmap.bmWidth;
	m_height = m_bitmap.bmHeight;

	return true;
}

void CTexture::RenderTexture(int x, int y) const
{
	BitBlt(WINVARMGR->m_hdc, x, y, m_width, m_height, m_Hdc, 0, 0, SRCCOPY);
}



//bool CTexture::Load()
//{
//	FILE *fpBmp;                    // 비트맵 파일 포인터
//	BITMAPFILEHEADER fileHeader;    // 파일 헤더 구조체 변수
//	BITMAPINFOHEADER infoHeader;    // 비트맵 정보 구조체 변수
//
//	unsigned char *image;    // 픽셀 데이터 포인터
//	int size;                // 픽셀 데이터 크기
//	int width, height;       // 비트맵 이미지의 가로, 세로 크기
//	int padding;             // 픽셀 데이터의 가로 크기가 4의 배수가 아닐 때 남는 공간의 크기
//
//
//	fopen_s(&fpBmp, m_fileName.c_str(), "rb");    // 비트맵 파일을 바이너리 모드로 열기
//	if (fpBmp == NULL)    // 파일 열기에 실패하면
//		return false;         // 프로그램 종료
//
//						  // 파일 헤더 구조체 읽기. 읽기에 실패하면 파일 포인터를 닫고 프로그램 종료
//	if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1) {
//		fclose(fpBmp);
//		return false;
//	}
//
//	// 매직 넘버가 MB가 맞는지 확인(2바이트 크기의 BM을 리틀 엔디언으로 읽었으므로 MB가 됨)
//	// 매직 넘버가 맞지 않으면 프로그램 종료
//	if (fileHeader.bfType != 'MB') {
//		fclose(fpBmp);
//		return false;
//	}
//
//	// 비트맵 정보 구조체 읽기. 읽기에 실패하면 파일 포인터를 닫고 프로그램 종료
//	if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1) {
//		fclose(fpBmp);
//		return false;
//	}
//
//	// 24비트 비트맵이 아니면 프로그램 종료
//	if (infoHeader.biBitCount != 24) {
//		fclose(fpBmp);
//		return false;
//	}
//
//	size = infoHeader.biSizeImage;    // 픽셀 데이터 크기
//	m_width = width = infoHeader.biWidth;       // 비트맵 이미지의 가로 크기
//	m_height = height = infoHeader.biHeight;     // 비트맵 이미지의 세로 크기
//
//
//	// 이미지의 가로 크기에 픽셀 크기를 곱하여 가로 한 줄의 크기를 구하고 4로 나머지를 구함
//	// 그리고 4에서 나머지를 빼주면 남는 공간을 구할 수 있음.
//	// 만약 남는 공간이 0이라면 최종 결과가 4가 되므로 여기서 다시 4로 나머지를 구함
//	padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
//
//
//	if (size == 0) {    // 픽셀 데이터 크기가 0이라면
//
//		// 이미지의 가로 크기 * 픽셀 크기에 남는 공간을 더해주면 완전한 가로 한 줄 크기가 나옴
//		// 여기에 이미지의 세로 크기를 곱해주면 픽셀 데이터의 크기를 구할 수 있음
//		size = (width * PIXEL_SIZE + padding) * height;
//	}
//
//	image = new unsigned char[size];    // 픽셀 데이터의 크기만큼 동적 메모리 할당
//
//	// 파일 포인터를 픽셀 데이터의 시작 위치로 이동
//	fseek(fpBmp, fileHeader.bfOffBits, SEEK_SET);
//
//	// 파일에서 픽셀 데이터 크기만큼 읽음. 읽기에 실패하면 파일 포인터를 닫고 프로그램 종료
//	if (fread(image, size, 1, fpBmp) < 1) {
//
//		fclose(fpBmp);
//		return false;
//	}
//
//	fclose(fpBmp);    // 비트맵 파일 닫기
//
//	LoadBitmapValue(image, padding);	//비트맵의 색깔을 읽어옵니다.
//
//	delete[] image;
//
//	isInited = true;
//	return true;
//}

//void CTexture::RenderTexture(int x, int y) const
//{
//	HDC hdc = GetDC(m_hWnd);
//
//	for (int index = 0; index < m_width * m_height; index++) {
//
//		SetPixelV(hdc, m_bitmap[index].x, m_bitmap[index].y,
//			RGB(m_bitmap[index].r, m_bitmap[index].g,
//				m_bitmap[index].b));
//
//	}
//
//	ReleaseDC(m_hWnd, hdc);
//}

//void CTexture::LoadBitmapValue(unsigned char* image, int padding)
//{
//	m_bitmap = new BitmapValue[m_width * m_height];
//
//	int index_s = 0;
//
//	// 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복
//	// 세로 크기만큼 반복
//	for (int y = 0; y < m_height; y++) {
//		// 가로 크기만큼 반복
//		for (int x = 0; x < m_width; x++) {
//
//			// 일렬로 된 배열에 접근하기 위해 인덱스를 계산
//			// (x * 픽셀 크기)는 픽셀의 가로 위치
//			// (y * (세로 크기 * 픽셀 크기))는 픽셀이 몇 번째 줄인지 계산
//			// 남는 공간 * y는 줄별로 누적된 남는 공간
//			int index = (x * PIXEL_SIZE) + (y * (m_width * PIXEL_SIZE)) + (padding * y);
//
//			// 현재 픽셀의 주소를 RGBTRIPLE 포인터로 변환하여 RGBTRIPLE 포인터에 저장
//			RGBTRIPLE *pixel = (RGBTRIPLE *)&image[index];
//
//			// RGBTRIPLE 구조체로 파랑, 초록, 빨강값을 가져옴
//			unsigned char blue = pixel->rgbtBlue;
//			unsigned char green = pixel->rgbtGreen;
//			unsigned char red = pixel->rgbtRed;
//
//			m_bitmap[index_s].r = red;
//			m_bitmap[index_s].g = green;
//			m_bitmap[index_s].b = blue;
//			m_bitmap[index_s].x = x;
//			m_bitmap[index_s].y = y;
//
//			index_s++;
//		}
//
//	}
//}
