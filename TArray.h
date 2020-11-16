
#ifndef TARRAY_H
#define TARRAY_H
#include <iostream>

template<typename T>
class TArray
{
	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const TArray<T>& arr);
public:
	TArray() : capacity{ 10 }, numElem{ 0 }, a{ new T[capacity] } {}
	TArray(int size) : capacity{ size }, numElem{ 0 }, a{ new T[capacity] }{}
	TArray(const TArray& other);
	TArray<T>& operator=(const TArray& rValue);
	void insert(T);
	bool find(T value) const;
	void print() const;
	~TArray();

private:
	int capacity, numElem;
	T* a;
	
};
#endif