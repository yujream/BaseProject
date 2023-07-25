#ifndef __REFERENCE_COUNTER_MANAGER_H__
#define __REFERENCE_COUNTER_MANAGER_H__

/*
 * 用于存储指针信息的链表
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
	static ReferenceCounterManager* GetInstance();

	void AddPointer(void* Pointer);
	CounterInfo* GetPointer(void* Pointer);
	void SubtractPointer(void* Pointer);

	int GetReferenceCount(void* Pointer);

private:
	ReferenceCounterManager() = default;
	~ReferenceCounterManager() = default;

	void AppendPointer(void* Pointer);

private:
	CounterInfo* Head;
};

#endif
