#pragma once

#include <vector>

class ReferenceManager
{

	std::vector<void*> m_reference;

public:
	ReferenceManager();
	~ReferenceManager();


	template<class T>
	T* SReference(T* value) {

		m_reference.push_back(value);

		return value;
	}

	void DeleteReference();

};

