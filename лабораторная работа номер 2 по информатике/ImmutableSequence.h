#pragma once


template <typename T>
class ImmutableSequence
{
public:
    virtual const T& GetFirst() const = 0;
    virtual const T& GetLast() const = 0;
    virtual const T& Get(int index) const = 0;
    virtual size_t GetLength() const = 0;
    virtual const T& operator[](int index) const = 0;
    virtual ImmutableSequence<T>* InsertAt(const T data, int index) const = 0;
    virtual ImmutableSequence<T>* Append(const T value) const = 0;
    virtual ImmutableSequence<T>* Prepend(const T value) const = 0;
    virtual ImmutableSequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual ImmutableSequence<T>* Concat(const ImmutableSequence<T>& other) const = 0;
};
