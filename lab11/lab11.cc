/*
 *        File: lab11
 *      Author: Ethan Dowalter
 *        Date: November 8, 2019
 * Description: Takes an input file and converts its chars to capital and its digits to asterisks
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ///Open files for input/output
    ifstream inStream;
    ofstream outStream;
    inStream.open("text.txt");
    if (inStream.fail())
    {
        cout << "\nError. Could not open input file." << endl;
        exit(0);
    }
    outStream.open("out.txt");
    if (outStream.fail())
    {
        cout << "\nError. Could not open output file." << endl;
        exit(0);
    }

    ///Read from input file and write to output file
    char ch;                    //char to read from file, one char at a time
    while (inStream.get(ch))
    {
        if (islower(ch))            //if lowercase, convert to capital
        {
            ch = toupper(ch);
        }
        else if (isdigit(ch))       //if digit, convert to asterisk
        {
            ch = '*';
        }
        outStream << ch;
    }

    ///Close files for input/output
    inStream.close();
    outStream.close();
    return 0;
}
