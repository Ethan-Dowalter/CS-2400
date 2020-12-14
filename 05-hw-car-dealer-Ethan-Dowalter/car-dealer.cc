/**************************************************************************************************
*        @file: car-dealer.cc
*      @author: Ethan Dowalter
*        @date: November 6, 2019
*       @brief: Presents user with a menu and allows user to order a car with a variety of options
**************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;


/**  
 *   Function - loadVectors
 *            > loads the vectors from an input file
 *   @param prices - additional price from an option/add on
 *   @param options - all possible add ons to the car
 */
void loadVectors(vector <double> &prices, vector <string> &options);


/**  
 *   Function - orderInfo
 *            > displays selected model, selected options, and total price of order
 *   @param model - car model: E, L, or X
 *   @param order - selected options/add ons for car
 *   @param total - total price of order: model base price + any add ons
 */
void orderInfo(char model, vector <string> order, double total);


/**  
 *   Function - printMenu
 *            > displays options for user on screen
 */
void printMenu();


/**  
 *   Function - selectModel
 *            > asks user which model they want
 *   @return - E, L, or X for the car model
 */
char selectModel();


/**  
 *   Function - displayOptions
 *            > displays all possible options that user can add to car order
 *   @param prices - additional price from an option/add on
 *   @param options - all possible add ons to the car
 */
void displayOptions(vector <double> prices, vector <string> options);


/**  
 *   Function - addOption
 *            > allows user to add on one of the options to the car order
 *   @param model - car model: E, L, or X
 *   @param options - all possible add ons to the car
 *   @param order - selected options/add ons for car
 */
void addOption(char model, vector <string> options, vector <string> &order);


/**  
 *   Function - removeOption
 *            > allows user to remove an option they previously added to the car order
 *   @param model - car model: E, L, or X
 *   @param order - selected options/add ons for car
 */
void removeOption(char model, vector <string> &order);


/**  
 *   Function - cancelOrder
 *            > allows user to cancel current order and restart by reseting all values
 *   @param model - car model: E, L, or X
 *   @param order - selected options/add ons for car
 *   @param total - total price of order: model base price + any add ons
 */
void cancelOrder(char &model, vector <string> &order, double &total);


/**  
 *   Function - lowerCaseVector
 *            > takes a vector of strings and converts it to only lowercase letters
 *   @param vec - vector to be converted to lowercase letters
 */
void lowerCaseVector(vector <string> &vec);


/**  
 *   Function - getTotal
 *            > calculates total cost of order
 *   @param model - car model: E, L, or X
 *   @param order - selected options/add ons for car
 *   @param options - all possible add ons to the car
 *   @param prices - additional price from an option/add on
 *   @return - total price of order
 */
double getTotal(char model, vector <string> order, vector <string> options, vector <double> prices);


/*******************
    Main Function
 *******************/ 

int main(int argc, char const *argv[])
{
    ///Get options from file
    vector <string> options;                        //vector to store options
    vector <double> prices;                         //vector to store prices of options
    loadVectors(prices, options);
    vector <string> order;                          //vector to store options user wants to add to car
    double total;                                   //total price of order
    

    char choice;                                     //user entered choice for the menu
    char model = 'a';                               //model user wants to order
    do
    {    
        ///Menu
        total = getTotal(model, order, options, prices);
        orderInfo(model, order, total);
        printMenu();
        cin >> choice;
        cin.ignore(1000, '\n');                     //makes sure only to take first char
        while (choice < '1' || choice > '6')
        {
            cout << "\nPlease enter a valid choice." << endl;
            orderInfo(model, order, total);
            printMenu();
            cin >> choice;
        }

        ///Process which option was entered
        switch (choice)
        {
            case '1':
                model = selectModel();
                break;
            case '2':
                displayOptions(prices, options);
                break;
            case '3':
                addOption(model, options, order);
                break;
            case '4':
                removeOption(model, order);
                break;
            case '5':
                cancelOrder(model, order, total);
                break;
        }
    } while (choice != '6');

    return 0;
}

