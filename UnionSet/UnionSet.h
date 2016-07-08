#pragma once 
#include<iostream>
#include<assert.h>

using namespace std;

class UnionSet
{
public:
	UnionSet(int N)
		:_n(N)
	{
		_set = new int[N];
		for (int i = 0; i < N; ++i)
			_set[i] = -1;
	}
	int FindRoot(int x)
	{
		if (_set[x] >= 0)
			x = _set[x];
		return x;
	}
	void Union(int x1, int x2)
	{
		int r1 = FindRoot(x1);
		int r2 = FindRoot(x2);
		if (r1 != r2)
		{
			_set[r1] += _set[r2];
			_set[r2] = r1;
		}
	}
	int GetUnionCount()
	{
		int count = 0;
		for (int i = 0; i < _n;++i)
		if (_set[i] < 0)
			count++;
		return count - 1;
	}
	int CircleOfFriends(int n, int m, int set[][2])
	{
		assert(set);
		UnionSet fs(n);
		for (int i = 0; i < m; ++i)
		{
			int x1 = set[i][0];
			int x2 = set[i][1];
			fs.Union(x1, x2);
		}
		return fs.GetUnionCount();
	}
private:
	int* _set;
	int _n;
};
