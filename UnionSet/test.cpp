#include"UnionSet.h"

void Test()
{
	int a[3][2] = { { 1, 2 }, { 2, 3 }, { 4, 5 } };
	UnionSet us(5);
	cout << us.CircleOfFriends(5, 3, a) << endl;
}

int main()
{
	Test();
	return 0;
}