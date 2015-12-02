//convert the userinput to lower to eliminate any confusion

//mapping inventory index of the item to and array with the quantity user wants


//#include "InventoryItem.h" //includes the header file for the InventoryItem class
#include <map> //using a map throughout the code
#include <iostream> 
#include "InventoryItem.h"
using namespace std;
map <int, int> order; //creating a map to hold the what the user wanted to order and how much of it they wanted

class Register //creates class called register
{
    
private: //private members
    
    InventoryItem inventory[4]; //an array of type InventoryItem that holds all of the item sin the inventory
    int itemindex; //index of the item that is being referenced throughout the code
    double subtotal; //variable that holds the subtotal
    double tax; //variable that holds the tax
    double purchasetotal; //the total
    string item; //string that holds the name of the object the user would like to purchase

public: //public members
    Register(); //the constructor that sets the elements of the inventory array that holds the stores inventory
    void itemquantity(); //contians all user input and prompts user to enter which items she would like to purchae and the quantity
    void subtotal1(); //calculates the subtotal, tax, and purchase total
    void display(); //displays all the information about the users purchase
    void displayitems();
    bool validitem(string);
    bool validquantity(string);
    bool itemavail(int);
    void updateinvent(int);
    void displayorder();
    

    ~Register(); //deconstructor
};