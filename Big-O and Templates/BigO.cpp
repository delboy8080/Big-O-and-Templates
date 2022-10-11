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



int main()
{
	
}
