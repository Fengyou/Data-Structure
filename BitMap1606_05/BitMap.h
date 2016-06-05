#pragma once
#include<assert.h>
#include<string.h>

class BitSet
{
public:
	BitSet(size_t N)
	{
		_size = N / 32 + 1;
		_array = new size_t[_size];
		memset(_array, 0, sizeof(size_t)* _size);
	}
	~BitSet()
	{
		delete[] _array;
	}
public:
	void Set(size_t num)
	{
		size_t index = num / 32;
		size_t pos = num % 32;

		assert(index < _size);

		_array[index] |= (1 << (32 - pos));
	}
	void Reset(size_t num)
	{
		size_t index = num / 32;
		size_t pos = num % 32;

		assert(index < _size);

		_array[index] &= ~(1 << (32 - pos));
	}
	void Clear()
	{
		memset(_array, 0, sizeof(size_t)*_size);
	}
	bool Test(size_t num)
	{
		size_t index = num / 32;
		size_t pos = num % 32;

		assert(index < _size);

		return _array[index] & (1 << (32 - pos));
	}
private:
	size_t* _array;
	size_t _size;
};

