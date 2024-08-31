#pragma once

#include "AccessValidation.h"
using namespace std;


template <typename T>
class LinkedList
{
    struct Node
    {
        T Value;
        Node* Next = nullptr;
    };

public:
    LinkedList()
    {
    }

    LinkedList(const T* items, size_t count)
    {
        for (size_t i = 0; i < count; i++)
        {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList& other)
    {
        Node* otherListNode = other.m_Head;
        while (otherListNode)
        {
            Append(otherListNode->Value);
            otherListNode = otherListNode->Next;
        }
    }

    ~LinkedList()
    {
        Node* deletionNode = m_Head;
        Node* traverseNode = nullptr;
        while (deletionNode)
        {
            traverseNode = deletionNode->Next;
            delete deletionNode;
            deletionNode = traverseNode;
        }
    }

    size_t GetLength() const
    {
        return m_Size;
    }

    T GetFirst() const
    {
        validateListNotEmpty(__FUNCTION__, m_Size);
        return m_Head->Value;
    }

    T GetLast() const
    {
        validateListNotEmpty(__FUNCTION__, m_Size);
        return m_Tail->Value;
    }


    // mutable
    T& Get(size_t index)
    {
        Node* node = getNode(index);
        return node->Value;
    }

    void Append(T data)
    {
        Node* newNode = new Node({ data, nullptr });
        appendNode(newNode);
    }

    void Prepend(T data)
    {
        Node* newNode = new Node({ data, nullptr });
        if (m_Size == 0)
        {
            m_Head = newNode;
            m_Tail = newNode;
            m_Size++;
            return;
        }

        newNode->Next = m_Head;
        m_Head = newNode;
        m_Size++;
    }

    LinkedList<T>* GetSublist(size_t startIndex, size_t endIndex) const
    {
        validateAccessByIndex(startIndex, __FUNCTION__, m_Size);
        validateAccessByIndex(endIndex, __FUNCTION__, m_Size);
        if (startIndex > endIndex)
        {
            std::cout << __FUNCTION__ << " function failed" << std::endl;
            throw std::invalid_argument("InvalidIndexRange");
        }

        LinkedList<T>* sublist = new LinkedList<T>();
        Node* traverseNode = getNode(startIndex);
        for (size_t i = startIndex; i <= endIndex; i++)
        {
            sublist->Append(traverseNode->Value);
            traverseNode = traverseNode->Next;
        }

        return sublist;
    }

    void InsertAt(T data, size_t index) 
    {
        validateListNotEmpty(__FUNCTION__, m_Size);
        if (index > m_Size - 1)
        {
            std::cout << __FUNCTION__ << " function failed" << std::endl;
            throw std::invalid_argument("IndexOutOfRange");
        }

        Node* newNode = new Node({ data, nullptr });
        if (index == 0)
        {
            newNode->Next = m_Head;
            m_Head = newNode;
            return;
        }

        //-- insert
        Node* indexNode = getNode(index - 1);
        newNode->Next = indexNode->Next;
        indexNode->Next = newNode;
        //--
        m_Size++;
        return;
    }

    // Appends the passed list to this list
    LinkedList<T>* Concat(const LinkedList<T>& other) const
    {
        LinkedList<T>* newList = new LinkedList<T>(*this);
        Node* otherListNode = other.m_Head;
        while (otherListNode)
        {
            newList->Append(otherListNode->Value);
            otherListNode = otherListNode->Next;
        }

        return newList;
    }
    /*
    T& operator[](int index)
    {
        return getValue(index);
    }

    LinkedList& operator=(LinkedList const& other)
    {
        if (this != &other)
        {
            LinkedList tempList(other);
            tempList.swapList(*this);
        }
        return *this;
    }

    bool operator==(LinkedList<T> other)
    {
        if (m_Size != other.GetLength())
            return 0;

        Node<T>* thisListNode = this->m_Head;
        Node<T>* otherListNode = other.m_Head;
        for (int i = 0; i < other.GetLength(); i++)
        {
            if (thisListNode-> != otherListNode->getData())
            {
                return 0;
            }
            thisListNode = thisListNode->getNext();
            otherListNode = otherListNode->getNext();
        }
        return 1;
    }*/
    void PrintList() const
    {
        Node* traverseNode = m_Head;
        while (traverseNode != nullptr)
        {
            cout << traverseNode->Value << endl;
            traverseNode = traverseNode->Next;
        }

        cout << endl;
    }

private:
    Node* m_Head = nullptr;
    Node* m_Tail = nullptr;
    size_t m_Size = 0;

    void appendNode(Node* node) //не нужен, можно использовать публичный append
    {
        if (m_Size == 0)
        {
            m_Head = node;
            m_Tail = node;
            m_Head->Next = nullptr;
            m_Size++;
            return;
        }

        m_Tail->Next = node;
        m_Tail = node;
        m_Size++;
        return;
    }

    Node* getNode(size_t index) const
    {
        validateAccessByIndex(index, __FUNCTION__, m_Size);
        Node* traverseNode = m_Head;
        size_t i = 0;
        while (i != index)
        {
            traverseNode = traverseNode->Next;
            i++;
        }

        return traverseNode;
    }
};
