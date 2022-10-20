#pragma once

#include <iostream>

using namespace std;

template <typename T>
class TVector
{
protected:
	T* arr;
	int size;
	int start;
public:
	TVector<T>(int _size = 0, int startM = 0);
	TVector& operator=(const TVector& tmp);
	TVector operator+(const TVector& tmp);
	TVector operator-(const TVector& tmp);
	TVector operator*(const TVector& tmp);

	TVector  operator+(const T& val);
	TVector  operator-(const T& val);
	TVector operator*(const T& k);
	T& operator[](int k);
	~TVector() {
		delete[] this->arr;
	}

	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.arr[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.size; i++)
		{
			out << v.arr[i] << ' ';
		}
		return out;
	}
};

