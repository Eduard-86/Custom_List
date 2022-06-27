#pragma once

/*
        �����������

    ����� �������� 3 ��������
    &1 �������� �������� �� �������� � �������� ��� � ���������
    &2 ��������� list ������� ����� ������� ���� node
    &3 ��� ����� Node ������� ����� ���������� ��� ������

    &2
        � ���������� ����� ���� �����
            �� ����� ���������� ��� ������ � ��������� node
                ������������� ������ ��� node ����� ����� ��������� ���� ��� �������

            void insert(T data);                             // ������� ������� � ������
            void insert(MyListNode* node);                   // �������� � ������ ������
            void insert(MyListNode* node, MyListNode* after) // �������� ����� ��������

        ���������� ����� �� ���������, ����������� data � node ������������
            ���������� ���� ������ � ������

            MyList(): FistNode = nullptr, EndNode = nullptr;
            MyList(T data);
            MyList(MyListNode* node);

        � MyList ������ ���� ���������� �������[]

            MyListNode* operator[](int index);

        ���������� ����� ������� ������ ��������� ��� ����


    &3  � ��� ���������� ������ ����� ��������� � ����� node

        � ������ node ����� 3 ����
            T data;
            MyListNode* NextNode;
            MyListNode* PreviousNode;

        ����� � �� ����� 3 �������

            T* GetData();
            MyListNode *& GetNextNode();
            MyListNode *& GetPreviousNode();


        � ��� ������ ������� ����� � ����� ����

            void PushFront(MyListNode*);
            void PushFront(T&);

            void PushBack(MyListNode*);
            void PushBack(T&);

*/

/*
* Node
*
    ������� Data �� �������� (������ ������������ ����������� )

    �������� ��������� �� list ������� ����� ���������� � ����������� �������������

    ������� ��������� ������ � Data
    ������� ����������� ������� ��� ����������� �������
    ����������� - �������� � ������ "��� ������� ���������� ����� ����������� �����"
    ����������� - �������� � ����� "��� ������� ���������� ����� ����������� �����"

    ������� ���������� ������� ��������� ������ Data
    ����� ���� ����� �������� � ���� list

    ����� ������
    ��� ������
*/

/*
 *
    ������������� insert �� PushFront, PushBack
    ������� ����� ���������� �� list

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

    // ������� ������� ����� ��������� � ������ ��������� 
    //void insert(T data);

    // �������� ����� ��������
    void insert(T data, int index);

    void PushFront(T);
    void PushBack(T);

    T& PopFront();
    T& PopBack();

    int  GetSize();

    void Clear();
};


/*
* ������� ��������� ������� ����� ��� � � ���� ������� ���� ������� ����� ������
* �� ���� ��������� ������, � �� ������� ����� �� �������� ��� ���� �����
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

    // �������� � ������ ������
    void insert(T* node);
    // �������� ����� ��������
    void insert(T* node, T* after);
};
*/

