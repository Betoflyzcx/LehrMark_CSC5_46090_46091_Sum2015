/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 8, 2015, 10:45 AM
 * Purpose:  Retirement Calculator
 */

//System Library
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float salary=100000; //Average Salary in $'s
    float invRate=0.06f;//Investment Rate -> see Calif Muni Bonds
    float savReq;       //Savings required at retirement
    float pDep=0.20f;   //Of your gross Salary -> Percentage Deposited 
    float deposit;      //Yearly deposit in $'s
    float savings=0;    //Initial Savings at start of Employment
    float year=0;       //Start at year 0
    
    //Calculate required savings
    savReq=salary/invRate; //Required Savings
    deposit=pDep*salary;   //Deposit based salary
    
    //Loop to calculate when Retirement is possible
    do{
        savings*=(1+invRate);//Earning based upon investment rate
        savings+=deposit;    //Add the deposit after earning interest
        year++;
    }while(savings<savReq);//When we have enough to retire then exit the loop
    
    //Display the results
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"I can retire in "<<year<<" (years) with $"
            <<savings<<" in savings!!!"<<endl;
    
    //Exit Stage Right!
    return 0;
}