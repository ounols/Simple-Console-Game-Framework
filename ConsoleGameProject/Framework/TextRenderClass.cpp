#include "TextRenderClass.h"



TextRenderClass::TextRenderClass()
{
}


TextRenderClass::~TextRenderClass()
{
}

TextRenderClass& operator<<(TextRenderClass& _class, std::string _string) {

	_class.m_string += _string;

	return _class;
}

TextRenderClass& operator<<(TextRenderClass& _class, int _int) {
	_class.m_string += std::to_string(_int);

	return _class;
}

TextRenderClass& operator<<(TextRenderClass& _class, float _float) {
	_class.m_string += std::to_string(_float);

	return _class;
}

TextRenderClass& operator<<(TextRenderClass& _class, double _double) {
	_class.m_string += std::to_string(_double);

	return _class;
}
