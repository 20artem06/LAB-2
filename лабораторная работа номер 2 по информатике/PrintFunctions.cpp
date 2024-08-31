#include "PrintFunctions.h"

using namespace std;

void printIntegerArray(ArraySequence<int>* array)
{
    cout << "Array holds " << array->GetLength() << " integers\n";
    int size = array->GetLength();
    for (int i = 0; i < array->GetLength(); i++)
    {
        cout << array->Get(i) << std::endl;
    }
    cout << std::endl;
}

void printTypes()
{
    cout << "Choose the type" << endl;
    cout << "Enter 1 - Int" << endl;
    cout << "Enter 2 - float" << endl;
};

void printOperationChoice()
{
    cout << "What do you want to test?" << endl;

    cout << "Enter 1 - Manual creation" << endl;
    cout << "Enter 2 - Getting an element" << endl;
    cout << "Enter 3 - Inserting an element" << endl;
    cout << "Enter 4 - Getting a subsequence" << endl;
    cout << "Enter 5 - Concatenation" << endl;
};

void printManuallyQuestion()
{
    cout << "Do you want to create the structure manu" << endl;
    cout << "Enter 1 - Int" << endl;
    cout << "Enter 2 - float" << endl;
};

void printMainMenu()
{
    cout << "Enter 1 - To test an ArraySequence" << endl;
    // cout << "Enter 3 - To test a ListSequence (not available)" << endl;
    cout << "Enter 2 - To run tests" << endl;
    cout << "Enter 3 - To Cancel" << endl;
};