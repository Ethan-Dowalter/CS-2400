/*
 *        File: main.cc
 *      Author: Ethan Dowalter
 *        Date: December 6, 2019
 * Description: main function for testing a class, "my_int"
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "my_int.h"
using namespace std;

int main()
{ 
  my_int value1;
     
  value1.input(cin);  
 
  value1.output(cout);

  if (is_prime(value1))
    cout<<"  is a prime number  \n";
  else
   cout<<" is not a prime number \n";
 
  my_int a,b;
  a.input(cin);
  b.input(cin);
  if (a > b)
  {
    cout << a.get_int() << " is greater than " << b.get_int() << endl;
  }
  else
  {
    cout << a.get_int() << " is not greater than " << b.get_int() << endl;
  }
  
  return 0;
}