#pragma once

/*
        АРХИТЕКТУРА

    Нужно запилить 3 сущности
    &1 Алгоритм слежения за индексом и положить его в контейнер
    &2 Костомный list который будет хранить наши node
    &3 Сам класс Node который будет реализован вне класса

    &2
        У контейнера будет один метод
            он будет переруженн под данные и экземпляр node
                перегруженная версия для node будет также принимать ключ для вставки

            void insert(T data);                             // Создать элемент в начало
            void insert(MyListNode* node);                   // вставить в начало списка
            void insert(MyListNode* node, MyListNode* after) // вставить после элемента

        Констуктор будет по умолчанию, принимающий data и node устанавливая
            переданную ноду первой в списке

            MyList(): FistNode = nullptr, EndNode = nullptr;
            MyList(T data);
            MyList(MyListNode* node);

        В MyList должен быть перегружен операто[]

            MyListNode* operator[](int index);

        Деструктор будет очищать список уничтожая все ноды


    &3  В моём контейнере данные будет храниться в самой node

        У класса node будет 3 поля
            T data;
            MyListNode* NextNode;
            MyListNode* PreviousNode;

        Также у неё будет 3 геттера

            T* GetData();
            MyListNode *& GetNextNode();
            MyListNode *& GetPreviousNode();


        И два метода вставка перед и после него

            void PushFront(MyListNode*);
            void PushFront(T&);

            void PushBack(MyListNode*);
            void PushBack(T&);

*/

/*
* Node
*
    Хранить Data по значению (просто использовать конструктор )

    Добавить указатель на list который будем передовать в статических конструкторах

    Открыть публичный доступ к Data
    Сокрыть конструктор сделать его статическим методом
    конструктор - вставить в начало "для вставки вызывается метод переденного листа"
    конструктор - вставить в конец "для вставки вызывается метод переденного листа"

    Сделать конструтор который принимает просто Data
    такую ноду может вставить к себе list

    Убить методы
    все методы
*/

/*
 *
    Переименовать insert на PushFront, PushBack
    Сделать метод извлечения из list

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

    // Создать элемент перед элементом с схожим значением 
    //void insert(T data);

    // вставить после элемента
    void insert(T data, int index);

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

