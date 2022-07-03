#include <iostream>
#include "List.h"

// jalko
/*
class FSM
{
public:

    enum class Key : int
    {
        state1 = 0,
        state2 = 1,
        state3 = 2
    };

    void Tick()
    {
        switch (kek)
        {
        case FSM::Key::state1:
        {
            State0();
            break;
        }

        case FSM::Key::state2:
        {
            State1();
            break;
        }

        case FSM::Key::state3:
        {
            State2();
            break;
        }

        default:
            break;
        }
    }

    void State0()
    {
        std::cout << "0\n";
    }

    void State1()
    {
        std::cout << "1\n";
    }

    void State2()
    {
        std::cout << "2\n";
    }

    void SetKekw(FSM::Key key)
    {
        kek = key;
    }

    Key GetKekw()
    {
        return kek;
    }

protected:

    Key kek = Key::state1;
};
*/

template <class T>
class hhh
{
public:
	
    
    T fuu(T fff);
};

template <class T>
T hhh<T>::fuu(T fff)
{
    return fff;
}

int main()
{
    using namespace std;


	
    MyList<int> list(999);
    list.PushFront(888);
    list.PushFront(878);
    list.PushFront(868);

	
    list.PushBack(757);
    list.PushBack(747);
    list.PushBack(737);

    list.insert(123, 0);

	
	for(int i = 0; i < list.GetSize(); ++i)
	{
        cout << list[i] << endl;
	}

    list.Clear();
	
	
    return 0;
}
