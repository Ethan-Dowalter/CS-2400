/*
 *        File: lab8.cc.cc
 *      Author: Ethan Dowalter
 *        Date: October 18, 2019
 * Description: Can encrypt and decrypt a file entered by the user by shifting the characters
 *              of the file either to the right or left by an amount entered by the user
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

//Displays what the purpose of the program is to user and asks what they want to do
void displayMenu();

//Asks user to enter a new key value and returns that value
int getKeyValue();

//Encrypts a file by shifting the characters in it to the right by 'key' letters
void encryptFile(int key);

//Decrypts a file by shifting the characters in it to the left by 'key' letters
void decryptFile(int key);

int main()
{
    int choice, key;
    key = 3;    //default
    do
    {
        displayMenu();
        cin >> choice;
        if (choice == 1)
        {
            key = getKeyValue();
        }
        else if (choice == 2)
        {
            encryptFile(key);
        }
        else if (choice == 3)
        {
            decryptFile(key);
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu()
{
    cout << "\nOption 1 allows user to set a new key for encrytion/decryption (default is 3)." << endl;
    cout << "Option 2 encrypts a file entered by the user." << endl;
    cout << "Option 3 decrypts a file entered by the user." << endl;
    cout << "Option 4 exits the program." << endl;
    cout << "\nWhat do you want to do? (1,2,3,4) : ";
}

int getKeyValue()
{
    int newKey;         //new key that user will enter
    cout << "\nEnter a new key (1-10) : ";
    cin >> newKey;
    while (newKey < 1 || newKey > 10)       //sentinal loop for valid key
    {
        cout << "Enter valid a new key (1-10): ";
        cin >> newKey;
    }
    return newKey;
}

void encryptFile(int key)
{
    ifstream inStream;          //object to read from a file
    ofstream outStream;         //object to write to a file
    string inFile, outFile;     //strings to store name of files entered by user
    cout << "\nEnter the name of the file you wish to encrypt : ";
    cin >> inFile;
    inStream.open(inFile);
    while (inStream.fail())     //sentinal loop for valid input file
    {
        cout << "Enter the name of the file you wish to encrypt (must already exist) : ";
        cin >> inFile;
        inStream.open(inFile);
    }
    
    cout << "Enter the name of the file where you want the encryption to go : ";
    cin >> outFile;
    outStream.open(outFile);

    char ch, encryptedChar;
    while (inStream.get(ch))    //loop to encrypt each character of file and write it to output file
    {
        encryptedChar = ch + key;       //shifts the char right by 'key' letters
        outStream << encryptedChar;
    }

    inStream.close();
    outStream.close();          //closes input and output files
}

void decryptFile(int key)
{
    ifstream inStream;          //object to read from a file
    ofstream outStream;         //object to write to a file
    string inFile, outFile;     //strings to store name of files entered by user
    cout << "\nEnter the name of the file you wish to decrypt : ";
    cin >> inFile;
    inStream.open(inFile);
    while (inStream.fail())     //sentinal loop for valid input file
    {
        cout << "Enter the name of the file you wish to decrypt (must already exist) : ";
        cin >> inFile;
        inStream.open(inFile);
    }
    
    cout << "Enter the name of the file where you want the decryption to go : ";
    cin >> outFile;
    outStream.open(outFile);

    char ch, encryptedChar;
    while (inStream.get(ch))    //loop to encrypt each character of file and write it to output file
    {
        encryptedChar = ch - key;       //shifts char to the left by 'key' letters
        outStream << encryptedChar;
    }

    inStream.close();
    outStream.close();          //closes input and output files
}
