#pragma once
#include <iostream>
#include <list>
#include <chrono>
#include <iomanip>
using namespace std;

template <typename FuncType>
double measureTime(FuncType func)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
	func();
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	return (end - st) / std::chrono::nanoseconds(1);

}

int binarySearch(int* list, int size, int target);
int linearSearch(int* list, int size, int value);
void printFirstItem(int arrayOfItems[]);
void bubbleSort(int arr[], int size);
void factorial(int i);

struct BinaryFunctor
{
	int* list;
	int size;
	int target;

	void operator()()
	{
		binarySearch(list, size, target);
	}
};

struct LinearFunctor
{
	int* list;
	int size;
	int target;

	void operator()()
	{
		binarySearch(list, size, target);
	}
};