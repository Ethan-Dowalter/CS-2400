/*
 *        File: lab10
 *      Author: Ethan Dowalter
 *        Date: November 1, 2019
 * Description: Reads from two input files containing prices and names of parts and outputs
 *              the name and price of the most and least expensive items
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;



int getMostExpensive(double prices[]);      //returns the location of the most expensive part

int getCheapest(double prices[]);           //returns the location of the cheapest part



int main()
{
    double prices[6];               //array to store prices of parts
    string parts[6];                //array to store names of parts

    ///Read in first file
    ifstream inStream;
    inStream.open("data1.txt");
    if (inStream.fail())            //checks if price input file failed to open
    {
        cout << "Error. Could not open input file." << endl;
        exit(0);
    }
    for (size_t i = 0; i < 6; i++)
    {
        inStream >> prices[i];      //loads prices into array
    }
    inStream.close();

    ///Read in second file
    inStream.open("data2.txt");
    if (inStream.fail())            //checks if parts input file failed to open
    {
        cout << "Error. Could not open input file." << endl;
        exit(0);
    }
    for (size_t i = 0; i < 6; i++)
    {
        inStream >> parts[i];      //loads part names into array
    }
    inStream.close();

    ///Output results to screen
    cout << setprecision(2) << fixed;
    cout << "The most expensive part is " << parts[getMostExpensive(prices)];
    cout << " and it costs $" << prices[getMostExpensive(prices)] << endl;
    cout << "The least expensive part is " << parts[getCheapest(prices)];
    cout << " and it costs $" << prices[getCheapest(prices)] << endl;

    return 0;
}



int getMostExpensive(double prices[])
{
    double exp = prices[0];         //stores highest price
    int locExp = 0;                 //stores location of highest price
    for (size_t i = 1; i < 6; i++)
    {
        if (prices[i] > exp)
        {
            exp = prices[i];
            locExp = i;
        }
    }
    return locExp;
}

int getCheapest(double prices[])
{
    double cheap = prices[0];         //stores lowest price
    int locCheap = 0;                 //stores location of lowest price
    for (size_t i = 1; i < 6; i++)
    {
        if (prices[i] < cheap)
        {
            cheap = prices[i];
            locCheap = i;
        }
    }
    return locCheap;
}