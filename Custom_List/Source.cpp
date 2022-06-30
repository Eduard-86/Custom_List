#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <set>

#include "List.h"


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

using namespace std;

int main()
{


    return 0;
}
