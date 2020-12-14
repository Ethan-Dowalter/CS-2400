#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
// First sum
int sum(int x, int y);
// Second sum
double sum(double x, double y);
// Third sum
double sum(int x, double y); 
// Fourth sum
int sum(int x, int y, int z); 
// Fifthsum
double sum(double x, double y, double z); 
// Sixth sum
int sum(int a, int b, int c, int d); 
// Seventh sum
double sum(double a, double b, double c, double d); 
// Eighthsum
double sum(int a, double b, int c, double d, int e, double f);
// Ninth sum
double sum(double a, double b, double c, double d, double e, double f);

int main(){
    int n1= 2;
    int n2= 4;
    int n3= 6;
    double  m1= 1.5;
    double  m2= 123.45;
    double m3= 0.56;
    cout <<sum(n1,n2) << endl;
    cout << sum(n1,m1) << endl;
    cout << sum(n1,n2,n3,10) << endl;
    cout << sum(n1,m1,n2,m2,n3,m3) << endl;
    cout << sum(5.5,6.5,10.0,17.0,4.2,11.5) << endl;
    return (EXIT_SUCCESS); 
}
// First sum
int sum(int x, int y) {return (x+y);}
// Second sum
double sum(double x, double y) {return (x+y);}
// Third sum
double sum(int x, double y) {return (x+y);}
// Fourth sum
int sum(int x, int y, int z) {return (sum(x,y) + z);}
// Fifth sum
double sum(double x, double y, double z) {return (x + sum(y,z));}
// Sixth sum
int sum(int a, int b, int c, int d) {return (sum(a,b) + sum(c,d));}
// Seventh sum
double sum(double a, double b, double c, double d) {return (sum(a,b) + sum(c,d));}
// Eighth sum
double sum(int a,double b,int c, double d,int e,double f)
{return (sum(a,c,e) + sum(b,d,f));}
// Ninth sum
double sum(double a, double b, double c, double d, double e, double f)
{return (sum(a,c,b,d) +sum(e,f));}