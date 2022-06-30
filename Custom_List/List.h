#pragma once

/*
        АРХИТЕКТУРА

    Доступа к нодам нет, возврощаем значение распоковывая ноду 

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

public:

    MyList() : FistNode(nullptr), LastNode(nullptr), size(0) {};

    MyList(T data);

    ~MyList();

    T& operator[](int index) const;

	// todo \|\|\|
    bool operator==(const T& value) const;
    bool operator>(const T& value) const;
    bool operator<(const T& value) const;
	
    // Создать элемент перед элементом с схожим значением 
    //void insert(T data);

    void insert(T data, int index);
    void insert(T data);

    void PushFront(T);
    void PushBack(T);

    T& PopFront();
    T& PopBack();

    int  GetSize();

    void Clear();
};


/*
* Пытался осмыслить шальную сысль что я в этом огрызке могу хранить любые данные
* но идея оказалась говном, а не выпилил чтобы не забывать что идея говно
*
template<class T>
class MyList
{
protected:

    int size;

    T* FistNode;
    T* LastNode;

public:

    MyList() : FistNode(nullptr), LastNode(nullptr), size(0) {};

    MyList(T* node) : FistNode(node), LastNode(node), size(1) {};

    T* operator[](int index);

    // вставить в начало списка
    void insert(T* node);
    // вставить после элемента
    void insert(T* node, T* after);
};
*/

