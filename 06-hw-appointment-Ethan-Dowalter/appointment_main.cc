/**
 *   @file: appointment_main.cc
 * @author: Ethan Dowalter
 *   @date: November 25, 2019
 *  @brief: Contains a class which stores all relavent info about an appointment
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

int main(int argc, char const *argv[]) {
    Appointment appt;
    appt.output();
    Appointment b("Meeting with boberry   |    2019  |1  1|  18|1  2: 5   9a M   |30      5");
    b.output();
    Appointment c;
    c.setYear(0x7e3);
    c.output();
    
    return 0;
}

