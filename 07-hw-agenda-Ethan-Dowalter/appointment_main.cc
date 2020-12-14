/**
 *   @file: appointment_main.cc
 * @author: Ethan Dowalter
 *   @date: December 4, 2019
 *  @brief: Contains some options that can be used to manipulate an agenda file that
 *          contains appointments using an appointment class
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
#include "appointment.h"

using namespace std;


/**  
 *   Function - isValidOption
 *            > checks if user entered option is valid
 *   @param option - one of five options: -ps, -p, -a, -dt, -dm
 *   @return - true or false
 */
bool isValidOption(string option);


/**  
 *   Function - dispAgendaInOrder
 *            > displays all appointments in agenda in chronological order
 *   @param appts - vector containing all appointments
 */
void dispAgendaInOrder(vector <Appointment> appts);


/**  
 *   Function - dispApptsAtTime
 *            > displays all appointments that occur at a specified military time
 *   @param appts - vector containing all appointments
 *   @param milTime - military time when appointment is scheduled
 */
void dispApptsAtTime(vector <Appointment> &appts, int milTime);


/**  
 *   Function - addAppt
 *            > adds an appointment to the agenda in format "title|year|month|day|std time|duration"
 *   @param appts - vector containing all appointments
 *   @param newAppt - new appointment to add to agenda
 */
void addAppt(vector <Appointment> &appts, string newAppt);


/**  
 *   Function - deleteApptTitle
 *            > deletes an appointment from the agenda with a specific title
 *   @param appts - vector containing all appointments
 *   @param title - title of appointment to be deleted
 */
void deleteApptTitle(vector <Appointment> &appts, string title);


/**  
 *   Function - deleteApptTime
 *            > delets an appointment from the agenda with a specific military time
 *   @param appts - vector containing all appointments
 *   @param milTime - time of appointment to be deleted
 */
void deleteApptTime(vector <Appointment> &appts, int milTime);



/*******************
    Main Function
 *******************/

int main(int argc, char const *argv[])
{
    ///Check for valid command
    if (argc != 2 && argc != 3)             //checks to see if user entered valid number of arguments
    {
        cout << "\nError. Please enter a valid number of arguments.\n" << endl;
        exit(0);
    }

    string option = argv[1];
    if (isValidOption(option) == false)     //checks for valid option
    {
        cout << "\nError. Please enter a valid option.\n" << endl;
        exit(0);
    }


    ///Read in input file
    ifstream inStream;
    inStream.open("agenda.txt");                //open input file
    if (inStream.fail())                        //check for failure opening file
    {
        cout << "Error. Could not open input file." << endl;
        exit(0);
    }

    vector <Appointment> appts;                 //vector for all the appointments
    string str;                                 //string to read in lines from input file
    while (!inStream.eof())
    {
        getline(inStream, str);
        if (str.length() >= 10)                 //ignore empty lines
        {
            Appointment a(str);                 //turn the string into an appointment
            appts.push_back(a);                 //send appointment to end of vector
        }
    }
    inStream.close();                           //close input file


    ///Call function corresponding to option
    if (argc == 2)
    {
        if (option == "-ps")                    //-ps option - print agenda in chronological order
        {
            dispAgendaInOrder(appts);
        }
        else
        {
            cout << "Please enter a valid option." << endl;
        }
        
    }
    else if (argc == 3)
    {
        string str = argv[2];                   //string to store third parameter
        if (option == "-p")                     //-p option - print appts that occur at specified time
        {
            dispApptsAtTime(appts, stoi(str));
        }
        else if (option == "-a")                //-a option - add an appt in format "title|year|month|day|std time|duration"
        {
            addAppt(appts, str);
        }
        else if (option == "-dt")               //-dt option - delets appts with specified title
        {
            deleteApptTitle(appts, str);
        }
        else if (option == "-dm")               //-dm option - delets appts with specified military time
        {
            deleteApptTime(appts, stoi(str));
        }
    }
    

    ///Write agenda back to file
    if (option == "-a" || option == "-dt" || option == "-dm")
    {
        ofstream outStream;
        outStream.open("agenda.txt");               //open output file
        if (outStream.fail())                       //check for failure opening file
        {
            cout << "Error. Could not open output file." << endl;
            exit(0);
        }

        for (size_t i = 0; i < appts.size(); i++)           //write to output file in format "title|year|month|day|std time|duration"
        {
            outStream << appts.at(i).getTitle() << '|';
            outStream << appts.at(i).getYear() << '|';
            outStream << appts.at(i).getMonth() << '|';
            outStream << appts.at(i).getDay() << '|';
            outStream << appts.at(i).getStandardTime() << '|';
            outStream << appts.at(i).getDuration() << endl;
        }
        outStream.close();          //close output file
    }

    return 0;
}



/**************************
    Function Definitions
 **************************/ 

bool isValidOption(string option)
{
    if (option == "-ps" || option == "-p" || option == "-a" || option == "-dt" || option == "-dm")
    {
        return true;
    }
    else
    {
        return false;
    }
}


