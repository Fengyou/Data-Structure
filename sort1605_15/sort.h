#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

//1.插入排序
//1）直接插入 O(N^2)
void InsertSort(int *a, size_t n)
{
	assert(a);
	for (size_t i = 1; i < n; i++)
	{
		int end = i - 1,tmp = a[i];
		while (end>=0 && tmp<a[end])
		{
			a[end+1] = a[end];
			end--;
		}
		a[end+1] = tmp;
	}
}
//2）希尔  N^1.25---1.6*N^1.25
void ShellSort(int *a, size_t n)
{
	assert(a);
	size_t gap = n ;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = gap; i < n; ++i)
		{
			int tmp = a[i];
			size_t end = i - gap;
			while (end >= 0 && tmp<a[end])
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

//2.选择排序
//1）选择  O(N^2)
void SelectSort(int *a, size_t n)
{
	assert(a);
	size_t begin = 0;
	size_t end = n-1;
	size_t minIndex, maxIndex;
	while (begin<end)
	{
		minIndex=begin;
		maxIndex=end;
		for (size_t i=begin; i <= end; ++i)
		{
			if (begin<end && a[maxIndex] < a[i])
				maxIndex = i;
			if (begin<end && a[minIndex] > a[i])
				minIndex = i;
		}
		swap(a[minIndex], a[begin]);
		if(maxIndex==begin)
			maxIndex=minIndex;
		swap(a[maxIndex], a[end]);
		begin++;
		end--;
	}
}
//2）堆  O(NlogN)
void _AdjustDown(int *a, size_t size, size_t parent)
{
	assert(a);
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size)  &&  (a[child] < a[child+1]))
			child++;
		if (a[child]>a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int *a, size_t n)
{
	assert(a);
	//建堆
	size_t i = (n - 2) / 2;
	for (; i > 0; i--)
	{
		_AdjustDown(a, n, i);
	}
	_AdjustDown(a, n, i);
	//调整
	size_t end= n - 1;
	while (end>0)
	{
		swap(a[0], a[end]);
		_AdjustDown(a, end , 0);
		end--;
	}
}


//3.交换排序
//1）冒泡           O(N^2)
void BubbleSort(int *a, size_t n)
{
	assert(a);
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = 0; j < n - 1 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}

}
//2）快速        O(N^2)
void QuickSort(int *a, size_t begin,size_t end)
{
	assert(a);
	if (begin >= end)
		return;

	int key = a[end];
	size_t left = begin;
	size_t right = end - 1;
	while (left < right) 
	{
		//左→右，找大
		while (left<right && a[left] <= key)
			left++;
		//右→左，找小
		while (left<right && a[right] > key)
			right--;
		//交换
		if (left < right)
			swap(a[left], a[right]);
	}
	if (a[left] < key)
		++left;
	swap(a[left], a[end]);

	QuickSort(a, 0, left - 1);
	QuickSort(a, left + 1, end);
}
void QuickSort1(int *a, size_t begin, size_t end)//cur负责找比key小的数，prev等待cur来交换
{
	assert(a);
	if (begin >= end)
		return;

	int key = a[end];
	int prev=begin-1,cur = begin;
	while (cur<end)
	{
		if (a[cur] < key)
		{
			++prev;
			swap(a[prev], a[cur]);//1.prev==cur自身交换  2.prev与>key的数交换
		}
		++cur;
	}
	swap(a[++prev], a[end]);

	QuickSort1(a, 0, prev - 1);
	QuickSort1(a, prev + 1, end);
}

//4.归并                O(NlogN)
void Merge(int src[],int dest[],size_t begin,size_t mid,size_t end)
{
	assert(src);
	
	size_t begin1 = begin;
	size_t end1 = mid;
	size_t begin2 = mid;
	size_t end2 = end;
	size_t index=0;
	while (begin1 < end1 && begin2 < end2)
	{
		if (src[begin1] < src[begin2])
			dest[index++] = src[begin1++];
		else
			dest[index++] = src[begin2++];
	}
	if (begin1<end1)
		memcpy(&dest[index] ,&src[begin1],(sizeof(int)*(end1-begin1)));
	if (begin2<end2)
		memcpy(&dest[index], &src[begin2], (sizeof(int)*(end2 - begin2)));
	memcpy(&src[begin], dest, (sizeof(int)*(end - begin)));
}
void MergeSort(int a[], size_t n)
{
	assert(a);
	int *src = a;
	size_t gap = 1;
	int *dest = (int*)malloc(sizeof(int)*n);

	size_t begin,mid,end;
	while (gap < n)
	{
		size_t div = 0;
		for (; div < n; div += 2 * gap)
		{
			begin = div;
			mid = div + gap;
			end = div + 2 * gap;

			if (mid>n)
				mid = n;
			if (end > n)
				end = n;

			Merge(src, dest, begin, mid, end);
		}
		gap *= 2;
	}
	free(dest);
}

void Print(int a[], size_t n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
