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
			assert(!"SReference�� ���� �Ұ���");
	}


	~SReferenceDoublePtr()
	{

		if (m_ptr == nullptr) return;
		if (m_size == 0) {
			assert(!"SReference�� ũ�Ⱑ �����Ǿ����� ����. �޸� ���� �߻�");
		}

		for (int i = 0; i < m_size; i++) {
			delete[] m_ptr[i];
		}

		delete[] m_ptr;
		m_ptr = nullptr;
	}

	//�������� ũ�⸦ �����մϴ�.
	void operator = (int size) {
		m_size = size;
	}
	
	//���� ����
	void operator = (const SReferenceDoublePtr<T>& other) {
		assert(!"SReference�� ���� �Ұ���");
	}

	////SReference�� �������縦 �����մϴ�.
	//void operator = (const SReference<T>& other) {
	//	m_ptr = new T;
	//	memcpy_s(m_ptr, sizeof(T), other.m_ptr, sizeof(T));
	//}

	//���ο� ��ü�� �Ҵ��� �մϴ�.
	void operator = (T** value) {
		//����ó�� - ���ο� �Ҵ�
		if (m_ptr == nullptr) {
			m_ptr = value;
			return;
		}
		//����ó�� - ��ü
		else {
			assert(!"SReference�� ���� �Ұ��� �Ǵ� SReference�� ��ü �Ұ���");
		}
	}

	void SetSize(int size) {
		m_size = size;
	}

	T** get() {
		return m_ptr;
	}
};

