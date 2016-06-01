#include"sort.h"

void TestInsert()
{
	cout << "Insert: " << endl;

	int a[] = { 3, 5, 6, 8, 9, 7, 2, 4, 1, 0 };
	InsertSort(a, 10);
	Print(a,10);
}

void TestShell()
{
	cout << "Shell: " << endl;

	int a[] = { 3, 5, 6, 8, 9, 7, 2, 4, 1, 0 };
	ShellSort(a, 10);
	Print(a, 10);
}

void TestSelect()
{
	cout << "Select: " << endl;

	int a[] = { 3, 5, 6, 8, 9, 7, 2, 4, 1, 0 };
	SelectSort(a, 10);
	Print(a, 10);
}

void TestHeap()
{
	cout << "Heap: " << endl;

	int a[] = { 3, 5, 6, 8, 9, 7, 2, 4, 1, 0 };
	HeapSort(a, 10);
	Print(a, 10);
}

void TestBubble()
{
	cout << "Bubble: " << endl;

	int a[] = { 3, 5, 6, 8, 9, 7, 2, 4, 1, 0 };
	BubbleSort(a, 10);
	Print(a, 10);
}

void TestQuick()
{
	cout << "Quick: " << endl;

	int a[] = { 3, 8, 6, 0, 9, 7, 2, 4, 1,5  };
	QuickSort(a,0,9);
	Print(a, 10);
}
void TestQuick1()
{
	cout << "Quick1: " << endl;

	int a[] = { 3, 8, 6, 0, 9, 7, 2, 4, 1, 5 };
	QuickSort1(a, 0, 9);
	Print(a, 10);
}

void TestMerge()
{
	cout << "Merge: " << endl;

	int a[] = { 3, 8, 6, 0, 9, 7, 2, 4, 1, 5 };
	MergeSort(a, 10);
	Print(a,10);
}

int main()
{
	TestInsert();
	TestShell();
	TestSelect();
	TestHeap();
	TestBubble();
	TestQuick();
	TestQuick1();
	TestMerge();

	return 0;
}

