/*****************************************************************//**
 * \file   BigO.cpp
 * \brief  Provides timing function used to measure performance of a function.
 * This file also contains some common algorithm (search, sort, factorial)
 * implementations which you can use the measureTime function with.
 *
 * \author DF
 * \date   October 2020
 *********************************************************************/
#include "Functions.h"
#include "Pair.h"
#include "DynamicArray.h"

void BigOMain()
{
	std::cout << "Code to use BigO functions...." << endl;
	for (int w = 0; w < 5; w++)
	{
		int* arr = new int[4]{ 1000,10000,100000,1000000 };
		cout << setw(10) << "Size" << setw(20) << "Binary"
			<< setw(20) << "Linear" << endl;
		for (int i = 0; i < 4; i++)
		{
			int size = arr[i];
			int* data = new int[size];
			for (int x = 1; x <= size; x++)
			{
				data[x - 1] = x;
			}
			BinaryFunctor bin;
			LinearFunctor lin;
			lin.list = bin.list = data;
			lin.size = bin.size = size;
			lin.target = bin.target = -1;
			cout << setw(10) << size << setw(20)
				<< measureTime(bin) << setw(20)
				<< measureTime(lin) << endl;

			delete[]data;
			data = nullptr;


		}
		delete[] arr;
		arr = nullptr;
	}
}

template <class T>
T getLarger(T x, T y)
{
	return x < y ? y : x;
}
template <class T>
T getSmallest(T x, T y)
{
	return x < y ? x : y;
}

template <class T>
void print(list<T> items)
{
	cout << "[";
	for (typename list<T>::iterator iter = items.begin();
		iter != items.end(); iter++)
	{
		if (iter != items.begin())
		{
			cout << ", ";
		}
		cout << *iter;
	}
	cout << "]"<<endl;
}

void print(DynamicArray<int> arr)
{

	cout << "[";
	for (int i = 0; i < arr.size();i++)
	{
		if (i!=0)
		{
			cout << ", ";
		}
		cout << arr.get(i);
	}
	cout << "]" << endl;
}
int main()
{
	/*
	int x = 5, y = 10;
	cout << "Int: " << getLarger(x, y) 
		<<"," << getSmallest(x, y) << endl;

	char a = 'a', b = 'b';
	cout <<"Char: " << getLarger(a, b)
		<< "," << getSmallest(a, b) << endl;

	double s = 8.9, t = 1.3;
	cout << "Double: " << getLarger(s, t)
		<< "," << getSmallest(s, t) << endl;

	list<int> nums = {1,2,3,4,5};
	list<string> strings = {"this", "is", "a", "list"};
	print(nums);
	print(strings);

	cout << "-========================== Q4 ============================" << endl;
	Pair<int, string> p1(1, "Derek");
	Pair<string, char> p2("Tony Stark", 'a');
	Pair<float, double> p3(2.5f, 6.98);
	Pair<int, float> p4(1, 1.25);
	Pair<char, int> p5( 'a', 65);

	cout << p1<< p2 << p3 << p4 << p5 << endl;
	cout << "-========================== Q5 ============================" << endl;
	*/
	DynamicArray<int> arr(-1, 5);
	for (int i = 2; i <= 20; i += 2)
	{
		arr.add(i);
	}
	print(arr);


}
