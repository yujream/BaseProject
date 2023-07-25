#include <iostream>

#include "ReferenceCounterManager.h"
#include "SmartPointer.hpp"

using namespace std;

class Test
{
public:
	Test() { cout << "Construct" << endl; }
	~Test() { cout << "Deconstruct" << endl; }

	void Print() { cout << "Hello" << endl; }
};

int main()
{
	yujream::SmartPointer<Test> Ptr(new Test());
	Ptr->Print();
	if (Ptr)
	{
		(*Ptr).Print();
	}

	int* pa = new int;
	ReferenceCounterManager::GetInstance()->AddPointer(pa);
	ReferenceCounterManager::GetInstance()->AddPointer(pa);
	ReferenceCounterManager::GetInstance()->AddPointer(pa);
	cout << ReferenceCounterManager::GetInstance()->GetReferenceCount(pa) << endl;
	ReferenceCounterManager::GetInstance()->SubtractPointer(pa);
	cout << ReferenceCounterManager::GetInstance()->GetReferenceCount(pa) << endl;
	return 0;
}