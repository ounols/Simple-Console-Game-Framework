#pragma once

#include <assert.h>

template <class T>
class SReferenceDoublePtr
{
public:

	T** m_ptr = nullptr;
	int m_size = 0;

public:
	SReferenceDoublePtr() {}

	SReferenceDoublePtr(int size) {
		m_size = size;
	}

	SReferenceDoublePtr(T** ptr)
	{
		if (m_ptr == nullptr)
			m_ptr = ptr;
		else
			assert(!"SReference의 복사 불가능");
	}


	~SReferenceDoublePtr()
	{

		if (m_ptr == nullptr) return;
		if (m_size == 0) {
			assert(!"SReference의 크기가 지정되어있지 않음. 메모리 누수 발생");
		}

		for (int i = 0; i < m_size; i++) {
			delete[] m_ptr[i];
		}

		delete[] m_ptr;
		m_ptr = nullptr;
	}

	//포인터의 크기를 설정합니다.
	void operator = (int size) {
		m_size = size;
	}
	
	//복사 금지
	void operator = (const SReferenceDoublePtr<T>& other) {
		assert(!"SReference의 복사 불가능");
	}

	////SReference의 깊은복사를 진행합니다.
	//void operator = (const SReference<T>& other) {
	//	m_ptr = new T;
	//	memcpy_s(m_ptr, sizeof(T), other.m_ptr, sizeof(T));
	//}

	//새로운 객체를 할당을 합니다.
	void operator = (T** value) {
		//예외처리 - 새로운 할당
		if (m_ptr == nullptr) {
			m_ptr = value;
			return;
		}
		//예외처리 - 교체
		else {
			assert(!"SReference의 복사 불가능 또는 SReference를 교체 불가능");
		}
	}

	void SetSize(int size) {
		m_size = size;
	}

	T** get() {
		return m_ptr;
	}
};

