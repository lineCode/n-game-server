#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include "stdlib.h"

template <typename T>
class Singleton
{
public:
	Singleton() { }
	virtual ~Singleton() { }

	static T* Instance()
	{
		static T m_instance;
		return &m_instance;
	}
};

//template <typename T>
//class Singleton
//{
//public:
//	Singleton() { }
//	virtual ~Singleton() { }
//
//	static T* Instance()
//	{
//		if (NULL == m_instance)
//		{
//			m_instance = new T;
//		}
//		return m_instance;
//	}
//	static void Destroy()
//	{
//		if (NULL != m_instance)
//		{
//			delete m_instance;
//		}
//	}
//private:
//	static T* m_instance;
//};

#endif
