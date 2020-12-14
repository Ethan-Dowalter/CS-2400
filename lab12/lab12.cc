/*
 *        File: lab12
 *      Author: Ethan Dowalter
 *        Date: November 15, 2019
 * Description: Gets data about employees from a file and loads it into a structure
 *              then prints out a report of all the data
 *              
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

///Struct to store all info for one employee
struct Employee
{
    int id;
    string first;
    string last;
    double salary;
};

//Loads a vector of structs from an input file
void loadVector(vector <Employee> &allEmployees);

//Prints out all info in vector about all employees
void printReport(vector <Employee> allEmployees);

//Calculates the total payroll of all employees
double totalPayroll(vector <Employee> allEmployees);



int main()
{
    vector <Employee> allEmployees;         //stores all info about all employees

    loadVector(allEmployees);
    
    printReport(allEmployees);

    return 0;
}



void loadVector(vector <Employee> &allEmployees)
{
    ifstream inStream;
    inStream.open("employees.txt");         //open input file
    if (inStream.fail())                    //check for failure
    {
        cout << "Error. Could not open input file." << endl;
        exit(0);
    }

    Employee e;                             //dummy variable for a single employee
    while (inStream >> e.id >> e.first >> e.last >> e.salary)
    {
        allEmployees.push_back(e);          //store employee in vector
    }
    inStream.close();                       //close file
}

void printReport(vector <Employee> allEmployees)
{
    cout << endl;

    ///Table header
    cout << setw(6) << left << "ID" << setw(22) << "First";
    cout << setw(10) << "Salary" << endl;
    for (size_t i = 0; i < 37; i++)
    {
        cout << '-';
    } 
    cout << endl;

    ///Table data
    string salary;                  //string to store salary to add a dollar sign
    for (size_t i = 0; i < allEmployees.size(); i++)
    {
        cout << setw(6)  << allEmployees.at(i).id;
        cout << setw(22) << allEmployees.at(i).first + ' ' + allEmployees.at(i).last;
        salary = '$' + to_string(allEmployees.at(i).salary);                //adds dollar sign
        salary.erase(salary.size() - 4, salary.size());                     //gets rid of extra decimal places from to_string
        cout << setw(10) << salary << endl;
    }

    ///Get total salaries
    for (size_t i = 0; i < 37; i++)
    {
            cout << '-';
    }
    cout << endl;
    cout << setw(23) << right << "TOTAL";
    string total = '$' + to_string(totalPayroll(allEmployees));     //adds dollar sign to total
    total.erase(total.size() - 4, total.size());                    //gets rid of extra decimal places from to_string
    cout << setw(14) << total << endl;

    cout << endl;
}

double totalPayroll(vector <Employee> allEmployees)
{
    double total = 0;               //sum of all salaries
    for (size_t i = 0; i < allEmployees.size(); i++)
    {
        total += allEmployees.at(i).salary;
    }
    return total;
}