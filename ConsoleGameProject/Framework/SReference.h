#pragma once

#include <assert.h>

template<class T>
class SReference
{

	T* m_ptr = nullptr;

public:
	SReference() {}
	SReference(T* ptr)
	{
		if (m_ptr == nullptr)
			m_ptr = ptr;
		else
			assert(!"SReference의 복사 불가능");
	}


	virtual ~SReference()
	{

		if (m_ptr != nullptr) {
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

	//복사 금지
	void operator = (const SReference<T>& other) {
		assert(!"SReference의 복사 불가능");
	}

	////SReference의 깊은복사를 진행합니다.
	//void operator = (const SReference<T>& other) {
	//	m_ptr = new T;
	//	memcpy_s(m_ptr, sizeof(T), other.m_ptr, sizeof(T));
	//}

	//새로운 객체를 할당을 합니다.
	void operator = (T* value) {
		//예외처리 - 새로운 할당
		if (m_ptr == nullptr) {
			m_ptr = value;
			return;
		}
		//예외처리 - 교체
		else {
			assert(!"SReference의 복사 불가능");
			assert(!"또는 SReference를 교체 불가능");
		}
	}

	T* get() {
		return m_ptr;
	}



};

template <class T>
class SReferenceArray 
	: public SReference<T>
{
	SReferenceArray() {}

	~SReferenceArray() {
		if (m_ptr != nullptr) {
			delete[] m_ptr;
			m_ptr = nullptr;
		}
	}


};

