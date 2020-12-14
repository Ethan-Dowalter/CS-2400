/*
 *        File: lab9.cc
 *      Author: Ethan Dowalter
 *        Date: October 25, 2019
 * Description: Reads from a text file containing temps and outputs the lowest, highest, and avg
 *              
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

///Finds lowest value in an array
int lowTemp(int dailyLow[], int count);

///Finds highest value in an array
int highTemp(int dailyLow[], int count);

///Computes the average value in an array
double avgTemp(int dailyLow[], int count);

int main()
{
    ///Open file
    ifstream inStream;
    inStream.open("athens_low_temps.txt");
    if (inStream.fail())
    {
        cout << "Error. File does not exist.";
        exit(0);
    }

    ///Load array from file
    int count = 30;                 //amount of elements in array
    int dailyLow[count];            //array to store temp data
    for (int i = 0; i < count; i++)
    {
        inStream >> dailyLow[i];    //read data and put into array
    }
    inStream.close();               //close file

    ///Output to terminal
    cout << "The lowest low was " << lowTemp(dailyLow, count) << endl;
    cout << "The highest low was " << highTemp(dailyLow, count) << endl;
    cout << "The average low was " << avgTemp(dailyLow, count) << endl;

    return 0;
}

int lowTemp(int dailyLow[], int count)
{
    int min = dailyLow[0];          //stores the min value of array
    for (int i = 1; i < count; i++)
    {
        if (dailyLow[i] < min)
        {
            min = dailyLow[i];      //reassigns min if array value is lower
        }
    }
    return min;
}

int highTemp(int dailyLow[], int count)
{
    int max = dailyLow[0];          //stores the max value of array
    for (int i = 1; i < count; i++)
    {
        if (dailyLow[i] > max)
        {
            max = dailyLow[i];      //reassigns max if array value is higher
        }
    }
    return max;
}

double avgTemp(int dailyLow[], int count)
{
    int total = 0;                  //stores the total of the array
    for (int i = 0; i < count; i++)
    {
        total += dailyLow[i];       //add value of array to total
    }
    return 1.0 * total / count;     //make sure to avoid integer division
}