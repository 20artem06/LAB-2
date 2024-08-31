#pragma once

template <class T>
class Sequence
{
public:
	
	virtual const T& GetFirst() const = 0;
	virtual const T& GetLast() const = 0;

	virtual const T& Get(size_t index) = 0;
	

	virtual Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) const = 0;
	virtual size_t GetLength() const = 0;
	virtual Sequence<T>& InsertAt(const T& value, int index) = 0;
	virtual Sequence<T>& Append(const T& value) = 0;
	virtual Sequence<T>& Prepend(const T& value) = 0;
	virtual Sequence<T>& Concat(const Sequence<T>& other) = 0;
	virtual T& operator[](int index) = 0;
	
	virtual ~Sequence() {}
};
