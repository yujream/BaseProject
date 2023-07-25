#ifndef __REFERENCE_COUNTER_MANAGER_H__
#define __REFERENCE_COUNTER_MANAGER_H__

/*
 * ���ڴ洢ָ����Ϣ������
 */
struct CounterInfo
{
	CounterInfo() : Pointer(nullptr), Count(0), Next(nullptr)
	{
		
	}

	CounterInfo(void* NewPointer)
		: Pointer(NewPointer), Count(1), Next(nullptr)
	{
		
	}

	void* Pointer;
	int Count;

	CounterInfo* Next;
};

class ReferenceCounterManager
{
public:
	ReferenceCounterManager* GetInstance();

	void AddPointer(void* Pointer);

private:
	ReferenceCounterManager() = default;
	~ReferenceCounterManager() = default;
	
private:
	CounterInfo* Head;
};

#endif
