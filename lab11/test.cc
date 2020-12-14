#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    const int SIZE = 6;
    int graph[SIZE] = {5,3,2,7,1,9};
    for (int i = 0; i < SIZE; i++)
    {
        cout << setfill('-') << left << setw(5) << graph[i];
        for (int j = 0; j < graph[i]; j++)
        {
            cout << setw(2) << '*';
        }
        cout << endl;
    }
    return 0;
}