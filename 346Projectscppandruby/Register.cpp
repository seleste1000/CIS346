//
//  register.cpp
//  
//
//  Created by Mya Havard on 10/18/15.
//
//

#include <stdio.h>
#include "Register.h"
#include <ctype.h>

Register::Register() //contrustor
{
    
    InventoryItem shirt("shirt", 5.50, 10); //creates an instance of InventoryItem called shirt. The inventory has 10 shirts for $5.50 each
    InventoryItem pants("pants", 12.50, 10); //creates an instance of InventoryItem called pants. The inventory has 10 shirts for $12.50 each
    InventoryItem skirt("skirt", 15.50, 10); //creates an instance of InventoryItem called skirt. The inventory has 10 skirt for $15.50 each
    InventoryItem shoes("shoes", 20.00, 10); //creates an instance of InventoryItem called skirt. The inventory has 10 skirt for $20.00 each
    inventory[0] = shirt; //makes the first index of the inventory array the shirt object
    inventory[1] = pants; //makes the second index of the inventory array the pants object
    inventory[2] = skirt; //makes the third index of the inventory array the skirt object
    inventory[3] = shoes; //makes the fourth index of the inventory array the shoes object
}
void Register::itemquantity() //this member function allows the user to decide which item they would like to purchase and the quantity. It includes user validation and repeats until for the user to add as many items to their purchase as she would like
{
    
    string item; //string that holds the name of the object the user would like to purchase
    itemindex = 0; //sets the index to 0
    char quant[100];
    int quantity; //holds the quantity the user would like
    bool instock; //bool if the item is in stock
    string ans; //holds the answer for repeating
    int j=0;//to keep track of the item in which the user would like to purchase
    cout<<"WELCOME TO OUR STORE!"<<endl;
    do{//this loop continues while the user would like to continue making new purchases
        
        bool found=false; //bool if the user defined item is in the inventory
        do{//this loop continues while the user is being asked to input the item they would like to purchase from the store
            
            cout<<"Currently we have \n"; //displays the quantity of the items in the inventory
            for(int item = 0; item < 4; item++){ //loops through the inventory array
                
                cout<<inventory[item].getUnits(); //prints the number of units for each element
                cout<<" " << inventory[item].getDescription() << " in stock."<<endl; //prints the description
            }
            
            cout << "Please enter the item you would like to purchase. \nYour options are Shirt, Pants, Skirt, or Shoes" << endl; //prompts user to input which item they would like
            cin >> item; //getting item form user
            
            for(int letter = 0; letter< item.length(); letter++){// going through each letter of the word
                item[letter] = tolower(item[letter]); //changing the letter to lowercase if it is not so already, if so then it does nothing
            }
            
            for (int k=0; k < 4; k++)//checkng to see if what the user asked for is in our store
            {
                if (inventory[k].getDescription() == item) //if the user defined item is in a description of one of the inventory elements
                {
                    itemindex = k; //holds the index of the found item
                    found = true; //makes found true to break out of the do whle loop
                }
            }
        } while(!found);//if what they user asked for is not in the store then we should ask the user again to tell us what they want
        //bool check = false;
        cout << "Please enter the quantity you would like of this item" << endl; //prompts user to enter the quantity
        cin >>quantity; //inputs quantity
        /*do {
        int i=0; //index for the quant string array
        while(quant[i] != '\n' && check == true) //while it is not the end of the string
        {
            if(isdigit(quant[i]) || quant[i] == '\n')
            {
                check = true;
                cout << "bye /" << quant[i] << "/"<< endl;
                i++; //increments the index
            }
            else
            {
                cout << "bye /" << quant[i] << "/"<< endl;
                //check = false;
            }
            
        }
            if (check == true)
            {
                quantity = atoi(quant);
            }
            else
            {
                cout << "Please only enter an INTEGER" << endl;
                cin >> quant;
            }
        }while (check == false);*/
        while ( (quantity < 0 && quantity > 10) || (quantity > inventory[itemindex].getUnits()))//validating that the user entered in the correct amount in which they would like to buy. Will repeat until a given a valid input
        {
            cout << "You either gave a negative number or we do not have that many units in stock. \nPlease enter a lower, positive quantity" << endl; //tells the user what is wrong with their input and prompts the user to enter a new input
            cin >> quantity; //inputs the quantity
        }
        
        inventory[itemindex].setUnits((inventory[itemindex].getUnits()-quantity)); //updates the quantity of that item in the inventory
        if (order.count(itemindex) == 0){ //counting the number of times the key has been used to see if it is already there
            order.insert ( std::pair<int,int>(itemindex, quantity) ); //if not add to it
            //j++;
        }
        else{
            cout<<"You are adding more of an item you have already asked for before"<<endl;//let the user know that she is buying more of an item
            order[itemindex] += quantity; //adding to the number ordered of the item
        }
        
        cout << "Would you like to purchase another item?(yes or no)"; //asks user if they would like to make another purchase
        cin >> ans; //gets the users answer
        while (ans != "yes" && ans != "no") //if the answer is not yes or no
        {
            cout << "Please only enter either yes or no" << endl; //prompts user to enter correct answer
            cin >> ans; //user input
        }
        
    }while(ans == "yes"); //repeats if user would like to enter more items
}

void Register::subtotal1() //calculates the subtotal, tax, and purchase total
{
    subtotal=0; //sets the subtotal to 0
    for (int k=0; k < 4;k++) //for each item in the inventory array
    {
        if(order.count(k) != 0) //if count of that key in the map is not 0
        {
            subtotal+=(inventory[k].getCost() * 1.3)*(order[k]); //add the price (1.3 times the given price) times the quantity specified by the user to the subtotal
        }
    }
    tax = subtotal*0.06; //determies the tax of the subtotal by multiplying the subtotal by 0.06
    purchasetotal = tax+subtotal; //sets the purchase total to sum of the tax and the subtotal
}
void Register::display() //displays the information about the user's order
{
    cout << cout <<"You purchase included: "; //begins to print the user's order
    for (int k=0; k < 4;k++) //goes through each element of the inventory array
    {
        if(order.count(k) != 0) //if that key appears at least once in the map
        {
            cout << endl << order[k] << " " << inventory[k].getDescription() <<"(s)" << endl; //prints the number of items for each key in the map
        }
    }
    cout << endl;
    cout << "Subtotal: $" << subtotal << endl; //prints the subtotal
    cout << "Taxes: $" << tax << endl; //prints the taxes
    cout << "Purchase Total: $" << purchasetotal << endl; //prints the purchase total
    order.clear(); //clears the map
    
}