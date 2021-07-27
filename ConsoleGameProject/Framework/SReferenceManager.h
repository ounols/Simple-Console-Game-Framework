#pragma once
#include <vector>

#include "Singleton.h"
#include "SReference.h"

#define SRefMgr CSReferenceManager::getInstance()

class CSReferenceManager :
	public Singleton<CSReferenceManager>
{
	std::vector<CSReference*> m_refValue;

public:
	CSReferenceManager();
	~CSReferenceManager();

	void addRef(CSReference* ref);
	void delRef(CSReference* ref);
	void increaseRef(CSReference* ref);
};

inline void CSReferenceManager::addRef(CSReference* ref)
{
	m_refValue.push_back(ref);
}

inline void CSReferenceManager::delRef(CSReference* ref)
{
	std::vector<CSReference*>::iterator iter = std::find(m_refValue.begin(), m_refValue.end(), ref);
	m_refValue.erase(iter);
}


inline void CSReferenceManager::increaseRef(CSReference * ref)
{
	std::vector<CSReference*>::iterator iter = std::find(m_refValue.begin(), m_refValue.end(), ref);
	int pos = std::distance(m_refValue.begin(), iter);
	m_refValue[pos]->
}
