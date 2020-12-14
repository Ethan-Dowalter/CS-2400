/*
 *        File: lab13a
 *      Author: Ethan Dowalter
 *        Date: November 22, 2019
 * Description: Simple demonstration of how to use a class and its member functions
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Counter
{
    public:
        Counter();
        Counter(int new_val);

        void increment();
        int get_value();

    private:
        int value;
};


int main()
{
    Counter c(4);
    if (c.get_value() < 10)
    {
        c.increment();
    }
    cout << "Oringinal value: " << c.get_value() - 1 << endl;
    cout << "New value: " << c.get_value() << endl;

    return 0;
}

Counter::Counter()
{
    value = 0;
}

Counter::Counter(int new_val)
{
    value = new_val;
}

int Counter::get_value()
{
    return value;
}

void Counter::increment()
{
    value += 1;
}