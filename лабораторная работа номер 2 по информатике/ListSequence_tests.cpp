#include "ListSequence_tests.h"

void testListSequenceItemsConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> lstSeq(items, 5);
    IS_TRUE(lstSeq.getSize() == 5);
    for (size_t i = 0; i < lstSeq.GetLength(); i++)
    {
        IS_TRUE(lstSeq.Get(i) == (i + 1));
    }
    std::cout << "ListSequence itemsConstructor test passed" << std::endl;
}

void testListSequenceSizeConsturctor()
{
    ListSequence<int> lstSeq(5);
    IS_TRUE(lstSeq.GetLength() == 5);
    std::cout << "ListSequence SizeConstructor test passed" << std::endl;
}

void testListSequenceCopyConstructor()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> lstSeq(items, 5);
    ListSequence<int> copiedSeq(lstSeq);
    IS_TRUE(copiedSeq.GetLength() == 5);
    for (size_t i = 0; i < copiedSeq.GetLength(); i++)
    {
        IS_TRUE(lstSeq.Get(i) == (i + 1));
    }
    std::cout << "ListSequence CopyConstructor test passed" << std::endl;
}

void testListSequenceGetSubSequence()
{
    int items[] = { 1, 2, 3, 4, 5 };
    int subItems[] = { 2, 3, 4 };
    ListSequence<int> lstSeq(items, 5);
    ListSequence<int> expectedSubSequence(subItems, 3);
    ListSequence<int>* subSequence = lstSeq.GetSubsequence(1, 3);
    IS_TRUE(subSequence->GetLength() == 3);
    for (size_t i = 0; i < subSequence->GetLength(); i++)
    {
        IS_TRUE(subSequence->Get(i) == (i + 2));
    }
    std::cout << "ListSequence getSubSequence test passed" << std::endl;
    delete subSequence;
}

void testListSequenceGetters()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> lstSeq(items, 5);
    IS_TRUE(lstSeq.GetLength() == 5);
    IS_TRUE(lstSeq[2] == 3);
    IS_TRUE(lstSeq.Get(4) == 5);
    IS_TRUE(lstSeq.GetLast() == 5);
    IS_TRUE(lstSeq.GetFirst() == 1);
    std::cout << "ListSequence getters test passed" << std::endl;
}

void testListSequenceBracketsOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> lstSeq(items, 5);
    IS_TRUE(lstSeq[2] == 3);
    std::cout << "ListSequence bracketsOperator test passed" << std::endl;
}

void testListSequenceConcat()
{
    int items1[] = { 1, 2, 3, 4, 5 };
    int items2[] = { 6, 7, 8, 9, 10 };
    ListSequence<int> lstSeq1(items1, 5);
    ListSequence<int> lstSeq2(items2, 5);
    lstSeq1.Concat(lstSeq2);
    for (size_t i = 0; i < 10; i++)
    {
        IS_TRUE(lstSeq1.Get(i) == (i + 1));
    }
    std::cout << "ListSequence concat test passed" << std::endl;
}

void testListSequenceAssignmentOperator()
{
    int items[] = { 1, 2, 3, 4, 5 };
    ListSequence<int> lstSeq(items, 5);
    ListSequence<int> assignSeq = lstSeq;
    IS_TRUE(lstSeq.GetLength() == 5);
    for (size_t i = 0; i < lstSeq.GetLength(); i++)
    {
        IS_TRUE(lstSeq.Get(i) == (i + 1));
    }
    std::cout << "ListSequence assignmentOperator test passed" << std::endl;
}

void testListSequence()
{
    try
    {
        testListSequenceItemsConstructor();
        testListSequenceSizeConsturctor();
        testListSequenceCopyConstructor();
        testListSequenceGetSubSequence();
        testListSequenceConcat();
        testListSequenceGetters();
        testListSequenceBracketsOperator();
        testListSequenceAssignmentOperator();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "LISTSEQUENCE TESTS PASSED" << std::endl
        << std::endl;
}