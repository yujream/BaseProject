#include "ReferenceCounterManager.h"

ReferenceCounterManager* ReferenceCounterManager::GetInstance()
{
	static ReferenceCounterManager Instance;
	return &Instance;
}

void ReferenceCounterManager::AddPointer(void* Pointer)
{
	if (nullptr == Head)
	{
		Head = new CounterInfo(Pointer);
		return;
	}

	CounterInfo* Node = Head;
	while (Node->Next)
	{
		if (Node->Pointer == Pointer)
		{
			Node->Count++;
			return;
		}

		Node = Node->Next;
	}

	if (Node->Pointer == Pointer)
	{
		Node->Count++;
	}
	else
	{
		CounterInfo* Info = new CounterInfo(Pointer);
		Node->Next = Info;
	}
}
