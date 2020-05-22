//  Program 5
//  IntArray program with overloaded operators
//  CS320-01
//  11-18-2019
//  @author  Brian Arlantico cssc0443

#include "intArray.h"

//Default Constructor
IntArray::IntArray() {
    lo = 0;
    hi = 9;
    size = 10;
    pA = (int*) malloc(10*sizeof(int));
}

//Constructor with one argument.
IntArray::IntArray(int x) {
    lo = 0;
    hi = x - 1;
    size = x;
    pA = (int*) malloc(x*sizeof(int));
}

//Constructor with specified indicies
IntArray::IntArray(int a, int b) {
    if (a > b) {
        std::cout << "Error: first index greater than last index" << std::endl;
        std::cout << "---Program halted---" << std::endl;
        size = -1;
        lo = 0;
        hi = -1;
        pA = new int[0];
        
    }
    else {

    if (a == b) {
        lo = hi = a;
        size = 1;
        pA = (int*) malloc (1*sizeof(int));
    }
    else {
        lo = a;
        hi = b;
        if (a < 0 && b < 0) {
            size = (-a) + (-b) + 1;
        } else if (a < 0 && b >= 0) {
            size = (-a) + b + 1;
        } else {
            size = b - a + 1;
        }

        pA = (int*) malloc(size*sizeof(int));

    }
    }

}

//Constructor from another IntArray object.
IntArray::IntArray(const IntArray& a) {
    lo = a.lo;
    hi = a.hi;
    size = a.size;

    for (int i = a.lo; i <= a.hi; i++) {
    if (i < 0)
        *(pA -(a.lo - i)) =  *(a.pA -(a.lo - i));
    else {
        *(pA - a.lo + i) = *(a.pA - a.lo + i); 
    }
}
}

//Destructor
IntArray::~IntArray() {
   
}   

//Check if two arrays are of same size and contain same elements.
int IntArray::operator==(const IntArray& a) {
    if (size != a.size)
        return 0;
    int j = 0;

    for (int i = low(); i < high(); i++) {
        if (*(pA -(low() - i)) !=  *(a.pA + j++))
        return 0; 
    }  
    return 1; //true
}

//Check if two intArrays do not contain exact same elements.
int IntArray::operator!=(const IntArray& a) {
    if (size != a.size)
        return 1;
    int j = 0;

    for (int i = low(); i < high(); i++) {
        if (*(pA -(low() - i)) !=  *(a.pA + j++))
        return 1; 
    }  
    return 0; //true
}

//Index accessing of intArray.
int& IntArray::operator[] (int i) {
    if (i < low() || i > high()) {
        std::cout << "Error: Illegal index." << std::endl;
        std::cout << "---Program halted---" << std::endl;
        return pA[0];
    }
    if (low() == 0)
        return *(pA + i);
    else {
        if (i < 0) 
            return *(pA  -(low() - i));
        else 
            return *(pA - low() + i);
    }
}

//Assigns one intArray to antoher.
IntArray& IntArray::operator=(const IntArray& a) {
    if (a.pA == this->pA)
        return *this;
    if (size != a.size) {
        std::cout << "Illegal assignment: Arrays of different sizes" << std::endl;
        std::cout << "---Program halted---" << std::endl;
        return *this;
    }

    int j = 0;
    

    for (int i = this->lo; i <= this->hi; i++) {
    if (i < 0)
        *(pA -(low() - i)) =  *(a.pA + j++);
    else {
        *(pA - low() + i) = *(a.pA + j++); 
    }
}
return *this;
}

//Adds the elements of intArrays if they have same size.
IntArray IntArray::operator+(const IntArray& a) {
    if (size != a.size) {
        std::cout << "Error: Differing sizes." << std::endl;
        std::cout << "---Program halted---" << std::endl;
        return *this;
    }
    IntArray array(size);
    int l, j = 0;

    for (int i = 0; i < size; i++) {

        array[l++] = *(pA + i) + *(a.pA + j++);  
}

return array;

}

//Adds intArray on right and assigns to left intArray.
IntArray& IntArray::operator+=(const IntArray& a) {
    if (size != a.size) {
        std::cout << "Error: Differing sizes." << std::endl;
        std::cout << "---Program halted---" << std::endl;
        return *this;
    }

    int j = 0;
    for (int i = this->lo; i <= this->hi; i++) {
    if (i < 0)
        *(pA -(low() - i)) +=  *(a.pA + j++);
    else {
        *(pA - low() + i) += *(a.pA + j++); 
    }
}
    return *this;

}

//Prints intArray.
ostream& operator<<(ostream& output, const IntArray& a) {
for (int i = a.lo; i <= a.hi; i++) {
    if (i < 0)
        output << a.name << "[" << i << "] = " << *(a.pA -(a.lo - i)) << std::endl;
    else {
        output << a.name << "[" << i << "] = " << *(a.pA - a.lo + i) << std::endl;
    }
}
 return output;
}

//Prints name.
void IntArray::getName() {
    std::cout << name << std::endl;
}

void IntArray::setName(const char *n) {
    name = n;
}

//Returns high index.
int IntArray::high() {
    return hi;
}

//Returns low index.
int IntArray::low() {
    return lo;

// intArray.h
// Provided by instructor, CS320 Fall 2018

#ifndef _INTARRAY_H
#define _INTARRAY_H
#include <iostream>
#include <iomanip>
#include "string.h"       // warnings issued whether this or <string>
#include <fstream>          // necessary for external file ptr
#include <stdlib.h>

using std::ostream;

class IntArray {
    private:
        const char* name;       // array's name
        int* pA;                // dynamic array
        int size;               // size of array
        int hi;                 // largest index
        int lo;                 // smallest index
    public:
        // Overloaded ctors
        IntArray();                         // IntArray z
        IntArray(int );                     // IntArray y(size)
        IntArray(int, int);                 // IntArray x(lowerIndex,upperIndex)
        IntArray(const IntArray&);          // IntArray w(anotherIntArray)
        ~IntArray();                        // Destructor

        // Overloaded operators
        int operator==(const IntArray&);
        int operator!=(const IntArray&);
        int& operator[] (int);                                      
        IntArray& operator=(const IntArray&);                       
        IntArray operator+(const IntArray&);
        IntArray& operator+=(const IntArray&);
        friend ostream& operator<<(ostream&, const IntArray&);

        // Helper functions
        void setName(const char *name);
        void getName();
        int  high();
        int  low();
};
