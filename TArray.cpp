
#include "TArray.h"

using namespace std;


template<typename T>
TArray<T>::TArray(const TArray& other)
	: capacity{ other.capacity }, numElem{ other.numElem }, a{ new T[capacity] }
{
	for (int i = 0; i < numElem; ++i)
	{
		a[i] = other.a[i];
	}
}

template<typename T>
TArray<T>& TArray<T>::operator=(const TArray& rValue)
{
	if (&rValue != this)
	{
		if (capacity != rValue.capacity)
		{
			delete[] a;
			capacity = rValue.capacity;
			a = new T[capacity];
		}
		numElem = rValue.numElem;
		for (int i = 0; i < numElem; ++i)
		{
			a[i] = rValue.a[i];
		}
	}

	return *this;
}

template<typename T>
void TArray<T>::insert(T value)
{
	bool find = false;
	for (int i = 0; i < numElem; ++i)
	{
		if (a[i] == value && find == false)
		{
			find = true;
		}
	}
	if (find)
	{
		cerr << "Can't insert " << value << ", it is a duplicate";
	}
	else
	{
		T temp;
		a[numElem] = value;
		++numElem;
		for (int i = 0; i < numElem; i++)
		{
			for (int j = i + 1; j < numElem; j++)
			{
				if (a[i] > a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
}

template<typename T>
bool TArray<T>::find(T key) const
{
	int low = 0, mid, high = numElem - 1;
	while (a[low] <= a[high])
	{
		mid = (low + high) / 2;
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

template<typename T>
void TArray<T>::print() const
{
	cout << "(" << a[0];
	for (int i = 1; i < numElem; ++i)
	{
		cout << "," << a[i];
	}
	cout << "]" << endl;
}

template<typename T>
ostream& operator<<(ostream& out, const TArray<T>& arrary)
{
	out << "(" << arrary.a[0];
	for (int i = 1; i < arrary.numElem; ++i)
	{
		out << "," << arrary.a[i];
	}
	out << "]" << endl;
	return out;
}

template<typename T>
TArray<T>::~TArray()
{
	delete[] a;
}