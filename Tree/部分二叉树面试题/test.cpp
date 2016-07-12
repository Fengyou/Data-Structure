#include"BinaryTree.h"

int prev0[] = { 1,2,4,3,5};
int in0[] = { 4, 2, 1, 5, 3 };
Tree<int> t0(prev0, sizeof(prev0) / sizeof(prev0[0]), in0, sizeof(in0) / sizeof(in0[0]));

int prev1[] = { 1, 2, 3, 4, 5, 6 };
int in1[] = { 3, 2, 4, 1, 6, 5 };
Tree<int> t1(prev1, sizeof(prev1)/sizeof(prev1[0]), in1, sizeof(in1)/sizeof(in1[0]));

int prev2[] = { 1, 2, 4, 5, 3, 6, 7 };
int in2[] = { 4, 2, 5, 1, 6, 3, 7 };
Tree<int> t2(prev2, sizeof(prev2)/sizeof(prev2[0]), in2, sizeof(in2)/sizeof(in2[0]));

void TestGrandfather()
{
	cout << "TestGrandfather()--------------------------------------------------" << endl;

	t1.Print();

	//int x = 6;
	//cout << t1.Find(x) << endl;

	int x = 3;
	int y = 6;
	t1.GetNearestGandfather(t1.Find(x),t1.Find(y));
}
void TestFarthest()
{
	cout << "TestFarther()--------------------------------------------------" << endl;

	t1.Print();
	cout << t1.GetFarthest() << endl;

	t2.Print();
	cout << t2.GetFarthest() << endl;
}
void TestTree()
{
	cout << "TestTree()--------------------------------------------------" << endl;

	int prev0[] = { 1, 2, 4, 3, 5 };
	int in0[] = { 4, 2, 1, 5, 3 };
	Tree<int> t0(prev0, sizeof(prev0)/sizeof(prev0[0]), in0, sizeof(in0)/sizeof(in0[0]));
	t0.Print();

	int prev1[] = { 1, 2, 3, 4, 5, 6 };
	int in1[] = { 3, 2, 4, 1, 6, 5 };
	Tree<int> t1(prev1, sizeof(prev1)/sizeof(prev1[0]), in1, sizeof(in1)/sizeof(in1[0]));
	t1.Print();

	int prev2[] = { 1, 2, 4, 5, 3, 6, 7 };
	int in2[] = { 4, 2, 5, 1, 6, 3, 7 };
	Tree<int> t2(prev2, sizeof(prev2)/sizeof(prev2[0]), in2, sizeof(in2)/sizeof(in2[0]));
	t2.Print();
}
void TestIsComplete()
{	
	cout << "TestIscomplete()--------------------------------------------------" << endl;

	t0.Print();
	cout<<t0.IsComplete()<<endl;

	t1.Print();
	cout << t1.IsComplete() << endl;

	t2.Print();
	cout<<t2.IsComplete()<<endl;
}
void TestTransform()
{
	t1.Print();
	t1.Transform();
}
int main()
{
	TestTree();
	TestGrandfather();
	TestFarthest();
	TestIsComplete();
	TestTransform();

	return 0;
}