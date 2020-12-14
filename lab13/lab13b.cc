/*
 *        File: lab13b
 *      Author: Ethan Dowalter
 *        Date: November 22, 2019
 * Description: Simulates a tollbooth using a class
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;


class Tollbooth
{
    public:
        Tollbooth();                        //default constructor
        void payinCar();                    //increments total cars and adds $0.50 to revenue
        void nopayCar();                    //increments total cars
        void display(ostream& fileout);     //displays member variables
    private:
        int numCars;                        //total amount of cars that pass
        double revenue;                     //total revenue collected
};



int main()
{
    Tollbooth bridge;   //tollbooth object to track cars passing on a bridge
    char ch;            //input char

    cout << "P-Paid  N-Not paid  Q-Quit --> ";
    cin >> ch;
    while (ch != 'Q' && ch != 'q')          //sentinal loop
    {
        if (ch == 'P' || ch == 'p')
        {
            bridge.payinCar();
        }
        else if (ch == 'N' || ch == 'n')
        {
            bridge.nopayCar();
        }
        cout << "P-Paid  N-Not paid  Q-Quit --> ";
        cin >> ch;
    }

    bridge.display(cout);                   //displays totals on screen

    return 0;
}



Tollbooth::Tollbooth()
{
    numCars = 0;        //default values
    revenue = 0;
}

void Tollbooth::payinCar()
{
    numCars += 1;           //car passes
    revenue += 0.5;         //and pays
}

void Tollbooth::nopayCar()
{
    numCars += 1;           //car passes without paying
}

void Tollbooth::display(ostream& fileout)
{
    fileout << "Total cars : " << numCars << endl;
    fileout << "Total revenue : $" << setprecision(2) << fixed << revenue << endl;
}