#pragma once

#include <string>

class TextRenderClass
{
public:
	TextRenderClass();
	~TextRenderClass();

	friend TextRenderClass& operator<<(TextRenderClass& _class, std::string _string);
	friend TextRenderClass& operator<<(TextRenderClass& _class, int _int);
	friend TextRenderClass& operator<<(TextRenderClass& _class, float _float);
	friend TextRenderClass& operator<<(TextRenderClass& _class, double _double);




	std::string m_string;
};

