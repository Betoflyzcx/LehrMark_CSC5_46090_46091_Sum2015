/* 
 * File:   Array.h
 * Author: Dr. Mark E. Lehr
 * Created on July 23, 2015, 10:54 AM
 * Purpose:Array Specification
 */

#ifndef ARRAY_H
#define	ARRAY_H

class Array{
  private:
    int size;
    int *data;
  public:
      int getSize(){return size;}//In-line function
      int getData(int);
      void setSize(int);
      void setData(int,int);
      ~Array(){delete []data;}//In-line function
};

#endif	/* ARRAY_H */

