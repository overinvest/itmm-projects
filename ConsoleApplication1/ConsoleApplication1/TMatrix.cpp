#include "TMatrix.h"

template<class T>
TMatrix<T>::TMatrix(int _size_matr) : TVector<TVector<T> >(_size_matr)
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<T>(this->size - i, i);
	}
}

template<class T>
TMatrix<T>::TMatrix(const TMatrix& mt) : TVector<TVector<T> >(mt) {}

template<class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& tmp)
{
	if (this != &tmp)
	{
		if (this->size != tmp.size)
		{
			this->size = tmp.size;
			delete[] this->arr;
			this->arr = new TVector<T>[this->size];
		}
		this->start = tmp.start;
		for (int i = 0; i < this->size; ++i)
			this->arr[i] = tmp.arr[i];
	}
	return *this;
}

template<class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
	TMatrix<T> result(*this);
	for (int i = 0; i < this->size; i++)
	{
		result.arr[i] = this->arr[i] + mt.arr[i];
	}
	return result;
}

template<class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
	TMatrix<T> result(*this);
	for (int i = 0; i < this->size; i++)
	{
		result.arr[i] = this->arr[i] - mt.arr[i];
	}
	return result;
}
