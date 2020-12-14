#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

class Appointment
{
    public:
        ///Constructors
        /**  
         *   Function - Default Constructor
         *            > initializes all member variables to default values
         */
        Appointment();

        /**  
         *   Function - Constructor
         *            > initializes member variables to values specified in string
         *   @param appData - string with all appointment info in it
         */
        Appointment(string appData);



        ///Getters
        /**  
         *   Function - getTitle
         *            > returns the title of the appointment
         *   @return - member variable, title
         */
        string getTitle();

        /**  
         *   Function - getYear
         *            > returns the year of the appointment
         *   @return - member variable, year
         */
        int getYear();

        /**  
         *   Function - getMonth
         *            > returns the month of the appointment
         *   @return - member variable, month
         */
        int getMonth();

        /**  
         *   Function - getDay
         *            > returns the day of the appointment
         *   @return - member variable, day
         */
        int getDay();

        /**  
         *   Function - getTime
         *            > returns the time of the appointment in military time
         *   @return - member variable, time
         */
        int getTime();

        /**  
         *   Function - getDuration
         *            > returns the duration of the appointment in minutes
         *   @return - member variable, duration
         */
        int getDuration();

        /**  
         *   Function - getDate
         *            > returns the full date of the appointment in the format yyyy-mm-dd
         *   @return - member variable, date
         */
        string getDate();

        /**  
         *   Function - getStandardTime
         *            > returns the standard time of the appointment, ex. "8:30PM"
         *   @return - member variable, standard_time
         */
        string getStandardTime();



        ///Setters
        /**  
         *   Function - setTitle
         *            > sets the title of the appointment
         *   @param newTitle - title of appointment, no invalid value
         */
        void setTitle(string newTitle);

        /**  
         *   Function - setYear
         *            > sets the year of the appointment
         *   @param newYear - year of appointment, must be >= 0
         */
        void setYear(int newYear);

        /**  
         *   Function - setMonth
         *            > sets the month of the appointment
         *   @param newMonth - month of appointment, must be between 1-12
         */
        void setMonth(int newMonth);

        /**  
         *   Function - setDay
         *            > sets the day of the appointment
         *   @param newDay - day of appointment, must be between 1-31
         */
        void setDay(int newDay);

        /**  
         *   Function - setTime
         *            > sets the time of the appointment in military time
         *   @param newTime - time of appointment in military time, ex. 2030 (8:30PM)
         */
        void setTime(int newTime);

        /**  
         *   Function - setDuration
         *            > sets the duration of the appointment in minutes
         *   @param newDuration - duration of appointment, must be > 0
         */
        void setDuration(int newDuration);

        /**  
         *   Function - setDate
         *            > sets the date of the appointment
         *   @param year - year of appointment, must be >= 0
         *   @param month - month of appointment, must be between 1-12
         *   @param day - day of appointment, must be between 1-31
         */
        void setDate(int year, int month, int day);



        ///Helpers
        /**  
         *   Function - militaryToStandard
         *            > converts military time to standard time
         *   @param time - military time in int form
         *   @return - standard time, ex. "8:30PM" for 2030 military time
         */
        string militaryToStandard(int time);

        /**  
         *   Function - standardToMilitary
         *            > converts standard time to military time
         *   @param standard_time - standard time string, ex. "8:30PM"
         *   @return - military time, ex. 2030 for "8:30PM"
         */
        int standardToMilitary(string standard_time);

        /**  
         *   Function - operator==
         *            > overloads == operator to check for equality of Appointment objects
         *   @param first - first Appointment obect being compared
         *   @param second - second Appointment object being compared
         *   @return - true if all member variables in both objects are equal, else false
         */
        friend bool operator== (const Appointment &first, const Appointment &second);

        /**  
         *   Function - shiftBars
         *            > used to read everything between two bars in the regular constructor
         *              since "appData" has the format "title|year|month|day|time|duration"
         *   @param start - index of first bar to start reading from
         *   @param stop - index of bar to stop reading at
         *   @param appData - string with all appointment info in it 
         */
        void shiftBars(size_t &start, size_t &stop, string appData);

        /**  
         *   Function - output
         *            > prints out all member variables of an Appointment object
         */
        void output();
        
        

    private:
        string title;               //title of appointment, could be anything
        int year;                   //year of appointment, default 1, must be >= 0
        int month;                  //month of appointment, default 1, must be between 1-12
        int day;                    //day of appointment, default 1, must be between 1-31
        int time;                   //time of appointment in military time, default 0000
        int duration;               //duration of appointment in minutes, default 1, must be > 0
        string date;                //full date of appointment in format yyyy-mm-dd
        string standard_time;       //standard time of appointment, default 12:00AM
};
#endif