//
//  TimeClock.cpp
//  sbraddo1Inheritance
//
//  Created by Seleste Braddock on 10/21/15.
//  Copyright © 2015 Seleste Braddock. All rights reserved.
//

#include "TimeClock.h"


int TimeClock::elapsedTime(){
    
    int elapsedTime;
    int elapsedMinutes, elapsedHours;
    
    //convert starting and finishing times to hours and minutes
    int endHours = endTime/100;
    int endMinutes = endTime%100;
    int startHours = startTime/100;
    int startMinutes = startTime%100;
    
    
    if (endMinutes >= startMinutes) {
        elapsedMinutes = endMinutes - startMinutes;
        elapsedHours = endHours - startHours;
        
    } else {
        elapsedMinutes = startMinutes - endMinutes;
        elapsedHours = endHours - startHours - 1;
    }
    
    
    
    cout << "Elapsed time: " << elapsedHours << " hour(s) " << elapsedMinutes << " minute(s)" << endl ;
    
    elapsedTime = elapsedHours*100 + elapsedMinutes;
    
    return elapsedTime;
    
}

