#pragma once
template <class T>
class DynamicArray
{
	T* arr;
	int capacity;
	int top;
	T sentinel;

public:
	DynamicArray(T sentinel, int size = 10);
	bool add(T c);
	bool insert(T c, int pos);
	bool remove(int index);
	char get(int index);
	bool set(T c, int index);
	int size();
	~DynamicArray();
};
template <class T>
DynamicArray<T>::DynamicArray(T sentinel, int size)
{
	arr = new T[size];
	capacity = size;
	top = 0;
	this->sentinel = sentinel;
}

template <class T>
bool DynamicArray<T>::add(T c);

template <class T>
bool DynamicArray<T>::insert(T c, int pos);

template <class T>
bool DynamicArray<T>::remove(int index);

template <class T>
char DynamicArray<T>::get(int index)
{
	if (index >= 0 && index < top)
	{
		return arr[index];
	}
	throw logic_error("Index out of bounds exception");
	//return this->sentinel;
}

template <class T>
bool DynamicArray<T>::set(T c, int index);
template <class T>
int DynamicArray<T>::size()
{
	return top;
}
template <class T>
DynamicArray<T>::~DynamicArray();