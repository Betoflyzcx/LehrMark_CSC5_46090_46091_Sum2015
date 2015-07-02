/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 1, 2015, 7:36 PM
 * Purpose:  Upper/Lower Case
 */

//System Library
#include <iostream>
using namespace std;

//User Library

//Global Constant

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    //Declare variables
    char letter1='A';
    char letter2='b';
    
    //Output the initial conditions
    cout<<"Before adding or subtracting 32"<<endl;
    cout<<"Letter 1 = "<<letter1<<endl;
    cout<<"Letter 2 = "<<letter2<<endl;
    
    //Change the case
    letter1+=32;
    letter2-=32;
    
    //Output the modified letters
    cout<<"After adding or subtracting 32"<<endl;
    cout<<"Letter 1 = "<<letter1<<endl;
    cout<<"Letter 2 = "<<letter2<<endl;

    //Exit stage right!
    return 0;
}