#pragma once

#include "List.h"


#pragma region MyList

template<class T>
inline MyList<T>::MyList(T data)
{
	LastNode = FistNode = new MyListNode(data, nullptr, nullptr);

	size = 1;
}

template <class T>
MyList<T>::~MyList()
{
	Clear();
}


template<class T>
T& MyList<T>::operator[](int index) const
{
	if (!size)
	{
		throw std::exception("Operator [] is falling, list is empty");
	}

	MyListNode* TempFistNode = FistNode;

	for (int i = 0; i < index; i++)
	{
		TempFistNode = TempFistNode->NextNode;
	}

	return TempFistNode->Data;

}

template <class T>
void MyList<T>::insert(T data, int index)
{
	if (size > index)
	{
		MyListNode* TempFistNode = FistNode;
		for (int i = 0; i < index; i++)
		{
			TempFistNode = TempFistNode->NextNode;
		}

		MyListNode* tempnode = TempFistNode->PreviousNode;

		TempFistNode->PreviousNode =
			new MyListNode(data, TempFistNode->PreviousNode, TempFistNode);

		tempnode->NextNode = TempFistNode->PreviousNode;

		size++;
	}
	else
	{
		throw std::exception("Method Insert, index > size");
	}

}


template<class T>
void MyList<T>::PushFront(T data)
{
	if (FistNode != nullptr)
	{
		FistNode->PreviousNode = new MyListNode(data, nullptr, FistNode);

		FistNode = FistNode->PreviousNode;
	}
	else
	{
		FistNode = LastNode = new MyListNode(data, nullptr, nullptr);
	}
	size++;
}

template<class T>
void MyList<T>::PushBack(T data)
{
	if (LastNode != nullptr)
	{
		LastNode->NextNode = new MyListNode(data, LastNode, nullptr);

		LastNode = LastNode->NextNode;
	}
	else
	{
		FistNode = LastNode = new MyListNode(data, nullptr, nullptr);
	}
	size++;
}

template <class T>
T& MyList<T>::PopFront()
{
	if (!size)
	{
		throw std::exception("Method PopFront is falling, list is empty");
	}
	else if (size == 1)
	{
		T tempT = FistNode->Data;
		FistNode = LastNode = nullptr;
		delete& FistNode->Data;
		size--;
		return tempT;
	}
	else
	{

		T tempT = FistNode->Data;
		MyListNode* tempnode = FistNode->NextNode;

		/*
		почему не работает

			delete FistNode;
				~MyListNode() { delete &Data; }

		а это работает
			delete &FistNode->Data;

		 */
		delete& FistNode->Data;

		tempnode->PreviousNode = nullptr;

		FistNode = tempnode;

		size--;

		return tempT;
	}

}

template <class T>
T& MyList<T>::PopBack()
{
	if (!size)
	{
		throw std::exception("Method PopBack is falling, list is empty");
	}
	if (size == 1)
	{
		T tempT = LastNode->Data;
		FistNode = LastNode = nullptr;
		delete& LastNode->Data;
		size--;
		return tempT;
	}

	T tempT = LastNode->Data;
	MyListNode* tempnode = LastNode->PreviousNode;

	delete& LastNode->Data;

	tempnode->NextNode = nullptr;

	LastNode = tempnode;

	size--;

	return tempT;
}

template <class T>
int MyList<T>::GetSize()
{
	return size;
}

template <class T>
void MyList<T>::Clear()
{
	if (size)
	{
		for (int i = 0; i <= size; i++)
			PopFront();
	}

}

#pragma endregion ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
