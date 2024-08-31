#include "DynamicArray_tests.h"

void testItemsConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    DynamicArray<int> arr(items, 5);
    IS_TRUE(arr.GetSize() == 5);
    for (size_t i = 0; i < arr.GetSize(); ++i)
    {
        IS_TRUE(arr[i] == items[i]);
    }
    std::cout << "DynamicArray itemsConstructor test passed" << std::endl;
}

void testCopyDynamicArray()
{
    DynamicArray<int> arr1(5);
    DynamicArray<int> arr2(arr1);
    for (size_t i = 0; i != arr1.GetSize(); ++i)
    {
        IS_TRUE(arr1[i] == arr2[i]);
    }
    std::cout << "DynamicArray copy test passed" << std::endl;
}

void testArrayEquals()
{
    DynamicArray<int> arr1(5);
    DynamicArray<int> arr2(arr1);
    IS_TRUE(arr1 == arr2);
    arr2.Resize(arr2.GetSize() + 1);
    arr2[arr2.GetSize() - 1] = 5;
    IS_TRUE(!(arr1 == arr2));
    std::cout << "DynamicArray equals test passed" << std::endl;
}

void testArrayGet()
{
    bool exceptionCaught = false;
    DynamicArray<int> arr1(5);
    int a;
    try
    {
        a = arr1.Get(10);
    }
    catch (const std::exception& e)
    {
        exceptionCaught = true;
    }
    IS_TRUE(exceptionCaught);
    arr1.Set(0, 2);
    a = arr1.Get(2);
    IS_TRUE(a == 0);
    std::cout << "DynamicArray get test passed" << std::endl;
}

void testArrayAssignmentOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    DynamicArray<int> arr1(items, 5);
    DynamicArray<int> arr2 = arr1;
    IS_TRUE(arr1 == arr2);
    std::cout << "LinkedList assignment operator test passed" << std::endl;
}

void testArrayBrackets()
{
    bool exceptionCaught = false;
    DynamicArray<int> arr1(5);
    int a;
    try
    {
        a = arr1[10];
    }
    catch (const std::exception& e)
    {
        exceptionCaught = true;
    }
    IS_TRUE(exceptionCaught);
    arr1.Set(0, 2);
    a = arr1[2];
    IS_TRUE(a == 0);
    std::cout << "DynamicArray brackets operator test passed" << std::endl;
}

void testArrayResize()
{
    DynamicArray<int> arr1(5);
    arr1.Resize(10);
    IS_TRUE(arr1.GetSize() == 10);
    std::cout << "DynamicArray resize test passed" << std::endl;
}

void testDynamicArray()
{
    testArrayResize();
    testArrayBrackets();
    testArrayGet();
    testArrayEquals();
    testItemsConstructor();
    testCopyDynamicArray();
    std::cout << "DYNAMICARRAY TESTS PASSED" << std::endl
        << std::endl;
}