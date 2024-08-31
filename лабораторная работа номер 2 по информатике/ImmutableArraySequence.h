#pragma once

#include "DynamicArray.h"
#include "ImmutableSequence.h"
#include "AccessValidation.h"


template <class T>
class ImmutableArraySequence : public ImmutableSequence<T>
{

private:
    DynamicArray<T> array;

public:
    ImmutableArraySequence(T* items, int count)
    {
        array = DynamicArray<T>(items, count);
    }

    ImmutableArraySequence()
    {
        array = DynamicArray<T>();
    }
    ImmutableArraySequence(int size)
    {
        array = DynamicArray<T>(size);
    }

    ImmutableArraySequence(const ImmutableArraySequence<T>& other)
    {
        array = other.array;
    }

    explicit ImmutableArraySequence(const DynamicArray<T>& data)
    {
        array = data;
    }

    explicit ImmutableArraySequence(const ImmutableSequence<T>* other)
    {
        for (int i = 0; i < other->GetLength(); i++)
        {
            Append(other->Get(i));
        }
    }
    

    size_t GetLength() const
    {
        return array.GetLength();
    }

    const T& GetFirst() const
    {
        return array[0];
    }

    const T& GetLast() const
    {
        return array[array.GetSize() - 1];
    }

    const T& Get(int index) const
    {
        return array.Get(index);
    }

    const T& operator[](int index) const
    {
        return array[index];
    }

    bool operator==(ImmutableArraySequence<T> other)
    {
        return array == other.array;
    }


    ImmutableArraySequence<T>* GetSubsequence(int startIndex, int endIndex) const
    {
        if (startIndex > endIndex)
        {
            throw std::invalid_argument("InvalidRange");
        }
        validateIndex(startIndex, __FUNCTION__, GetLength());
        validateIndex(endIndex, __FUNCTION__, GetLength());

        ImmutableArraySequence<T>* subSequence = new ImmutableArraySequence<T>;
        subSequence->array.Resize(endIndex - startIndex + 1);
        for (size_t i = startIndex; i <= endIndex; i++)
        {
            subSequence->array.Set(Get(i), i - startIndex);
        }
        return subSequence;
    }

    ImmutableArraySequence<T>* Append(T item) const
    {
        int currentSize = GetLength();
        ImmutableArraySequence<T>* newSeq = new ImmutableArraySequence<T>(array);
        newSeq->array.Resize(currentSize + 1);
        for (int i = 0; i < currentSize; i++)
        {
            newSeq->array.Set(Get(i), i);
        }
        newSeq->array.Set(item, currentSize);
        return newSeq;
    }

    ImmutableArraySequence<T>* Prepend(T item) const
    {
        int currentSize = GetLength();
        ImmutableArraySequence<T>* newSeq = new ImmutableArraySequence<T>(array);
        newSeq->array.Resize(currentSize + 1);
        for (int i = 1; i < currentSize + 1; i++)
        {
            newSeq->array.Set(Get(i - 1), i);
        }
        newSeq->array.Set(item, 0);
        return newSeq;
    }

    ImmutableArraySequence<T>* InsertAt(T item, int index) const
    {
        ImmutableArraySequence<T>* newSeq = new ImmutableArraySequence<T>(array);
        newSeq->array.Resize(GetLength() + 1);
        for (int i = newSeq->array.getSize() - 2; i >= index; i--)
        {
            newSeq->array.Set(newSeq->array[i], i + 1);
        }
        newSeq->array[index] = item;
        return newSeq;
    }

    ImmutableArraySequence<T>* Concat(const ImmutableSequence<T>& other) const
    {
        int thisSize = GetLength();
        int otherSize = other.GetLength();
        ImmutableArraySequence<T>* newSeq = new ImmutableArraySequence<T>(array);
        newSeq->array.Resize(thisSize + otherSize);
        for (int i = 0; i < otherSize; i++)
        {
            newSeq->array.Set(other.Get(i), thisSize + i);
        }
        return newSeq;
    }
};