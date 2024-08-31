#pragma once

#include "LinkedList.h"
#include "Sequence.h"

template <class T>
class ListSequence : public Sequence<T>
{

private:
    LinkedList<T> m_List;

public:
    ListSequence(const T* items, size_t count)
    {
        m_List = LinkedList<T>(items, count);
    }

    ListSequence() = default;
    ListSequence(size_t size)
        : m_List(size)
    {
    }

    ListSequence(const ListSequence<T>& other)
    {
        m_List = LinkedList<T>(other.m_List);
    }

    ~ListSequence(){}

    explicit ListSequence(const LinkedList<T>& data)
    {
        m_List = data;
    }

    explicit ListSequence(const Sequence<T> *other)
    {
        for (int i = 0; i < other->GetLength(); i++)
        {
            Append(other->Get(i));
        }
    }

    const T& GetFirst() const
    {
        return m_List.Get(0);
    }

    const T& GetLast() const
    {
        return m_List.GetLast();
    }

    const T& Get(size_t index) const
    {
        return m_List.Get(index);
    }


    T& operator[](int index)
    {
        return m_List[index];
    }

    ListSequence<T>& operator=(ListSequence<T> other)
    {
        m_List = other.m_List;
        return *this;
    }

    int operator==(ListSequence<T> other)
    {
        return m_List == other.m_List;
    }


    ListSequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) const
    {
        ListSequence<T>* subSequence = new ListSequence<T>(*m_List.GetSublist(startIndex, endIndex));
        return subSequence;
    }

    size_t GetLength() const
    {
        return m_List.GetLength();
    }

    ListSequence<T>& Append(const T& item)
    {
        m_List.Append(item);
        return *this;
    }

    ListSequence<T>& Prepend(const T& item)
    {
        m_List.Prepend(item);
        return *this;
    }

    ListSequence<T>& InsertAt(const T& item, size_t index)
    {
        m_List.InsertAt(item, index);
        return *this;
    }

    ListSequence<T>& Concat(const Sequence<T>& other)
    {
        const size_t otherSize = other.GetLength();
        for (size_t i = 0; i < otherSize; i++)
        {
            Append(other.Get(i));
        }
        return *this;
    }
    
};
