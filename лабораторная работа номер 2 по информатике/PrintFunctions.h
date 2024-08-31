#pragma once

#include <iostream>
#include "ArraySequence.h"

void printIntegerArray(ArraySequence<int>* array);
void printTypes();
void printOperationChoice();
void printManuallyQuestion();
void printMainMenu();

template <typename T>
void printArray(ArraySequence<T>* array, void print(T))
{
    cout << "Array consists of " << array->GetLength() << " numbers\n";
    for (int i = 0; i < array->getSize(); i++)
        print(array->Get(i));
    cout << std::endl;
};