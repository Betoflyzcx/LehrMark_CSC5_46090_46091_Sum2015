/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 14, 2015, 12:11 PM
 * Purpose:  Simple Sort step by step
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array * filAray(int);
void prntAry(Array *,int);
void swap(Array *,int,int);
void swapMin(Array *,int);
void markSrt(Array *);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=200;
    Array *array=filAray(size);
    
    //Output the initial array
    prntAry(array,20);
    
    //Process the inputs
    markSrt(array);
    
    //Output the results
    prntAry(array,20);

    //Exit Stage Right
    delete array;
    return 0;
}

/**************************************************
 *                Mark Sort                       *
 **************************************************
 * Purpose:  To sort any integer array
 * Input:
 *    n-> The size of the array
 * Input-Output:
 *    a-> The sorted integer Array
 */
void markSrt(Array *a){
    //Loop and sort every position
    for(int pos=0;pos<a->getSize()-1;pos++){
        swapMin(a,pos);
    }
}

/**************************************************
 *                   SwapMin                      *
 **************************************************
 * Purpose:  To place the minimum at the top of the
 *           list.
 * Input:
 *    n-> Size of the array/list
 *    pos->Position to place the minimum
 * Input-Output:
 *    a-> An integer array/list
 */
void swapMin(Array *a,int pos){
    //Loop through the list starting at pos+1
    for(int i=pos+1;i<a->getSize();i++){
        //Place smallest value at the position pos
        if(a->getData(pos)>a->getData(i))swap(a,pos,i);
    }
}

/**************************************************
 *                     Swap                       *
 **************************************************
 * Purpose:  To swap by logical operations two values
 * Input-Output:
 *    a-> An integer value
 *    b-> An integer value
 */
void swap(Array *a,int pos,int i){
    //Perform the logical in-place swap
    int temp=a->getData(pos);
    a->setData(pos,a->getData(i));
    a->setData(i,temp);
}

/**************************************************
 *                Print Array                      *
 **************************************************
 * Purpose:  To print an integer array with any
 *           number of columns
 * Input:
 *    n-> The size of the array
 *    a-> The Array Class
 *    nCols->Number of columns to display the array.
 * Output:
 *    On Screen
 */
void prntAry(Array *a,int nCols){
    //Separate outputs with a line
    cout<<endl;
    //Loop and output every element in the array
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        //When column is reached go to next line
        if((i%nCols)==(nCols-1))cout<<endl;
    }
    //Separate outputs with a line
    cout<<endl;
}

/**************************************************
 *                Fill Array                      *
 **************************************************
 * Purpose:  To fill an array with 2 digit integer
 *           random numbers.
 * Input:
 *    n-> The size of the array
 * Output:
 *    a-> The Array class
 * Output:
 */
Array * filAray(int n){
    //Declare a class pointer
    Array *a=new Array;//Allocate memory for the class
    a->setSize(n);         //Setting the size of the data array
    //Loop on every element and equate to 2 digits
    for(int i=0;i<n;i++){
        a->setData(i,rand()%90+10);//[10-99]
    }
    //Return the Array
    return a;
}