void dispAgendaInOrder(vector <Appointment> appts)
{
    vector <size_t> minYearIndices, minMonthIndices, minDayIndices, minTimeIndices;         //tracks the indices of min date and time to try and minimize search time

    cout << endl;
    cout << left << setw(40) << "Title" << setw(13) << "Date";                              //table header labels
    cout << setw(10) << "Time" << setw(11) << "Duration" << endl;
    for (size_t i = 0; i < 73; i++)                                                         //table header dashes
    {
        cout << '-';
    }
    cout << endl;

    while (appts.size() > 0)                        //loop to search for earliest appt, erases it after it's displayed - so loop until vector is empty
    {
        int minYear = appts.at(0).getYear();            //earliest year in agenda, initalizes to first value in appt vector
        for (size_t i = 1; i < appts.size(); i++)       //finds minimum year
        {
            if (minYear > appts.at(i).getYear())
            {
                minYear = appts.at(i).getYear();
            }
        }
        for (size_t i = 0; i < appts.size(); i++)       //finds all indices with minYear and puts them into minYearIndices
        {
            if (minYear == appts.at(i).getYear())
            {
                minYearIndices.push_back(i);
            }
        }


        int minMonth = appts.at(minYearIndices.at(0)).getMonth();       //earliest month of the earliest year in agenda
                                                                        //initializes to first value where minYear occurs in appt vector
        for (size_t i = 1; i < minYearIndices.size(); i++)              //finds minMonth among the appts that occur in the minYear
        {
            if (minMonth > appts.at(minYearIndices.at(i)).getMonth())
            {
                minMonth = appts.at(minYearIndices.at(i)).getMonth();
            }
        }
        for (size_t i = 0; i < minYearIndices.size(); i++)              //finds all indices with minMonth and minYear and puts them into minMonthIndices
        {
            if (minMonth == appts.at(minYearIndices.at(i)).getMonth())
            {
                minMonthIndices.push_back(minYearIndices.at(i));
            }
        }

        int minDay = appts.at(minMonthIndices.at(0)).getDay();          //earliest day of the earliest month of the earliest year in agenda
                                                                        //initializes to first value where minMonth and minYear occur in appt vector
        for (size_t i = 1; i < minMonthIndices.size(); i++)             //finds minDay among the appts that occur in the minMonth of the minYear
        {
            if (minDay > appts.at(minMonthIndices.at(i)).getDay())
            {
                minDay = appts.at(minMonthIndices.at(i)).getDay();
            }
        }
        for (size_t i = 0; i < minMonthIndices.size(); i++)             //finds all indices with minDay, minMonth, and minYear and puts them into minDayIndices
        {
            if (minDay == appts.at(minMonthIndices.at(i)).getDay())
            {
                minDayIndices.push_back(minMonthIndices.at(i));
            }
        }

        int minTime = appts.at(minDayIndices.at(0)).getTime();          //earliest time on the earliest day of the earliest month of the earliest year in agenda
                                                                        //initalizes to first value where minDay, minMonth, and minYear occur in appt vector
        for (size_t i = 1; i < minDayIndices.size(); i++)               //finds minTime among the appts that occur on the minDay of the minMonth of the minYear
        {
            if (minTime > appts.at(minDayIndices.at(i)).getTime())
            {
                minTime = appts.at(minDayIndices.at(i)).getTime();
            }
        }
        for (size_t i = 0; i < minDayIndices.size(); i++)               //finds all indices with the minTime, minDay, minMonth, and minYear and puts them into minTimeIndices
        {
            if (minTime == appts.at(minDayIndices.at(i)).getTime())
            {
                minTimeIndices.push_back(minDayIndices.at(i));
            }
        }


        for (size_t i = 0; i < minTimeIndices.size(); i++)              //print out appt info for appts at indices in minTimeIndices
        {
            appts.at(minTimeIndices.at(i)).output();
        }
        for (int i = minTimeIndices.size() - 1; i >= 0; i--)            //erase the previously displayed appointments so they do not have to get searched over again
        {
            appts.erase(appts.begin() + minTimeIndices.at(i));
        }

        minYearIndices.clear();             //clear the vectors of their contents for next loop
        minMonthIndices.clear();
        minDayIndices.clear();
        minTimeIndices.clear();
    }

    for (size_t i = 0; i < 73; i++)         //table footer dashes
    {
        cout << '-';
    }
    cout << endl;
}


void dispApptsAtTime(vector <Appointment> &appts, int milTime)
{
    vector <size_t> apptsAtTimeIndices;             //stores indices where specified time occur in agenda
    for (size_t i = 0; i < appts.size(); i++)       //searches agenda for specified time and stores indices where it occurs
    {
        if (milTime == appts.at(i).getTime())
        {
            apptsAtTimeIndices.push_back(i);
        }
    }

    cout << endl;
    cout << left << setw(40) << "Title" << setw(13) << "Date";          //table header labels
    cout << setw(10) << "Time" << setw(11) << "Duration" << endl;
    for (size_t i = 0; i < 73; i++)                                     //table header dashes
    {
        cout << '-';
    }
    cout << endl;

    for (size_t i = 0; i < apptsAtTimeIndices.size(); i++)              //prints appts that occur at specified time
    {
        appts.at(apptsAtTimeIndices.at(i)).output();
    }

    for (size_t i = 0; i < 73; i++)         //table footer dashes
    {
        cout << '-';
    }
    cout << endl;
}


void addAppt(vector <Appointment> &appts, string newAppt)
{
    Appointment a(newAppt);         //creates new appt
    appts.push_back(a);             //adds new appt to agenda
}


void deleteApptTitle(vector <Appointment> &appts, string title)
{
    for (int i = appts.size() - 1; i >= 0; i--)     //searches agenda for appts with matching titles
    {
        if (title == appts.at(i).getTitle())        //if title matches, then erase it
        {
            appts.erase(appts.begin() + i);
        }
    }
}


void deleteApptTime(vector <Appointment> &appts, int milTime)
{
    for (int i = appts.size() - 1; i >= 0; i--)     //searches agenda for appts with matching times
    {
        if (milTime == appts.at(i).getTime())       //if time matches, then erase it
        {
            appts.erase(appts.begin() + i);
        }
    }
}