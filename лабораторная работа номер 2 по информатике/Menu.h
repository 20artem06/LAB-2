#pragma once

#include <iostream>
#include "PrintFunctions.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "DynamicArray_tests.h"
#include "LinkedList_tests.h"
#include "ArraySequence_tests.h"
#include "ImmutableArraySequence_tests.h"
#include "listSequence_tests.h"

void menu();
void testArray();
void arrayManualCreation();
void arrayGetElement();
void arrayInsertElement();
void arrayGetSubArray();
void arrayConcatenate();
template <class T>
ArraySequence<T> createArrayManually(T createElement());
ArraySequence<int> createRandomIntegerArray();
void testIntegerArrayManualCreation();
void testFloatArrayManualCreation();

int createInteger();
float createFloat();
void printFloat(float);
void printInteger(int);
void runTests();
int createRandomIntNumber(int maxNumber);