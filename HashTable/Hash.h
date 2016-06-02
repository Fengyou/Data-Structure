#pragma once
#include<iostream>

using namespace std;

enum State{
	EMPTY = 0,
	EXIST = 1,
	DELETE = 2,
};
template<class T>
class Hash
{
public:
	Hash(int capacity)
		:_capacity(capacity)
		, _size(0)
	{
		_array = new T[_capacity];
		_state = new State[_capacity];

		memset(_array, T(), sizeof(T)*_capacity);
		memset(_state, EMPTY, sizeof(State)*_capacity);
	}
	~Hash()
	{
		delete[] _array;
		delete[] _state;
	}

	bool insert(const T& key)
	{
		/*	if (_size*10/_capacity>7)
		checkCapacity();*/
		if (_size == _capacity)
		{
			cout << "Table is full!" << endl;
			return false;
		}
		int index = key%_capacity;                      //int index=Func1(key)     
		while (_state[index] == EXIST)
		{
			if (_array[index] == key)
				return false;
			else
			{
				++index;                               // Func2(index,i++)                      
				if (index == _capacity)
					index = 0;
			}
		}

		_array[index] = key;
		_state[index] = EXIST;
		++_size;
		return true;
	}
	int find(const T& key)
	{
		if (_size == 0)
		{
			cout << "Table is empty!" << endl;
			return -1;
		}
		int index = key%_capacity;                    //Func1(key)
		while (_state[index] != EMPTY)
		{
			if (_state[index] == EXIST && _array[index] == key)
				return index;
			else
			{
				index++;                               //Func2(index,i++)
				if (index == _capacity)
					index = 0;
			}
		}
		return -1;
	}
	bool remove(T key)
	{
		if (_size == 0)
		{
			cout << "Table is empty!" << endl;
		}
		int index = find(key);
		if (index == -1)
		{
			cout << key << "不在表中..." << endl;
			return false;
		}
		else
		{
			while (_array[index] != key)
			{
				++index;                         //Func2(index,i++)
				if (index == _capacity)
					index = 0;
			}
			_state[index] = DELETE;
			--_size;
			cout << "删除" << key << "成功！..." << endl;
			return true;
		}
	}
	void Print()
	{
		for (int i = 0; i < _capacity; i++)
		{
			cout << i << "->data:" << _array[i] << "	" << "state:" << _state[i] << endl;
		}
	}
	//一次探测
	int Func1(const T& key)
	{
		int index = key%_capacity;
		return index;
	}
	//二次探测
	int Func2(int lastHash, int i)
	{
		int index = (lastHash + i*i) % _capacity;
		return index;
	}
protected:
	void checkCapacity()
	{
	}
private:
	T* _array;
	State* _state;
	int _capacity;
	int _size;
};