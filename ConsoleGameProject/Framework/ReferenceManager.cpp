#include "ReferenceManager.h"



ReferenceManager::ReferenceManager()
{
}


ReferenceManager::~ReferenceManager()
{
	DeleteReference();
	
}

void ReferenceManager::DeleteReference()
{
	if (m_reference.empty()) return;

	for (int i = m_reference.size() - 1; i >= 0; i--) {
		delete[] m_reference[i];
		m_reference.pop_back();
	}
}
