#pragma once

#include <iostream>
#include "TVector.cpp"

using namespace std;

template <typename T>
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int _size_matr = 0);
	TMatrix(const TMatrix& tmp);
	TMatrix& operator=(const TMatrix& tmp);
	TMatrix  operator+ (const TMatrix& mt);
	TMatrix  operator- (const TMatrix& mt);

	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.size; i++)
		{
			in >> mt.arr[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.size; i++)
		{
			out << mt.arr[i] << endl;
		}
		return out;
	}
};
