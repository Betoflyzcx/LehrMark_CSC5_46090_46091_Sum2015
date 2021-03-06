/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 14, 2015, 12:11 PM
 * Purpose:  Simple Sort step by step
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array * filAray(int);
void prntAry(const Array *,int);
void swap(int &,int &);
void swapMin(int [],int,int);
void markSrt(int [],int);
void wrtStrc(fstream &,Array *);
Array * rdStruc(fstream &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Prepare for reading and writing to a file
    string filename="Binary.dat";
    fstream file;
    file.open(filename.c_str(),ios::in|ios::out|ios::binary);
    
    //Declare Variables
    int size=200;
    Array *array=filAray(size);
    
    //Output the initial array
    //cout<<"The Original Array"<<endl;
    //prntAry(array,20);
    
    //Process the inputs
    markSrt(array->data,array->size);
    
    //Output the sorted result
    //cout<<"The Sorted Array"<<endl;
    //prntAry(array,20);
    
    //Write this to a file, Read it back, then print the results
    //cout<<"The array output to a file then read back in and printed out"<<endl;
    wrtStrc(file,array);
    Array *brray=rdStruc(file);
    prntAry(brray,20);
    
    //Deallocate memory and closing files
    delete []array->data;
    delete []brray->data;
    delete array;
    delete brray;
    file.close();
    
    //Exit Stage Right
    return 0;
}

/**************************************************
 *         Read a Structure from a File           *
 **************************************************
 * Purpose:  Read array structure from a file
 * Input:
 *    file-> Where to read
 * Output:
 *    a-> The structure that contains the data
 */
Array * rdStruc(fstream &file){
    //Declare a structure pointer
    Array *a=new Array;//Allocate memory for the structure
    //Go to the beginning
    file.clear();
    file.seekg(0L, ios::beg); 
    //Read the size from the file
    file.read(reinterpret_cast<char *>(&a->size),sizeof(a->size));
    //Allocate the data array
    a->data=new int[a->size];
    //Read the array from the file
    file.read(reinterpret_cast<char *>(a->data),
                          a->size*sizeof(a->size));
    //Return the Array
    return a;
}

/**************************************************
 *       Write a Structure to a File              *
 **************************************************
 * Purpose:  Write an array structure to a file
 * Input:
 *    file-> Where to write
 * Output:
 *    a-> The structure that contains the data
 */
void wrtStrc(fstream & file,Array *a){
    //Write the size of the array
    file.write(reinterpret_cast<char *>(&a->size),sizeof(a->size));
    //Write the array elements
    file.write(reinterpret_cast<char *>(a->data),
                          a->size*sizeof(a->size));
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
void markSrt(int a[],int n){
    //Loop and sort every position
    for(int pos=0;pos<n-1;pos++){
        swapMin(a,n,pos);
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
void swapMin(int a[],int n,int pos){
    //Loop through the list starting at pos+1
    for(int i=pos+1;i<n;i++){
        //Place smallest value at the position pos
        if(a[pos]>a[i])swap(a[pos],a[i]);
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
void swap(int &a,int &b){
    //Perform the logical in-place swap
    a=a^b;
    b=a^b;
    a=a^b;
}

/**************************************************
 *                Print Array                      *
 **************************************************
 * Purpose:  To print an integer array with any
 *           number of columns
 * Input:
 *    n-> The size of the array
 *    a-> The Array Structure
 *    nCols->Number of columns to display the array.
 * Output:
 *    On Screen
 */
void prntAry(const Array *a,int nCols){
    //Separate outputs with a line
    //cout<<endl;
    //Loop and output every element in the array
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        //When column is reached go to next line
        if((i%nCols)==(nCols-1))cout<<endl;
    }
    //Separate outputs with a line
    //cout<<endl;
}

/**************************************************
 *                Fill Array                      *
 **************************************************
 * Purpose:  To fill an array with 2 digit integer
 *           random numbers.
 * Input:
 *    n-> The size of the array
 * Output:
 *    a-> The Array structure
 * Output:
 */
Array * filAray(int n){
    //Declare a structure pointer
    Array *a=new Array;//Allocate memory for the structure
    a->size=n;         //Setting the size of the data array
    a->data=new int[a->size];//Allocate memory for the data
    //Loop on every element and equate to 2 digits
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;//[10-99]
    }
    //Return the Array
    return a;
}