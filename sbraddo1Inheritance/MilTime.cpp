//
//  MilTime.cpp
//  sbraddo1Inheritance
//
//  Created by Seleste Braddock on 10/21/15.
//  Copyright © 2015 Seleste Braddock. All rights reserved.
//

#include "MilTime.h"

string MilTime::getStandHr(){
    
    string stdTime;
    
    //find the amount of hours
    int hours = milHours/100;
    int minutes = (milHours - hours*100);
    
    int stdHrs = hours%12;
    
    //displaying hours, minutes, and seconds
    if (hours > 12) {
        if (minutes >= 0 && minutes < 10){
            cout << hours%12 << ":0" << minutes <<" pm" << endl;
        } else {
            cout << hours%12 << ":" << minutes <<" pm" << endl;
        }
    } else if (hours == 0) {
        if (minutes >= 0 && minutes < 10){
            cout << "12:0" << minutes <<" am" << endl;
        } else {
            cout << "12:" << minutes <<" am" << endl;
        }
    } else {
        if (minutes >= 0 && minutes < 10){
            cout << hours << ":0" << minutes <<" am" << endl;
        } else {
            cout << hours << ":" << minutes <<" am" << endl;
        }
    };
    
    //string containing standard time
    stdTime = to_string(hours) + ":";
    if (minutes >= 0 && minutes < 10){
        stdTime += "0" + to_string(minutes) + ":";
    } else {
        stdTime += to_string(minutes) + ":";
    }
    if (milSeconds >= 0 && milSeconds < 10){
        stdTime += "0" + to_string(milSeconds);
    } else {
        stdTime += to_string(milSeconds);
    }
    
    //cout << stdTime << endl;
    
    return stdTime;
}

void MilTime::setTime( int h, int s ){
    
    //find the amount of hours
    int hours = milHours/100;
    int minutes = (milHours - hours*100);
    
    //int stdHrs = hours%12;
    
    //displaying hours, minutes, and seconds
    if (hours > 12) {
        if (minutes >= 0 && minutes < 10){
            cout << hours%12 << ":0" << minutes <<" pm" << endl;
        } else {
            cout << hours%12 << ":" << minutes <<" pm" << endl;
        }
    } else if (hours == 0) {
        if (minutes >= 0 && minutes < 10){
            cout << "12:0" << minutes <<" am" << endl;
        } else {
            cout << "12:" << minutes <<" am" << endl;
        }
    } else {
        if (minutes >= 0 && minutes < 10){
            cout << hours << ":0" << minutes <<" am" << endl;
        } else {
            cout << hours << ":" << minutes <<" am" << endl;
        }
    };
    
    //changing values of Time class member vars
    sec = this->milSeconds;
    min = minutes;
    hour = hours;
    
}














