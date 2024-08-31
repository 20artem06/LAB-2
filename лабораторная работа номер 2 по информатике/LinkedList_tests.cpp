#include "LinkedList_tests.h"

void testAssignmentOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    LinkedList<int> lst1(items, 5);
    LinkedList<int> lst2 = lst1;
    IS_TRUE(lst1 == lst2);
    std::cout << "LinkedList assignment operator test passed" << std::endl;
}

void testEmptyConstructor()
{
    LinkedList<int> lst = LinkedList<int>();
    IS_TRUE(lst.GetLength() == 0);
    bool exceptionCaught = false;
    int a;
    try
    {
        a = lst.GetFirst();
    }
    catch (const std::exception& e)
    {
        exceptionCaught = true;
    }
    IS_TRUE(exceptionCaught);
    std::cout << "LinkedList empty Constructor test passed" << std::endl;
}

void testArrayConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    LinkedList<int> lst(items, 5);
    IS_TRUE(lst.GetLength() == 5);
    for (size_t i = 0; i < lst.GetLength(); ++i)
    {
        IS_TRUE(lst[i] == lst[i]);
    }
    std::cout << "LinkedList array constructor test passed" << std::endl;
}

void testCopyConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    LinkedList<int> lst1(items, 5);
    LinkedList<int> lst2(lst1);
    for (size_t i = 0; i < lst2.GetLength(); ++i)
    {
        IS_TRUE(lst1[i] == lst2[i]);
    }
    IS_TRUE(lst2.GetLength() == 5);
    std::cout << "LinkedList copy constructor test passed" << std::endl;
}

void testEqualsOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    int appendedArray[] = { 1, 2, 3, 4, 5, 6 };
    LinkedList<int> lst1(items, 5);
    LinkedList<int> lst2(items, 5);
    LinkedList<int> lst3(appendedArray, 6);
    IS_TRUE(lst1 == lst2);
    IS_TRUE(!(lst1 == lst3));
    std::cout << "LinkedList equals operator test passed" << std::endl;
}

void testListGetters()
{
    int items[] = { 1, 2, 3, 4, 5 };
    LinkedList<int> lst1(items, 5);
    IS_TRUE(lst1.Get(1) == 2);
    IS_TRUE(lst1[2] == 3);
    IS_TRUE(lst1.GetFirst() == 1);
    IS_TRUE(lst1.GetLast() == 5);

    LinkedList<int> emptyList = LinkedList<int>();
    bool exceptionCaught = false;
    int a;
    try
    {
        a = emptyList.GetFirst();
    }
    catch (const std::exception& e)
    {
        exceptionCaught = true;
    }
    IS_TRUE(exceptionCaught);
    std::cout << "LinkedList getters tests passed" << std::endl;
}

void testListConcat()
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 6, 7, 8, 9, 10 };
    int resArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    LinkedList<int> lst1(arr1, 5);
    LinkedList<int> lst2(arr2, 5);
    LinkedList<int>* concatedLst = lst1.Concat(&lst2);

    LinkedList<int> expectedResLst(resArr, 10);
    IS_TRUE(*concatedLst == expectedResLst);
    delete concatedLst;
    std::cout << "LinkedList concat test passed" << std::endl;
}

void testSublist()
{
    int arr1[] = { 1, 2, 3, 4, 5 };

    int resArr[] = { 2, 3, 4 };
    LinkedList<int> lst1(arr1, 5);
    LinkedList<int>* sublist = lst1.GetSublist(1, 3);
    LinkedList<int> expectedSublist(resArr, 3);

    IS_TRUE(*sublist == expectedSublist);
    delete sublist;
    std::cout << "LinkedList sublist test passed" << std::endl;
}

void testListSetters()
{
    int originalArray[] = { 1, 2, 3, 4, 5 };
    int appendedArray[] = { 1, 2, 3, 4, 5, 6 };
    int prependedArray[] = { 0, 1, 2, 3, 4, 5 };
    int insertedArray[] = { 1, 2, 3, 100, 4, 5 };

    LinkedList<int> lst1(originalArray, 5);
    LinkedList<int> appendedLstRes(appendedArray, 6);

    lst1.Append(6);
    IS_TRUE(lst1 == appendedLstRes);

    LinkedList<int> lst2(originalArray, 5);
    LinkedList<int> prependenLstRes(prependedArray, 6);
    lst2.Prepend(0);
    IS_TRUE(lst2 == prependenLstRes);

    LinkedList<int> lst3(originalArray, 5);
    LinkedList<int> insertedLstRes(insertedArray, 6);

    lst3.InsertAt(100, 3);
    IS_TRUE(lst3 == insertedLstRes);

    std::cout << "LinkedList setters tests passed" << std::endl;
}

void testLinkedList()
{
    testAssignmentOperator();
    testSublist();
    testListConcat();
    testListSetters();
    testEqualsOperator();
    testListGetters();
    testCopyConstructor();
    testEmptyConstructor();
    testArrayConstructor();
    std::cout << "LINKEDLIST TESTS PASSED" << std::endl
        << std::endl;
}