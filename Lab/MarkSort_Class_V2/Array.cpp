/* 
 * File:   Array.h
 * Author: Dr. Mark E. Lehr
 * Created on July 23, 2015, 10:54 AM
 * Purpose:Array Implementation
 */

#include "Array.h"

int Array::getData(int indx){
    if(indx>=0&&indx<size)return data[indx];
    else return -1;
}
      
void Array::setSize(int n){
    if(n>=2)size=n;
    else size=100;
    data=new int[size];
}
      
void Array::setData(int indx,int val){
    if(indx>=0&&indx<size&&val>=10&&val<=99)data[indx]=val;
    else data[indx]=10;
}