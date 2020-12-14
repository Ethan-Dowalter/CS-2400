/*
 *        File: my_int.h
 *      Author: Ethan Dowalter
 *        Date: December 6, 2019
 * Description: class definition for the my_int class
 */

#ifndef MY_INT_H
#define MY_INT_H
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//*********************************************************
// Function: is_prime
// Purpose:  object num contains a valid positive value
//           returns true if num is prime; otherwise
//           returns false
// Params:   num  - the value to be checked for prime
// Calls:    sqrt
// Uses:     cmath 
//*********************************************************
bool is_prime(const my_int& num);

class my_int
{
public:
  //*********************************************************
  // Function: my_int
  // Purpose:  Constructor initializes the val to x
  // Params:   x - the value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
  my_int(int x);   

  //*********************************************************
  // Function: my_int       
  // Purpose:  Constructor initializes the val to 0      
  // Params:   none      
  // Calls:    none                                    
  // Uses:     none           
  //*********************************************************
  my_int();       

  //*********************************************************
  // Function: set
  // Purpose:  Sets the val to x
  // Params:   x - the new value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
  void set(int x); 

  //*********************************************************************
  // Function: input
  // Purpose:  reads and stores a value from inp. if inp is a input 
  //           stream, then inp is already connected to a file.User enters 
  //           a value and ask the user to re-enter the data if the
  //           user enters an incorrect value.
  // Params:   inp -- the input stream
  // Calls:    none
  // Uses:     istream
  //*********************************************************************
  void input(istream& inp);  
 
  //*********************************************************************
  // Function: output
  // Purpose:  display the val on fout. if fout is a  output stream
  //           then fout is already  connected to a file
  // Params:   fout -- the output stream
  // Calls:    none
  // Uses:     ostream
  //*********************************************************************
  void output(ostream& fout) const;

  //*********************************************************
  // Function: get_int
  // Purpose:  returns the val
  // Params:   none
  // Calls:    none
  // Uses:     none
  //*********************************************************
  int get_int() const;

  //*********************************************************
  // Function: operator >
  // Purpose:  greater than operator for ADT my_int
  // Params:   num1 -- first number being compared
  //           num2 -- second number being compared
  // Calls:    none
  // Uses:     none
  //*********************************************************
  friend bool operator >(my_int& num1, my_int& num2);

private:
  int val;  // Variable to hold value for class
};
#endif