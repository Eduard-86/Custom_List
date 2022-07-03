#pragma once
#include <iostream>
#include <exception>


/*
        АРХИТЕКТУРА

    Доступа к нодам нет, возврощаем значение распоковывая ноду 

    =========================== Чё хотелось бы допилить ============================

	* Сортировку по предикату
	* Аллокаторы \\ хз на самом деле 
	* Итераторы
	Позже ещё что придумаю 

*/


/*
 *
 * Class Exception
 *
 *
using std::string;

template<class Key>
class not_found_exception : public std::exception
{
public:
    virtual const Key& get_key() const noexcept = 0;
};

class russian_dictionary_exception : public not_found_exception<const string>
{
protected:

    string* key;

public:

    russian_dictionary_exception(string msg)
    {
        key = new string();

        *key = msg;
    }

    virtual ~russian_dictionary_exception() override
    {
        delete key;

    }

    const string& get_key() const noexcept override
    {
        return *key;
    }

};
*/



template<class T>
class MyList
{
public:

    template<class T>
    MyList() : FistNode(nullptr), LastNode(nullptr), size(0) {};

    MyList(T data);

    ~MyList();

    T& operator[](int index) const;

    // todo \|\|\|
    bool operator==(const MyList& value) const;
    bool operator>(const MyList& value) const;
    bool operator<(const MyList& value) const;

    void insert(T data, int index);
    void insert(T data);

    void PushFront(T);
    void PushBack(T);

    T& PopFront();
    T& PopBack();

    int  GetSize() const;

    void Clear();
	
protected:

    int size;

    class MyListNode
    {
    public:
        MyListNode(T data = T(), MyListNode* Previous = nullptr, MyListNode* Next = nullptr)
            : Data(data), PreviousNode(Previous), NextNode(Next)
        {}

        T Data;
        MyListNode* PreviousNode;
        MyListNode* NextNode;

    };

    MyListNode* FistNode;
    MyListNode* LastNode;


};




#pragma region MyList

template<class T>
MyList<T>::MyList(T data)
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
bool MyList<T>::operator==(const MyList& value) const
{
	return this->size == value.size;
}

template <class T>
bool MyList<T>::operator>(const MyList& value) const
{
	return this->size > value.size;
}

template <class T>
bool MyList<T>::operator<(const MyList& value) const
{
	return this->size < value.size;
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

template <class T>
void MyList<T>::insert(T data)
{
	PushFront(data);
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
int MyList<T>::GetSize() const
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
