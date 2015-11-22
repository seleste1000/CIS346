#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
using namespace std;

class InventoryItem //creates class called InventoryItem
{
private:
	string description;	// The item description
	double cost;		// The item cost
	int units;          // Number of units on hand

public:
   // Constructor #1
   InventoryItem() //default constructor
	  { description = ""; cost = 0.0; units = 0; } //assigns values to each member variable

   // Constructor #2
   InventoryItem(string desc) //overload constructor
	  { description = desc; cost = 0.0; units = 0; } //assigns description to desc and the cost and units to 0

   // Constructor #3
   InventoryItem(string desc, double c, int u) //overload constructor
	  { description = desc; cost = c; units = u; } //sets each member variable to a parameter

   // Mutator functions
   void setDescription(string d) //mutator function for description
	  { description = d; } //sets descriptions to the parameter d

   void setCost(double c) //mutator function for cost
      { cost = c; } //sets cost to the parameter c
      
   void setUnits(int u) //mutator function for units
      { units = u; } //sets units to the parameter u

   // Accessor functions
   const string getDescription() const //accessor function for description
      { return description; } //returns the description
         
   double getCost() const //accessor function for cost
      { return cost; } //returns the cost

   int getUnits() const //accessor function for units
      { return units; } //returns the units
};

#endif