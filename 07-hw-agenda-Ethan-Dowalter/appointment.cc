/**
 *   @file: appointment.cc
 * @author: Ethan Dowalter
 *   @date: December 4, 2019
 *  @brief: All getters, setters, constructors, and helper functions for the Appointment class
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

///Default constructors
Appointment::Appointment()
{
    ///Default values
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
}

Appointment::Appointment(string appData)
{
    ///Default values
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;

    ///Take input from appData
    int size = appData.size();              //keeps size of string constant b/c its subject to change
    for (size_t i = size - 1; i >= 0; i--)
    {
        if (i == appData.find('|'))
        {
            break;
        }
        else if (appData.at(i) == ' ' || appData.at(i) == '\t' || appData.at(i) == '\n')
        {
            appData.erase(i,1);             //deletes all whitespace from string after title
        }
    }
    while (appData.at(0) == ' ' || appData.at(0) == '\t' || appData.at(0) == '\n')
    {
        appData.erase(0,1);                 //if first character is whitespace then erase it
    }
    while (appData.at(appData.find('|') - 1) == ' ' || appData.at(appData.find('|') - 1) == '\t' || 
      appData.at(appData.find('|') - 1) == '\n')
    {
        appData.erase(appData.find('|') - 1, 1);    //if char before first bar is whitespace then erase it
    }

    size_t barStart = 0, barStop;                   //position of bars in appData string
    barStop = appData.find('|');                    //set position of first ending
    setTitle(appData.substr(0, barStop));           //title is everything until the first bar

    shiftBars(barStart, barStop, appData);          //year is between first and second bars
    setYear(stoi(appData.substr(barStart + 1, barStop - (barStart + 1))));

    shiftBars(barStart, barStop, appData);          //pattern continues with rest of variables
    setMonth(stoi(appData.substr(barStart + 1, barStop - (barStart + 1))));

    shiftBars(barStart, barStop, appData);
    setDay(stoi(appData.substr(barStart + 1, barStop - (barStart + 1))));

    shiftBars(barStart, barStop, appData);
    setTime(standardToMilitary(appData.substr(barStart + 1, barStop - (barStart + 1))));
    
    shiftBars(barStart, barStop, appData);
    setDuration(stoi(appData.substr(barStart + 1, barStop - (barStart + 1))));
}



///Title
string Appointment::getTitle()
{
    return title;
}

void Appointment::setTitle(string newTitle)
{
    title = newTitle;
}



///Year
int Appointment::getYear()
{
    return year;
}

void Appointment::setYear(int newYear)
{
    if (newYear >= 0)
    {
        year = newYear;
    }
}



///Month
int Appointment::getMonth()
{
    return month;
}

void Appointment::setMonth(int newMonth)
{
    if (newMonth >= 1 && newMonth <= 12)
    {
        month = newMonth;
    }
}



///Day
int Appointment::getDay()
{
    return day;
}

void Appointment::setDay(int newDay)
{
    if (newDay >= 1 && newDay <= 31)
    {
        day = newDay;
    }
}



///Time
int Appointment::getTime()
{
    return time;
}

void Appointment::setTime(int newTime)
{
    int newHour = newTime / 100;            //military time format, first two digits between 00-23
    int newMinute = newTime % 100;          //military time format, second two digits between 00-59
    if (newMinute / 60.0 < 1 && newHour < 24 && newTime > 0)
    {
        time = newTime;
    }
}



///Duration
int Appointment::getDuration()
{
    return duration;
}

void Appointment::setDuration(int newDuration)
{
    if (newDuration > 0)
    {
        duration = newDuration;
    }
}



///Date
string Appointment::getDate()
{
    if (month < 10)
    {
        return to_string(year) + '-' + '0' + to_string(month) + '-' + to_string(day);
    }
    else
    {
        return to_string(year) + '-' + to_string(month) + '-' + to_string(day);
    }    
}

void Appointment::setDate(int year, int month, int day)
{
    if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
    {
        setYear(year);
        setMonth(month);
        setDay(day);
        date = to_string(year) + '-' + to_string(month) + '-' + to_string(day);
    }
}



///Standard time and military time
string Appointment::getStandardTime()
{
    return militaryToStandard(time);
}

string Appointment::militaryToStandard(int time)
{
    if (time >= 0 && time < 2400)
    {
        int hour = time / 100 % 12;         //first two digits of military time give the hour, convert to 0-12
        if (hour == 0)                      //if hour is 0 then add 12
        {
            hour += 12;
        }
        int minute = time % 100;            //second two digits of military time give the minute
        
        string timeOfDay;                   //am or pm
        if (time < 1200)                    //before noon is am, after is pm
        {
            timeOfDay = "AM";
        }
        else
        {
            timeOfDay = "PM";
        }

        if (minute < 10)                   //put a placeholder 0 if minutes is less than 10
        {
            return to_string(hour) + ':' + '0' + to_string(minute) + timeOfDay;
        }
        else
        {
            return to_string(hour) + ':' + to_string(minute) + timeOfDay;
        }
    }
    else
    {
        return "Undefined";
    }
    
}

int Appointment::standardToMilitary(string standard_time)
{
    int hour, minute, military_time;                //ints to extract the time from the string standard_time
 
    hour = stoi(standard_time.substr(0, standard_time.find(':')));          //hour takes everything before ':'
    if (hour == 12)                                                         //if hour is 12 then it's 0 b/c military format
    {
        hour = 0;
    }

    minute = stoi(standard_time.substr(standard_time.find(':') + 1, 2));    //minute takes 2 places after ':'

    military_time = hour * 100 + minute;                                    //sum ints together in military format

    if (standard_time.find("PM") != string::npos || standard_time.find("pM") != string::npos || 
      standard_time.find("Pm") != string::npos || standard_time.find("pm") != string::npos)
    {
        military_time += 1200;                      //if PM then add 1200 to time
    }

    return military_time;
}



///Helper functions
bool operator ==(const Appointment &first, const Appointment &second)
{
    if (first.title == second.title && first.year == second.year && first.month == second.month
      && first.day == second.day && first.time == second.time && first.duration == second.duration)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    return false;
}

void Appointment::shiftBars(size_t &start, size_t &stop, string appData)
{
    start = stop;                           //makes start where stop was
    stop = appData.find('|', stop + 1);     //moves stop to the next bar
}

void Appointment::output()
{
    cout << left;
    cout << setw(40) << title;
    cout << setw(13) << getDate();
    cout << setw(10) << getStandardTime();
    cout << setw(11) << duration;
    cout << endl;
}
