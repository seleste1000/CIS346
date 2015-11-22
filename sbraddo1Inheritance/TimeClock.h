//
//  TimeClock.h
//  sbraddo1Inheritance
//
//  Created by Seleste Braddock on 10/21/15.
//  Copyright © 2015 Seleste Braddock. All rights reserved.
//

#ifndef TimeClock_h
#define TimeClock_h

#include "MilTime.h"
#include <stdio.h>

/*
 
 Design a class named TimeClock. The class should be derived from the MilTime class you designed above. 
 The class should allow the programmer to pass two times to it: starting time and ending time. 
 The class should have a member function that returns the amount of time elapsed between the two times. For example, if the starting time is 900 hours (9:00 am), and the ending time is 1300 hours (1:00 pm), the elapsed time is 4 hours. 
 Be sure to comment each line of code.
 
 */

class TimeClock : public MilTime {
    
private:
    int startTime;
    int endTime;
public:
    //constructors
    TimeClock():MilTime(){startTime = 0; endTime = 0;}
    TimeClock( int s, int e ):MilTime( s, 0 ){ startTime = s; endTime = e; }
    ~TimeClock(){ cout << "The TimeClock object has been deleted." << endl; }
    
    //accessor and mutator functions
    int getStart(){ return startTime; }
    int getEnd(){ return endTime; }
    
    void setStart( int s ){ startTime = s ; }
    void setEnd( int e ){ endTime = e; }
    
    
    int elapsedTime(); //returns elapsed time in military format

};

#endif /* TimeClock_h */
