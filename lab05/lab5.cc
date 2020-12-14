/*
 *        File: lab5.cc
 *      Author: Ethan Dowalter
 *        Date: September 27, 2019
 * Description: User enters high and low temps and program returns the 
 *              highest high and lowest low
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[])
{
    ///Intro to user
    cout << "\nThis program processes daily temperature data and will return " 
      << "the highest high and the lowest low, for any amount of days entered.\n" << endl;
    
    ///While loop for however many days user wants to enter
    int high = 0, low = 0;                          //variables for user input
    int highest_high = -300, lowest_low = 300;      //variables to store largest/smallest values, initialized to impossible values
    while (high != -100 || low != -100)             //sentinal value -100 to quit
    {
        cout << "  (Enter -100 to quit)" << endl;     //informs user of sentinal value
        cout << "Enter the daily high : ";
        cin >> high;
        if (high == -100)
        {
            break;                      //immediately breaks if user enters sentinal value
        }
        else if (high > highest_high)
        {
            highest_high = high;        //assigns new value if user value is higher
        }

        cout << "Enter the daily low : ";
        cin >> low;
        if (low == -100)
        {
            break;                      //immediately breaks if user enters sentinal value
        }
        else if (low < lowest_low)
        {
            lowest_low = low;           //assigns new value if user value is lower
        }
    }

    ///Outputs highest and lowest temps
    cout << "\nThe highest temperature was " << highest_high << endl;
    cout << "The lowest temperature was " << lowest_low << endl << endl;
    
    return 0;
}// main