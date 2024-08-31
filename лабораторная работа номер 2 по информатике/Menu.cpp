#include <iostream>
#include "Menu.h"

int getIntegerInRange(int min, int max)
{
    while (true)
    {
        int number;
        std::cin >> number;
        if (number <= max && number >= min)
        {
            return number;
        }
        cout << "Number out of range" << endl;
    }
}

void menu()
{
    int manageNumber;
    while (true)
    {
        printMainMenu();
        manageNumber = getIntegerInRange(1, 4);
        switch (manageNumber)
        {
        case 1:
            testArray();
            break;
        case 2:
            runTests();
            break;
        case 3:
            return;
        default:
            return;
        }
    }
}

void runTests()
{
    testLinkedList();
    testDynamicArray();
    testArraySequence();
    testImmutableArraySequence();
    testListSequence();
}

void testArray()
{
    int manageNumber;
    printOperationChoice();
    manageNumber = getIntegerInRange(1, 5);
    switch (manageNumber)
    {
    case 1:
        arrayManualCreation();
        break;
    case 2:
        arrayGetElement();
        break;
    case 3:
        arrayInsertElement();
        break;
    case 4:
        arrayGetSubArray();
        break;
    case 5:
        arrayConcatenate();
        break;
    default:
        return;
    }
}

void arrayManualCreation()
{
    int manageNumber;
    printTypes();
    manageNumber = getIntegerInRange(1, 2);
    switch (manageNumber)
    {
    case 1:
        testIntegerArrayManualCreation();
        break;
    case 2:
        testFloatArrayManualCreation();
        break;
    default:
        return;
    }
}

void testFloatArrayManualCreation()
{
    ArraySequence<float> arr = createArrayManually(createFloat);
    printArray<float>(&arr, printFloat);
}
void testIntegerArrayManualCreation()
{
    ArraySequence<int> arr = createArrayManually(createInteger);
    printArray<int>(&arr, printInteger);
}

template <class T>
ArraySequence<T> createArrayManually(T createElement())
{
    int length = 0;
    cout << "Enter the length (<100)" << endl;
    length = getIntegerInRange(0, 99);
    ds::ArraySequence<T> newArray = ds::ArraySequence<T>();
    for (int i = 0; i < length; i++)
    {
        cout << "[" << i << "] element =" << endl;
        newArray.append(createElement());
    }
    return newArray;
};

int createInteger()
{
    int number;
    std::cin >> number;
    return number;
}

void printInteger(int number)
{
    cout << number << endl;
}

float createFloat()
{
    float number;
    std::cin >> number;
    return number;
}

void printFloat(float number)
{
    cout << number << endl;
}

void arrayConcatenate()
{
    ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    cout << "Let's create a new integer array to concatenate it to that array" << endl;

    ArraySequence<int> arr2 = createArrayManually(createInteger);
    arr.Concat(arr2);
    cout << "The concatenated array is: " << endl;
    printArray(&arr, printInteger);
}

void arrayGetSubArray()
{
    ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    int startIndex, endIndex;
    while (true)
    {
        cout << "Pick the start index of the subarray:" << endl;
        cin >> startIndex;
        cout << "Pick the end index of the subarray:" << endl;
        cin >> endIndex;
        if (startIndex < endIndex && endIndex >= 0 && endIndex < 10 && startIndex >= 0 && startIndex < 10)
        {
            break;
        }
        cout << "Invalid indexes provided! Try again. " << endl;
    }
    ArraySequence<int>* subArr = arr.GetSubsequence(startIndex, endIndex);
    cout << "The subarray is: " << endl;
    printArray(subArr, printInteger);
    delete subArr;
}

void arrayInsertElement()
{
    ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    int index, element;
    cout << "Pick an index to insert a new element in:" << endl;
    cin >> index;
    cout << "Input the new element " << endl;
    cin >> element;
    arr.InsertAt(element, index);
    cout << "Array after insertion: " << endl;
    printArray(&arr, printInteger);
}

void arrayGetElement()
{
    ArraySequence<int> arr = createRandomIntegerArray();
    cout << "Here's an array of 10 random integers: " << endl;
    printArray(&arr, printInteger);
    int index;
    cout << "Pick an index to get the element of the array" << endl;
    cin >> index;
    cout << "The element is: " << arr.Get(index) << endl;
}

ArraySequence<int> createRandomIntegerArray()
{
    int length = 10;
    ArraySequence<int> newArray = ArraySequence<int>();
    for (int i = 0; i < length; i++)
    {
        newArray.Append(createRandomIntNumber(100));
    }
    return newArray;
};

int createRandomIntNumber(int maxNumber)
{
    return rand() % maxNumber;
}