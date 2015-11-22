//
//  MilTime.h
//  sbraddo1Inheritance
//
//  Created by Seleste Braddock on 10/21/15.
//  Copyright © 2015 Seleste Braddock. All rights reserved.
//

#ifndef MilTime_h
#define MilTime_h

#include <stdio.h>
#include <iostream>
#include "Time.h"

using namespace std;

/*
 
 Design a class called MilTime that is derived from the Time class. The MilTime class should convert time in military (24-hour) format to the standard time format used by the Time class. The class should have the following member variables:
 • milHours: Contains the hour in 24-hour format. For example, 1:00 pm would be stored as 1300 hours, and 4:30 pm would be stored as 1630 hours.
 • milSeconds: Contains the seconds in standard format. 
 The class should have the following member functions:
 • Constructor: The constructor should accept arguments for the hour and seconds, in military format. The time should then be converted to standard time and stored in the hours , min , and sec variables of the Time class.
 • setTime: Accepts arguments to be stored in the milHours and milSeconds variables. The time should then be converted to standard time and stored in the hours, min, and sec variables of the Time class.
 • getHour: Returns the hour in military format.
 • getStandHr: Returns the hour in standard format.
 
 */

class MilTime : public Time {
private:
    int milHours; //holds the time in military format
    int milSeconds; //holds the seconds in standard format
public:
    MilTime():Time(){ milHours = 0; milSeconds = 0; } //default constructor
    MilTime( int hMil, int sMil ):Time( 0, 0, sMil ){ milHours = hMil; milSeconds = sMil; } //overload constructor
    ~MilTime(){ cout << "The MilTime object has been deleted." << endl; } //destructor
    
    //accessor and mutator functions
    void setHour( int h ){ milHours = h; } //set the hour in military format
    int getHour(){ return milHours; } //return the hour in military format
    void setSecs( int s ){ milSeconds = s; } //set the seconds
    int getSecs(){ return milSeconds; } //returns the seconds
    
    
    string getStandHr(); //returns the hour in std format
    
    void setTime( int h, int s );
    
};

#endif /* MilTime_h */
