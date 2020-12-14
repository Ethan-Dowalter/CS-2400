/**
 *   @file: appointment.h
 * @author: Ethan Dowalter
 *   @date: December 4, 2019
 *  @brief: Class definition for the Appointment class
 */

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
        ///Default
        Appointment();
        Appointment(string appData);

        ///Getters
        string getTitle();
        int getYear();
        int getMonth();
        int getDay();
        int getTime();                      //military time
        int getDuration();
        string getDate();                   //return a date of the format yyyy-mm-dd
        string getStandardTime();

        ///Setters
        void setTitle(string newTitle);
        void setYear(int newYear);
        void setMonth(int newMonth);
        void setDay(int newDay);
        void setTime(int newTime);          //military time
        void setDuration(int newDuration);
        void setDate(int year, int month, int day);

        ///Helpers
        string militaryToStandard(int time);
        int standardToMilitary(string standard_time);
        friend bool operator== (const Appointment &first, const Appointment &second);
        void shiftBars(size_t &start, size_t &stop, string appData);
        void output();
        
        
    private:
        string title;
        int year;
        int month;
        int day;
        int time;
        int duration;
        string date;
        string standard_time;
};
#endif