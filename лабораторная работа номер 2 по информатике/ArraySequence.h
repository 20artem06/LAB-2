#pragma once

#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : Sequence<T>
{
private:
	DynamicArray<T> m_Items;

public:
	ArraySequence()
		: m_Items(0)
	{
	}

	ArraySequence(const T* items, size_t count)
		: m_Items(items, count)
	{
	}

	ArraySequence(const ArraySequence<T>& other)
		: m_Items(other.m_Items)
	{
	}

	~ArraySequence() {}

	const T& GetFirst() const 
	{
		return m_Items.Get(0);
	}

	const T& GetLast() const 
	{
		const size_t size = m_Items.GetSize();
		return m_Items.Get(size - 1);
	}

	const T& Get(size_t index) const 
	{
		return m_Items.Get(index);
	}

	T& operator[](int index)
	{
		return array[index];
	}

	ArraySequence<T>& operator=(ArraySequence<T> other)
	{
		array = other.array;
		return *this;
	}

	bool operator==(ArraySequence<T> other)
	{
		return array == other.array;
	}

	Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) const 
	{
		const size_t count = endIndex - startIndex + 1;
		return new ArraySequence<T>(&m_Items.Get(startIndex), count);
	}

	size_t GetLength() const override
	{
		return m_Items->GetSize();
	}


	ArraySequence<T>& Append(const T& item) 
	{
		const size_t size = m_Items->GetSize();
		m_Items->Resize(size + 1);
		m_Items->Set(size, item);
		return *this;
	}

	ArraySequence<T>& Prepend(const T& item) 
	{
		InsertAt(0, item);
		return *this;
	}

	ArraySequence<T>& InsertAt(const T& item, size_t index)
	{
		const size_t size = m_Items->GetSize();
		m_Items->Resize(size + 1);
		for (size_t i = size; i > index; --i)
		{
			m_Items.Set(i, m_Items.Get(i - 1));
		}

		m_Items->Set(index, item);
		return *this;
	}

	ArraySequence<T>& Concat(const Sequence<T>& other)
	{
		Sequence<T>* result = new ArraySequence<T>(*this);
		for (size_t i = 0; i < other.GetLength(); ++i)
		{
			result->Append(other.Get(i));
		}

		return *result;
	}
};