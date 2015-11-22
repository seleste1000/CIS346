#include "Register.cpp"
#include <iostream>
using namespace std;

/*Cash Register
Design a CashRegister class that can be used with the InventoryItem class (See Dr. Marshall for this class’s header file). The CashRegister class should perform the following:
1. Ask the user for the item and quantity being purchased.
2. Get the item’s cost from the InventoryItem object.
3. Add a 30% profit to the cost to get the item’s unit price.
4. Multiply the unit price times the quantity being purchased to get the purchase subtotal.
5. Compute a 6% sales tax on the subtotal to get the purchase total.
6. Display the purchase subtotal, tax, and total on the screen.
7. Subtract the quantity being purchased from the onHand variable of the InventoryItem
class object.
Implement both classes in a complete program. Feel free to modify the InventoryItem class in any way necessary.
Input Validation: Do not accept a negative value for the quantity of items being purchased.*/




int main() //main
{
    string response; //string for user's input
    Register reg; //creates an instance of the Registe class
    do{ //do while loop that loops as long as the user would like to make another purchase
    reg.itemquantity(); //calls the itemquantity member function that determines what the user would like to purchase and the quantity of those items
    
    reg.subtotal1(); //calculates the subtotal, tax, and purchase total based on the user input in the itemquantity function
    reg.display(); //displays all of the infmomation determiend by the class
    cout << "\n\nWould you like to start a new order?"<<endl; //asks user if the would like another order
    
    cin>>response; //inputs a response
    while (response != "yes" && response != "no") //while the user input was invalid
    {
        cout << "Please only enter either yes or no" << endl; //prompts the usr for another response
        cin >> response; //user enteres the reponse
    }


    }while(response == "yes"); //continues while the user enters yes for response

    return 0; //end of the main function
}