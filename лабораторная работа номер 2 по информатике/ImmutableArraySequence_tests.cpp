#include "ImmutableArraySequence_tests.h"

void testImmutableArraySequenceItemsConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ImmutableArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.GetLength() == 5);
    for (size_t i = 0; i < arrSeq.GetLength(); i++)
    {
        IS_TRUE(arrSeq.Get(i) == (i + 1));
    }
    std::cout << "ImmutableArraySequence itemsConstructor test passed" << std::endl;
}

void testImmutableArraySequenceGetters()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ImmutableArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq.GetLength() == 5);
    IS_TRUE(arrSeq[2] == 3);
    IS_TRUE(arrSeq.Get(4) == 5);
    IS_TRUE(arrSeq.GetLast() == 5);
    IS_TRUE(arrSeq.GetFirst() == 1);
    std::cout << "ImmutableArraySequence getters test passed" << std::endl;
}


void testImmutableArraySequenceSizeConstructor()
{
    ImmutableArraySequence<int> arrSeq(5);
    IS_TRUE(arrSeq.GetLength() == 5);
    std::cout << "ImmutableArraySequence SizeConstructor test passed" << std::endl;
}

void testImmutableArraySequenceCopyConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ImmutableArraySequence<int> arrSeq(items, 5);
    ImmutableArraySequence<int> copiedSeq(arrSeq);
    IS_TRUE(copiedSeq.GetLength() == 5);
    for (size_t i = 0; i < copiedSeq.GetLength(); i++)
    {
        IS_TRUE(arrSeq.Get(i) == (i + 1));
    }
    std::cout << "ImmutableArraySequence CopyConstructor test passed" << std::endl;
}

void testImmutableArraySequenceBracketsOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ImmutableArraySequence<int> arrSeq(items, 5);
    IS_TRUE(arrSeq[2] == 3);
    std::cout << "ImmutableArraySequence bracketsOperator test passed" << std::endl;
}

void testImmutableArrayGetSubSequence()
{
    int items1[] = { 1, 2, 3, 4, 5 };
    ImmutableArraySequence<int> arrSeq1(items1, 5);
    ImmutableArraySequence<int>* subSeq = arrSeq1.GetSubsequence(1, 3);
    IS_TRUE(subSeq->GetLength() == 3);
    for (size_t i = 0; i < 3; i++)
    {
        IS_TRUE(subSeq->Get(i) == i + 2);
    }
    delete subSeq;
    std::cout << "ImmutableArraySequence subSequence test passed" << std::endl;
}

void testImmutableArraySequenceConcat()
{
    int items1[] = { 1, 2, 3, 4, 5 };
    int items2[] = { 6, 7, 8, 9, 10 };
    ImmutableArraySequence<int> arrSeq1(items1, 5);
    ImmutableArraySequence<int> arrSeq2(items2, 5);
    ImmutableArraySequence<int>* concatSeq = arrSeq1.Concat(arrSeq2);
    for (size_t i = 0; i < 10; i++)
    {
        IS_TRUE(concatSeq->Get(i) == (i + 1));
    }

    std::cout << "ImmutableArraySequence concat test passed" << std::endl;
    delete concatSeq;
}

void testImmutableArraySequenceAssignmentOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ImmutableArraySequence<int> arrSeq(items, 5);
    ImmutableArraySequence<int> assignSeq = arrSeq;
    IS_TRUE(arrSeq.GetLength() == 5);
    for (size_t i = 0; i < arrSeq.GetLength(); i++)
    {
        IS_TRUE(arrSeq.Get(i) == (i + 1));
    }
    std::cout << "ImmutableArraySequence assignmentOperator test passed" << std::endl;
}

void testImmutableArraySequence()
{
    testImmutableArraySequenceBracketsOperator();
    testImmutableArraySequenceCopyConstructor();
    testImmutableArraySequenceConcat();
    testImmutableArrayGetSubSequence();
    testImmutableArraySequenceSizeConstructor();
    testImmutableArraySequenceAssignmentOperator();
    testImmutableArraySequenceItemsConstructor();
    testImmutableArraySequenceGetters();

    std::cout
        << "IMMUTABLE ARRAYSEQUENCE TESTS PASSED" << std::endl
        << std::endl;
}