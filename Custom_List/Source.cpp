#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <set>

#include "List.h"



/*
        АРХИТЕКТУРА

    Нужно зпилисть 3 сущьности
    &1 Алгоритм и положить его в контейнер
    &2 Костомный list который будет хранить наши node
    &3 Сам класс Node который будет реализован вне класса

    &3 У контейнера будет один метод
        он будет переруженн под данные и экземпляр node

        void insert(T data);
        void insert(MyListNode* node, );

*/

/*
 *	Реализовать : Вставку - по индексу, в начало и конец
 *	Реализовать : Получение и удаление - по индексу, в начало и конец
 */

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
