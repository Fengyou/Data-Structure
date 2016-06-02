#include"Hash.h"

void TestHash()
{
	Hash<int> h(10);
	h.insert(1);
	h.insert(9);
	h.insert(21);
	h.insert(15);
	h.insert(5);
	h.Print();

	cout << "find 5?" << h.find(5) << endl;
	cout << "find 20?" << h.find(20) << endl;

	h.remove(9);
	h.remove(50);
	h.Print();
}

int main()
{
	TestHash();

	return 0;
}