#include <iostream>
#include <cstdlib>
using namespace std;

void getNum (int &num);

void findMin (int &curMin, int curNum);

int main()
{
  int number,  //number read from the key board
      minimum; // minimum number out of all the numbers

  getNum(number);

  minimum = number;

  while (number >= 0 ) {
    cout<< " Number is  "<< number << endl;
    findMin(minimum, number);
    getNum(number);
  }

  cout << "\n Minimum number =  "<< minimum << endl;

  return (EXIT_SUCCESS);
}

void getNum(int &num)
{
  cout << "Enter a number and enter -1 to quit  ";
  cin >> num;
}

void findMin(int &curMin , int curNum)
{
  if (curMin > curNum) {
    curMin = curNum;
  }
}
