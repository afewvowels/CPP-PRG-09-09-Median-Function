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
int *sortArray(int *, int);
void swap(int *, int *);
void displayMedian(int *, int);

int main()
{
    int *intArrIntegers = nullptr;
    int *intArrSize = nullptr;
    
    intArrSize = sizeArray();
    
    intArrIntegers = fillArray(*intArrSize);
    
    cout << "The values in the array are:\n";
    for (int i = 0 ; i < *intArrSize ; i++)
    {
        cout << intArrIntegers[i] << endl;
    }
    cout << endl;
    
    intArrIntegers = sortArray(intArrIntegers, *intArrSize);
    
    cout << "The sorted values in the array are:\n";
    for (int i = 0 ; i < *intArrSize ; i++)
    {
        cout << intArrIntegers[i] << endl;
    }
    cout << endl;
    
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

//  Broken selection sort, use this someday
//int *sortArray(int *intArr, int intSize)
//{
//    int intMinIndex;
//    int intMinValue;
//
//    for(int start = 0 ; start < (intSize - 1) ; start++)
//    {
//        intMinIndex = start;
//        intMinValue = intArr[start];
//
//        for(int i = (start + 1) ; i < intSize ; i++)
//        {
//            if(intArr[i] < intArr[intMinValue])
//            {
//                intMinValue = intArr[i];
//                intMinIndex = i;
//            }
//        }
//        swap(intArr[intMinIndex], intArr[start]);
//    }
//
//    return intArr;
//}

int *sortArray(int *intArr, int intSize)
{
    int intMaxElement;
    int intIndex;
    
    for (intMaxElement = (intSize - 1) ; intMaxElement > 0 ; intMaxElement--)
    {
        for (intIndex = 0 ; intIndex < intMaxElement ; intIndex++)
        {
            if (intArr[intIndex] > intArr[intIndex + 1])
            {
                swap(intArr[intIndex], intArr[intIndex + 1]);
            }
        }
    }
    
    return intArr;
}

void swap(int *intA, int *intB)
{
    int *intTemp = nullptr;
    
    intTemp = intA;
    intA = intB;
    intB = intTemp;
    
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
