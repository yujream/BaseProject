#include <iostream>
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
	return 0;
}