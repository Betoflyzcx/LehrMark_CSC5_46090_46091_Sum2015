/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 1, 2015, 10:20 PM
 * Purpose:  Approximate PI
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const double PI=4*atan(1.0);

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare and initialize variables
    int nTerms=200000000;
    long double apprxPI=1.0L;
    
    //Now calculate PI with a for-loop
    for(int i=3,nTerm=1;nTerm<=nTerms;i+=4,nTerm+=2){
        apprxPI+=(-1.0L/i+1.0L/(i+2));
    }
    apprxPI*=4;
    
    //Output the results and compare
    cout<<fixed<<showpoint<<setprecision(15);
    cout<<"Exact Value of PI = "<<PI<<endl;
    cout<<"The approximate value of PI = "<<apprxPI<<endl;
    
    //Exit stage right!
    return 0;
}