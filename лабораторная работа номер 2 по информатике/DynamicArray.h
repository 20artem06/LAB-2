#pragma once

#include <stdexcept>
#include "AccessValidation.h"
template <class T>
class DynamicArray
{
public:
	DynamicArray(int size)
		: m_Data(new T[size])
		, m_Count(size)
	{
	}

	DynamicArray(const T* items, int count)
		: m_Data(new T[count])
		, m_Count(count)
	{
		for (size_t i = 0; i < m_Count; ++i)
		{
			m_Data[i] = items[i];
		}
	}

	DynamicArray(const DynamicArray<T>& other)
		: DynamicArray(other.m_Data, other.m_Count)
	{
	}

	~DynamicArray()
	{
		delete[] m_Data;
	}

	T Get(size_t index) const
	{
		if (index >= m_Count)
		{
			throw std::out_of_range();
		}

		return m_Data[index];
	}

	size_t GetSize() const
	{
		return m_Count;
	}

	void Set(size_t index, T value)
	{
		if (index >= m_Count)
		{
			throw std::out_of_range();
		}

		m_Data[index] = value;
	}

	void resize(size_t newSize)
	{
		DynamicArray newArray(newSize);
		size_t n = newSize > m_Count ? m_Count : newSize;
		for (size_t i = 0; i != n; ++i)
		{
			newArray.m_Data[i] = m_Data[i];
		}
		swapArray(newArray);
	}

	bool operator==(const DynamicArray<T>& other) const
	{

		if (m_Count != other.GetSize())
			return 0;

		for (int i = 0; i < other.GetSize(); i++)
		{
			if (m_Data[i] != other.m_Data[i])
				return 0;
		}
		return 1;
	}

	T& operator[](int index) const
	{
		validateAccessByIndex(index, __FUNCTION__, m_Count);
		return m_Data[index];
	}

	DynamicArray& operator=(DynamicArray const& other)
	{
		if (this != &other)
		{
			DynamicArray tempArray(other);
			tempArray.swapArray(*this);
		}
		return *this;
	}

private:
	T* m_Data = nullptr;
	size_t m_Count = 0;

	void swapArray(DynamicArray& other)
	{
		std::swap(m_Count, other.m_Count);
		std::swap(m_Count, other.m_Count);
	}
};