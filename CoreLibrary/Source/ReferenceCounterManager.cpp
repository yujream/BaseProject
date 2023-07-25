#include "ReferenceCounterManager.h"

ReferenceCounterManager* ReferenceCounterManager::GetInstance()
{
	static ReferenceCounterManager Instance;
	return &Instance;
}

void ReferenceCounterManager::AddPointer(void* Pointer)
{
	CounterInfo* ResultNode = GetPointer(Pointer);
	if (nullptr != ResultNode)
	{
		ResultNode->Count++;
	}
	else
	{
		AppendPointer(Pointer);
	}
}

CounterInfo* ReferenceCounterManager::GetPointer(void* Pointer)
{
	CounterInfo* Node = Head;
	while (nullptr != Node)
	{
		if (Pointer == Node->Pointer)
		{
			return Node;
		}
	}

	return nullptr;
}

void ReferenceCounterManager::SubtractPointer(void* Pointer)
{
	CounterInfo* ResultNode = GetPointer(Pointer);
	if (nullptr != ResultNode)
	{
		ResultNode->Count--;
	}
}

int ReferenceCounterManager::GetReferenceCount(void* Pointer)
{
	CounterInfo* ResultNode = GetPointer(Pointer);
	if (nullptr != ResultNode)
	{
		return ResultNode->Count;
	}

	return -1;
}

void ReferenceCounterManager::AppendPointer(void* Pointer)
{
	if (nullptr == Head)
	{
		Head = new CounterInfo(Pointer);
	}

	CounterInfo* Node = Head;
	while (nullptr != Node->Next)
	{
		Node = Node->Next;
	}

	Node->Next = new CounterInfo(Pointer);
}
