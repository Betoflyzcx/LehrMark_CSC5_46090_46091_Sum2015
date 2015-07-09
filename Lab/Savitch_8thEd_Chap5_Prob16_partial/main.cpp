/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 8, 2015, 9:14 PM
 * Purpose:  Given date output the day of the week
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
bool isLpYr(unsigned short);
int  gtMnVal(string,unsigned short);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    unsigned short year;
    string month;
    const int SIZE=4;
    char rday[SIZE];
    char day[SIZE-1];
    short nDay;
    
    //Input the date
    cout<<"Input date form of July 4, 2008"<<endl;
    cin>>month;
    cin>>rday;
    cin>>year;
    
    //Translate the day into a number
    if(strlen(rday)==3){
        day[0]=rday[0];
        day[1]=rday[1];
        day[2]='\0';
    }else{
        day[0]=rday[0];
        day[1]='\0';
    }
    nDay=atoi(day);
    
    //Output the date
    cout<<"The date = "<<month<<" "<<nDay<<", "<<year<<endl;
    
    //Test the Leap year
    cout<<"Year = "<<year<<" Leap Yr is "<<(isLpYr(year)?"True":"False")<<endl;
            
    //Test Get month Value
    cout<<"Month Value = "<<gtMnVal(month,year)<<endl;

    //Exit stage right!
    return 0;
}

int  gtMnVal(string month,unsigned short year){
    if(month=="January"){
        if(isLpYr(year))return 6;
        return 0;
    }else if(month=="February"){
        if(isLpYr(year))return 2;
        return 3;
    }
    return -1;
}

bool isLpYr(unsigned short year){
    return ((year%400==0)||((year%4==0)&&!(year%100==0)));
}

