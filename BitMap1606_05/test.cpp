#include<iostream>
#include"BitMap.h"

using namespace std;

void Test1()
{
	BitSet bs(100);
	bs.Set(9);
	bs.Set(10);
	bs.Set(40);

	cout << "Test 10?" << bs.Test(10) << endl;
	cout << "Test 21?" << bs.Test(21) << endl;
	cout << "Test 40?" << bs.Test(40) << endl;
	cout << "Test 41?" << bs.Test(41) << endl;

	bs.Reset(10);
	cout << "Test Reset 10?" << bs.Test(10) << endl;
}

void Test2()
{
	BitSet bs(-1);
}

int main()
{
	Test1();

	return 0;
}