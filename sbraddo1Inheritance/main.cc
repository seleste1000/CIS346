//
//  main.cpp
//  sbraddo1Inheritance
//
//  Created by Seleste Braddock on 10/19/15.
//  Copyright © 2015 Seleste Braddock. All rights reserved.
//

#include <iostream>
#include "TimeClock.h"
#include "MilTime.h"
#include "Time.h"

using namespace std;

int main() {
    
    bool askAgain = false; //initializing bool that will indicate whether the user's input is valid
    //MilTime milTime; //holds the military time object
    
    //starting time
    int milHrs1 = 0; //initializing integer that holds military format in hrs
    int milSecs1 = 0; //initializing integer that will hold seconds
    
    //ending time
    int milHrs2 = 0; //initializing integer that holds military format in hrs
    int milSecs2 = 0; //initializing integer that will hold seconds
    
    do{
        
        MilTime timeStart; //holds the starting MilTime object
        MilTime timeEnd; //holds ending MilTime object
        TimeClock timeclock; //initializing timeClock object
        
        do{ //getting milHrs1
            //ask user to enter time in military format
            
            askAgain = false;
            
            cout << "Enter the starting time in military format. (i.e. 2345, 1800, 0900, 0003)" << endl;
            cin >> milHrs1; //takes in military time in hrs
            
            if (milHrs1 > 2359 || milHrs1 < 0) { //input validation
                cout << "Military time is between 0000 hours and 2359 hours. Please enter a valid time." << endl;
                askAgain = true; //the user will be asked for the military time again
            }
            
        }while(askAgain);
        
        timeStart.setHour(milHrs1); //setting the hours
        
        do{ //getting milSecs
            
            askAgain = false;
        
            cout << "Enter the amount of seconds." << endl;
            cin >> milSecs1;
            
            if (milSecs1 > 59 || milSecs1 < 0) { //input validation
                cout << "Seconds can only run between 0 and 59. Please enter a different value." << endl;
                askAgain = true;
            }
            
        }while(askAgain);
        
        timeStart.setSecs(milSecs1); //setting the seconds
        
        cout << "Starting time: " << timeStart.getStandHr() << endl;
        
        do{ //getting milHrs2
            //ask user to enter time in military format
            
            askAgain = false;
            
            cout << "Enter the ending time in military format. (i.e. 2345, 1800, 0900, 0003)" << endl;
            cin >> milHrs2; //takes in military time in hrs
            
            if (milHrs2 > 2359 || milHrs2 < 0) { //input validation
                cout << "Military time is between 0000 hours and 2359 hours. Please enter a valid time." << endl;
                askAgain = true; //the user will be asked for the military time again
            }
            
        }while(askAgain);
        
        timeEnd.setHour(milHrs2); //setting the hours
        
        do{ //getting milSecs
            
            askAgain = false;
            
            cout << "Enter the amount of seconds." << endl;
            cin >> milSecs2;
            
            if (milSecs2 > 59 || milSecs2 < 0) { //input validation
                cout << "Seconds can only run between 0 and 59. Please enter a different value." << endl;
                askAgain = true;
            }
            
        }while(askAgain);
        
        timeEnd.setSecs(milSecs2); //setting the seconds
        
        cout << "Ending time: " << timeEnd.getStandHr() << endl;
        
        timeclock.setStart(timeStart.getHour()); //setting the start time
        timeclock.setEnd(timeEnd.getHour()); //setting the end time
        
        
        //displaying the start, end, and elapsed time
        cout << "Starting time: " << timeStart.getStandHr() << endl;
        cout << "Ending time: " << timeEnd.getStandHr() << endl;
        timeclock.elapsedTime();
        //cout << "Elapsed time: " << timeclock.elapsedTime()/100 /*isolates number of hours*/ << " hour(s) " << timeclock.elapsedTime()%100 << " minute(s)" /*isolates number of minutes*/ << endl ;
        
        
        bool thisLoop = false; //for the do-while loop below
        
        do{
            cout << "Do you want to convert another time? (enter y/n)" << endl;
            string ans;
            cin >> ans;
            
            //input validation
            if (ans == "y" || ans == "Y"){
                askAgain = true;
            } else if (ans == "n" || ans == "N"){
                cout << "The program will exit" << endl;
                return 0;
            } else {
                thisLoop = true;
                cout << "Try again" << endl;
            }
            
        }while(thisLoop);
    
    }while(askAgain);
    
    
    return 0;
}
