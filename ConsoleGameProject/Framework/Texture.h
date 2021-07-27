#pragma once

#include <string>
#include <Windows.h>

//typedef struct tagBitmapValue {
//
//	unsigned char r, g, b = 0;
//
//	int x, y = 0;
//
//}BitmapValue;

class CTexture
{
	std::string m_fileName;
	//BitmapValue* m_bitmap = nullptr;
	HBITMAP m_hBitmap;
	BITMAP m_bitmap;
	HDC m_Hdc;
	int m_width = 0;
	int m_height = 0;

	bool isInited = false;


public:
	CTexture();
	CTexture(const CTexture& other);
	CTexture(std::string fileName);
	~CTexture();

	bool Load();

	int getWidth() const {
		return m_width;
	}

	int getHeight() const {
		return m_height;
	}

	void RenderTexture(int x, int y) const;
	
//private:
//	void LoadBitmapValue(unsigned char* image, int padding);
};