//
//  main.cpp
//  CPP-PRG-09-09-Median-Function
//
//  Created by Keith Smith on 10/31/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  In statistics, when a set of values is sorted in ascending or descending order, its median
//  is the middle value. If the set contains an even number of values, the median is the
//  mean, or the average, of the two middle values. Write a function that accepts as arguments
//  the following:
//
//      A) An array of integers
//      B) An integer that indicates the number of elements in the array
//
//  The function should determine the median of the array. This value should be returned
//  as a double. (Assume the values in the array are already sorted.)
//
//  Demonstrate your pointer prowess by using pointer notation instead of array notation
//  in this function.

#include <iostream>
#include <iomanip>

using namespace std;

int *sizeArray();
int *fillArray(int);
void displayMedian(int *, int);

int main()
{
    int *intArrIntegers = nullptr;
    int *intArrSize = nullptr;
    
    intArrSize = sizeArray();
    
    intArrIntegers = fillArray(*intArrSize);
    
    displayMedian(intArrIntegers, *intArrSize);
    
    delete [] intArrIntegers;
    intArrIntegers = nullptr;
 
    return 0;
}

int *sizeArray()
{
    int *intSize = nullptr;
    
    intSize = new int;
    
    cout << "Please enter the size of the array: ";
    cin >> *intSize;
    
    return intSize;
}

int *fillArray(int intSize)
{
    int *intArr = nullptr;
    
    intArr = new int[intSize];
    
    for (int i = 0 ; i < intSize ; i++)
    {
        cout << "Please enter value " << (i + 1) << " of " << intSize << ": ";
        cin >> *(intArr + i);
    }
    
    return intArr;
}

void displayMedian(int *intArr, int intSize)
{
    float *fltMedian = nullptr;
    
    fltMedian = new float;
    
    if(intSize % 2 == 0)
    {
        *fltMedian += intArr[intSize/2];
        *fltMedian += intArr[(intSize/2) - 1];
        *fltMedian /= 2.0f;
    }
    else if(intSize % 2 != 0)
    {
        *fltMedian = intArr[intSize/2];
    }
    else
    {
        cout << "ERROR DETERMINING MEDIAN VALUE" << endl;
        exit(1);
    }
    
    cout << setprecision(1) << fixed << showpoint;
    cout << "The median value is " << *fltMedian << endl;
}