/**************************
    Function Definitions
 **************************/ 

void loadVectors(vector <double> &prices, vector <string> &options)
{
    ///Open file and check for errors
    ifstream inStream;
    inStream.open("options.txt");
    if (inStream.fail())
    {
        cout << "\nError. Could not open input file.\n" << endl;
        exit(0);
    }

    ///Load vectors with data
    string option;                                  //string to get the option into vector
    double price;                                   //double to get the price into vector
    int count = 0;                                  //counts the number of options
    while (inStream >> price && getline(inStream, option))
    {
        option.erase(0,1);                          //makes sure not to save the space between the price and option from input file
        prices.push_back(price);
        options.push_back(option);
        count++;
    }

    ///Check for too many options
    if (count > 30)
    {
        cout << "\nError. Input file contains too many options.\n" << endl;
        exit(0);
    }

    ///Close file
    inStream.close();
}


double getTotal(char model, vector <string> order, vector <string> options, vector <double> prices)
{
    double total = 0;           //total price of order
    switch(model)               //base price of the model
    {
        case 'E':
            total += 10000;
            break;
        case 'L':
            total += 12000;
            break;
        case 'X':
            total += 18000;
            break;
    }

    for (size_t i = 0; i < order.size(); i++)           //additional cost from added options
    {
        for (size_t j = 0; j < options.size(); j++)
        {
            if (order[i] == options[j])
            {
                total += prices[j];
            }
        }
    }

    return total;
}


void orderInfo(char model, vector <string> order, double total)
{
    cout << endl;
    if (model != 'E' && model != 'L' && model != 'X')
    {
        cout << "No model selected" << endl;
    }
    else
    {
        cout << "Model : " << model << endl;

        cout << "Options : ";
        if (order.size() == 0)
        {
            cout << "None" << endl;
        }
        else if (order.size() <= 6)
        {
            size_t i;
            for (i = 0; i < order.size() - 1; i++)
            {
                cout << order[i] << ", ";
            }
            cout << order[i] << endl;
        }

        cout << "Total price : $" << total << endl;
    }
    
}


void printMenu()
{
    cout << endl;
    cout << "1. Select a model (E, L, X)" << endl;
    cout << "2. Display available options and prices" << endl;
    cout << "3. Add an option" << endl;
    cout << "4. Remove an option" << endl;
    cout << "5. Cancel order" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter choice : ";
}


char selectModel()
{
    char model;                         //which model user wants
    cout << "\nWhich model do you want? (E, L, X) : ";
    cin >> model;
    cin.ignore(1000, '\n');             //makes sure only to take first char
    model = toupper(model);
    while (model != 'E' && model != 'L' && model != 'X')
    {
        cout << "Enter a valid model. (E, L, X) : ";
        cin >> model;
        cin.ignore(1000, '\n');         //makes sure only to take first char
        model = toupper(model);
    }
    return model;
}


void displayOptions(vector <double> prices, vector <string> options)
{
    cout << endl;
    cout << "Model E base price : $10,000.00" << endl;
    cout << "Model L base price : $12,000.00" << endl;
    cout << "Model X base price : $18,000.00" << endl;
    cout << endl;
    cout << "Available options : ";
    string str;                         //string to display options
    string price;                       //string to display prices
    for (size_t i = 0; i < options.size(); i++)
    {
        if (i % 3 == 0)
        {
            cout << endl;                           //new line every three options
        }
        price = to_string(prices.at(i));            //convert price double to a string
        str = options[i] + "($" + price + ")";      //make each options one combined string
        str.erase(str.size() - 5, 4);               //erase extra 0's saved from to_string
        cout << left << setw(30) << str;            //print info
    }
    cout << endl;
}


