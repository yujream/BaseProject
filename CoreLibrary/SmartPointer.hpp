#ifndef __SMART_POINTER_H__
#define __SMART_POINTER_H__

#include "Core.h"

BEGIN_NAMESPACE
template<class T>
class SmartPointer final
{
public:
	SmartPointer();
	SmartPointer(T* Pointer);
	~SmartPointer();

	T* operator->() const;
	T& operator*() const;           // ����������Ϊ�˱��⿽��

	// ת��Ϊbool���ͣ����ڱ��ʽ�ж�
	explicit operator bool() const;


private:
	T* BindPointer;
};

template <class T>
SmartPointer<T>::SmartPointer()
	: BindPointer(nullptr)
{
}

template <class T>
SmartPointer<T>::SmartPointer(T* Pointer)
{
	BindPointer = Pointer;
}

template <class T>
SmartPointer<T>::~SmartPointer()
{
	if (nullptr != BindPointer)
	{
		delete BindPointer;
	}
}

template <class T>
T* SmartPointer<T>::operator->() const
{
	return BindPointer;
}

template <class T>
T& SmartPointer<T>::operator*() const
{
	return *BindPointer;
}

template <class T>
SmartPointer<T>::operator bool() const
{
	return BindPointer != nullptr;
}

END_NAMESPACE

#endif
