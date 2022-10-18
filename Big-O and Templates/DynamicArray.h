#pragma once
template <class T>
class DynamicArray
{
	T* arr;
	int capacity;
	int top;
	T sentinel;
	void grow();
public:
	DynamicArray(T sentinel, int size = 10);
	DynamicArray(DynamicArray<T>& other);
	bool add(T c);
	bool insert(T c, int pos);
	bool remove(int index);
	T get(int index);
	bool set(T c, int index);
	int size();
	~DynamicArray();
};
template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T>& other)
{
	arr = new T[other.capacity];
	for (int i = 0; i < other.top; i++)
	{
		arr[i] = other.arr[i];
	}
	top = other.top;
	capacity = other.capacity;
	sentinel = other.sentinel;
}
template <class T>
void DynamicArray<T>::grow()
{
	T* temp = new T[capacity * 2];
	for (int i = 0; i < top; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	capacity *= 2;
	cout << "Growing : " << arr[0] << endl;
}

template <class T>
DynamicArray<T>::DynamicArray(T sentinel, int size)
{
	arr = new T[size];
	capacity = size;
	top = 0;
	this->sentinel = sentinel;
}

template <class T>
bool DynamicArray<T>::add(T c)
{
	if (top == capacity)
	{
		grow();
	}
	arr[top] = c;
	top++;
	return true;
}

template <class T>
bool DynamicArray<T>::insert(T c, int pos)
{
	if (pos >= 0 && pos < top)
	{
		if (top == capacity)
		{
			grow();
		}
		for (int i = top; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[pos] = c;
		top++;
		return true;
	}
	throw logic_error("Array Index out of bounds");
}

template <class T>
bool DynamicArray<T>::remove(int index)
{
	if (index >= 0 && index < top)
	{
		for (int i = index; i < top; i++)
		{
			arr[i] = arr[i + 1];
		}
		top--;
		return true;
	}
	throw logic_error("Array Index out of bounds");
}

template <class T>
T DynamicArray<T>::get(int index)
{
	if (index >= 0 && index < top)
	{
		return arr[index];
	}
	throw logic_error("Index out of bounds exception");
	//return this->sentinel;
}

template <class T>
bool DynamicArray<T>::set(T c, int index)
{
	if (index >= 0 && index < top)
	{
		arr[index] = c;
		return;
	}
	throw logic_error("Array out of bounds");
}

template <class T>
int DynamicArray<T>::size()
{
	return top;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->arr;
	//this->arr = nullptr;
	
}