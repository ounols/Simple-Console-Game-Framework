#include "Texture.h"
#include "WinVarMgr.h"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define PIXEL_SIZE   3    // �ȼ� �� ���� ũ�� 3����Ʈ(24��Ʈ)
#define PIXEL_ALIGN  4    // �ȼ� ������ ���� �� ���� 4�� ��� ũ��� �����



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
//	FILE *fpBmp;                    // ��Ʈ�� ���� ������
//	BITMAPFILEHEADER fileHeader;    // ���� ��� ����ü ����
//	BITMAPINFOHEADER infoHeader;    // ��Ʈ�� ���� ����ü ����
//
//	unsigned char *image;    // �ȼ� ������ ������
//	int size;                // �ȼ� ������ ũ��
//	int width, height;       // ��Ʈ�� �̹����� ����, ���� ũ��
//	int padding;             // �ȼ� �������� ���� ũ�Ⱑ 4�� ����� �ƴ� �� ���� ������ ũ��
//
//
//	fopen_s(&fpBmp, m_fileName.c_str(), "rb");    // ��Ʈ�� ������ ���̳ʸ� ���� ����
//	if (fpBmp == NULL)    // ���� ���⿡ �����ϸ�
//		return false;         // ���α׷� ����
//
//						  // ���� ��� ����ü �б�. �б⿡ �����ϸ� ���� �����͸� �ݰ� ���α׷� ����
//	if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1) {
//		fclose(fpBmp);
//		return false;
//	}
//
//	// ���� �ѹ��� MB�� �´��� Ȯ��(2����Ʈ ũ���� BM�� ��Ʋ ��������� �о����Ƿ� MB�� ��)
//	// ���� �ѹ��� ���� ������ ���α׷� ����
//	if (fileHeader.bfType != 'MB') {
//		fclose(fpBmp);
//		return false;
//	}
//
//	// ��Ʈ�� ���� ����ü �б�. �б⿡ �����ϸ� ���� �����͸� �ݰ� ���α׷� ����
//	if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1) {
//		fclose(fpBmp);
//		return false;
//	}
//
//	// 24��Ʈ ��Ʈ���� �ƴϸ� ���α׷� ����
//	if (infoHeader.biBitCount != 24) {
//		fclose(fpBmp);
//		return false;
//	}
//
//	size = infoHeader.biSizeImage;    // �ȼ� ������ ũ��
//	m_width = width = infoHeader.biWidth;       // ��Ʈ�� �̹����� ���� ũ��
//	m_height = height = infoHeader.biHeight;     // ��Ʈ�� �̹����� ���� ũ��
//
//
//	// �̹����� ���� ũ�⿡ �ȼ� ũ�⸦ ���Ͽ� ���� �� ���� ũ�⸦ ���ϰ� 4�� �������� ����
//	// �׸��� 4���� �������� ���ָ� ���� ������ ���� �� ����.
//	// ���� ���� ������ 0�̶�� ���� ����� 4�� �ǹǷ� ���⼭ �ٽ� 4�� �������� ����
//	padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;
//
//
//	if (size == 0) {    // �ȼ� ������ ũ�Ⱑ 0�̶��
//
//		// �̹����� ���� ũ�� * �ȼ� ũ�⿡ ���� ������ �����ָ� ������ ���� �� �� ũ�Ⱑ ����
//		// ���⿡ �̹����� ���� ũ�⸦ �����ָ� �ȼ� �������� ũ�⸦ ���� �� ����
//		size = (width * PIXEL_SIZE + padding) * height;
//	}
//
//	image = new unsigned char[size];    // �ȼ� �������� ũ�⸸ŭ ���� �޸� �Ҵ�
//
//	// ���� �����͸� �ȼ� �������� ���� ��ġ�� �̵�
//	fseek(fpBmp, fileHeader.bfOffBits, SEEK_SET);
//
//	// ���Ͽ��� �ȼ� ������ ũ�⸸ŭ ����. �б⿡ �����ϸ� ���� �����͸� �ݰ� ���α׷� ����
//	if (fread(image, size, 1, fpBmp) < 1) {
//
//		fclose(fpBmp);
//		return false;
//	}
//
//	fclose(fpBmp);    // ��Ʈ�� ���� �ݱ�
//
//	LoadBitmapValue(image, padding);	//��Ʈ���� ������ �о�ɴϴ�.
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
//	// �ȼ� �����ʹ� �Ʒ� ���� �������� ����ǹǷ� �Ʒ��ʺ��� �ݺ�
//	// ���� ũ�⸸ŭ �ݺ�
//	for (int y = 0; y < m_height; y++) {
//		// ���� ũ�⸸ŭ �ݺ�
//		for (int x = 0; x < m_width; x++) {
//
//			// �Ϸķ� �� �迭�� �����ϱ� ���� �ε����� ���
//			// (x * �ȼ� ũ��)�� �ȼ��� ���� ��ġ
//			// (y * (���� ũ�� * �ȼ� ũ��))�� �ȼ��� �� ��° ������ ���
//			// ���� ���� * y�� �ٺ��� ������ ���� ����
//			int index = (x * PIXEL_SIZE) + (y * (m_width * PIXEL_SIZE)) + (padding * y);
//
//			// ���� �ȼ��� �ּҸ� RGBTRIPLE �����ͷ� ��ȯ�Ͽ� RGBTRIPLE �����Ϳ� ����
//			RGBTRIPLE *pixel = (RGBTRIPLE *)&image[index];
//
//			// RGBTRIPLE ����ü�� �Ķ�, �ʷ�, �������� ������
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
