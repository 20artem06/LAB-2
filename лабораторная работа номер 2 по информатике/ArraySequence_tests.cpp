#include "ArraySequence_tests.h"
#include "ListSequence.h"

void testGetSubSequence()
{
    int items[] = { 1, 2, 3, 4, 5 };
    int subItems[] = { 2, 3, 4 };
    ArraySequence<int> arrSeq(items, 5);
    ArraySequence<int> expectedSubSequence(subItems, 3);
    ArraySequence<int>* subSequence = arrSeq.GetSubsequence(1, 3);
    IS_TRUE(subSequence->GetLength() == 3);
    for (size_t i = 0; i < subSequence->GetLength(); i++)
    {
        IS_TRUE(subSequence->Get(i) == (i + 2));
    }
    std::cout << "ArraySequence GetSubSequence test passed" << std::endl;
    delete subSequence;
}

void testArraySequenceItemsConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.GetLength() == 5);
    for (size_t i = 0; i < arrSeq.GetLength(); i++)
    {
        IS_TRUE(arrSeq.Get(i) == (i + 1));
    }
    std::cout << "ArraySequence itemsConstructor test passed" << std::endl;
}

void testArraySequenceGetters()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.GetLength() == 5);
    IS_TRUE(arrSeq[2] == 3);
    IS_TRUE(arrSeq.Get(4) == 5);
    IS_TRUE(arrSeq.GetLast() == 5);
    IS_TRUE(arrSeq.GetFirst() == 1);
    std::cout << "ArraySequence getters test passed" << std::endl;
}


void testArraySequenceCopyConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> arrSeq(items, 5);
    ArraySequence<int> copiedSeq(arrSeq);
    IS_TRUE(copiedSeq.GetLength() == 5);
    for (size_t i = 0; i < copiedSeq.GetLength(); i++)
    {
        IS_TRUE(arrSeq.Get(i) == (i + 1));
    }
    std::cout << "ArraySequence CopyConstructor test passed" << std::endl;
}

void testArraySequenceBracketsOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq[2] == 3);
    std::cout << "ArraySequence bracketsOperator test passed" << std::endl;
}
void testArraySequenceConcat()
{
    int items1[] = { 1, 2, 3, 4, 5 };
    int items2[] = { 6, 7, 8, 9, 10 };
    ArraySequence<int> arrSeq1(items1, 5);
    ArraySequence<int> arrSeq2(items2, 5);
    arrSeq1.Concat(arrSeq2);
    for (size_t i = 0; i < 10; i++)
    {
        IS_TRUE(arrSeq1.Get(i) == (i + 1));
    }

    std::cout << "ArraySequence concat test passed" << std::endl;
}

void testArraySequenceAssignmentOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> arrSeq(items, 5);
    ArraySequence<int> assignSeq = arrSeq;
    IS_TRUE(arrSeq.GetLength() == 5);
    for (size_t i = 0; i < arrSeq.GetLength(); i++)
    {
        IS_TRUE(arrSeq.Get(i) == (i + 1));
    }
    std::cout << "ArraySequence assignmentOperator test passed" << std::endl;
}

void testArraySequence()
{
    testGetSubSequence();
    testArraySequenceItemsConstructor();
    testArraySequenceConcat();
    testArraySequenceCopyConstructor();
    testArraySequenceGetters();
    testArraySequenceBracketsOperator();
    testArraySequenceAssignmentOperator();

    std::cout << "ARRAYSEQUENCE TESTS PASSED" << std::endl
        << std::endl;
}