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
			assert(!"SReference�� ���� �Ұ���");
	}


	virtual ~SReference()
	{

		if (m_ptr != nullptr) {
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

	//���� ����
	void operator = (const SReference<T>& other) {
		assert(!"SReference�� ���� �Ұ���");
	}

	////SReference�� �������縦 �����մϴ�.
	//void operator = (const SReference<T>& other) {
	//	m_ptr = new T;
	//	memcpy_s(m_ptr, sizeof(T), other.m_ptr, sizeof(T));
	//}

	//���ο� ��ü�� �Ҵ��� �մϴ�.
	void operator = (T* value) {
		//����ó�� - ���ο� �Ҵ�
		if (m_ptr == nullptr) {
			m_ptr = value;
			return;
		}
		//����ó�� - ��ü
		else {
			assert(!"SReference�� ���� �Ұ���");
			assert(!"�Ǵ� SReference�� ��ü �Ұ���");
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