void addOption(char model, vector <string> options, vector <string> &order)
{
    ///Check for model and too many options
    if (model != 'E' && model != 'L' && model != 'X')
    {
        return;
    }
    else if (order.size() >= 6)
    {
        cout << "\nYou cannot have more than 6 options selected." << endl;
        return;
    } 

    char ch;                                    //character to read user input
    string input;                               //user input converted to lowercase
    bool isValidOption = false;                 //once input is valid, is set to true
    bool isRepeatOption = false;                //if user enters an option already selected, set to true
    vector <string> lowerCaseOptions;           //options vector converted to lowercase
    vector <string> lowerCaseOrder;             //order vector converted to lowercase

    ///Convert options and order vectors to lowercase
    lowerCaseOptions = options;
    lowerCaseVector(lowerCaseOptions);
    lowerCaseOrder = order;
    lowerCaseVector(lowerCaseOrder);

    ///Get user input
    do
    {   
        cout << "\nWhich option would you like to add? (Enter 'cancel' to return to menu) : ";
        cin.get(ch);
        while (ch != '\n')
        {
            input += tolower(ch);           //converts user input to lowercase
            cin.get(ch);
        }

        ///Lets user go back to menu if they enter "cancel"
        if (input == "cancel")
        {
            break;
        }

        ///Check if user input is valid
        if (order.size() > 0)           //check for duplicate option
        {
            lowerCaseOrder = order;
            lowerCaseVector(lowerCaseOrder);
            for (size_t i = 0; i < lowerCaseOrder.size(); i++)
            {
                if (input == lowerCaseOrder.at(i))
                {
                    isRepeatOption = true;
                    cout << "You already have that option selected. ";
                    break;
                }
            }
        }

        for (size_t i = 0; i < options.size(); i++)
        {
            if (input == lowerCaseOptions[i] && !isRepeatOption)        //if not duplicate and valid, add to order
            {
                order.push_back(options[i]);
                isValidOption = true;
                break;
            }
        }
        
        ///Error message and reset variable
        if (!isValidOption)
        {
            cout << "Please enter a valid option.";
        }
        input = "";                                     //clears string for next loop
        isRepeatOption = false;                         //resets flag for next loop
    } while (!isValidOption);
}


void removeOption(char model, vector <string> &order)
{
    ///Check for model and too few options
    if (model != 'E' && model != 'L' && model != 'X')
    {
        return;
    }
    else if (order.size() < 1)
    {
        return;
    } 

    char ch;                                    //character to read user input
    string input;                               //user input converted to lowercase
    vector <string> lowerCaseOrder;             //order vector converted to lowercase
    bool isValidOption = false;                 //if input is valid, is set to true

    ///Convert order into lowercase
    lowerCaseOrder = order;
    lowerCaseVector(lowerCaseOrder);

    ///Get user input
    cout << "\nWhich option would you like to remove? : ";
    cin.get(ch);
    while (ch != '\n')
    {
        input += tolower(ch);               //converts user input to lowercase
        cin.get(ch);
    }

    ///Check if user input is valid
    for (size_t i = 0; i < lowerCaseOrder.size(); i++)
    {
        if (input == lowerCaseOrder[i])
        {
            order.erase(order.begin() + i);       //remove option from order
            isValidOption = true;
            break;
        }
    }

    ///If input is invalid, ignore it
    if (!isValidOption)
    {
        cout << "Invalid option. Nothing removed." << endl;
    }
}


void cancelOrder(char &model, vector <string> &order, double &total)
{
    model = 'a';                                        //resets all values
    order.clear();
    total = 0;
}


void lowerCaseVector(vector <string> &vec)
{
    string str;                                         //string for converting vector to lowercase
    vector <string> lowerCase;                          //vector for storing lower case version of input vector

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec[i].length(); j++)
        {
            str += tolower(vec[i].at(j));               //takes strings from vector and converts them to lowercase
        }
        lowerCase.push_back(str);                       //vector with only lowercase
        str = "";                                       //clears contents of string before next loop
    }

    vec.swap(lowerCase);                                //swaps vectors so function returns the same vector but lowercase
}