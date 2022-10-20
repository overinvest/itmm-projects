#include "TVector.h"

template <typename T>
TVector<T>::TVector(int _size, int startM) {
	size = _size;
	//start = tmp.start; //мб надо после 82 - ой строки
	start = startM;
	arr = new T[size];
	for (int i = 0; i < _size; i++)
	{
		arr[i] = T(0);
	}
}
template<typename T>
TVector<T>& TVector<T>::operator=(const TVector &tmp)
{
	if (size != tmp.size)
	{
		if (size != 0)
		{
			delete[]arr;
		}
		size = tmp.size;
		arr = new T[size];
	}
	start = tmp.start;
	for (int i = 0; i < size; i++)
	{
		arr[i] = tmp.arr[i];
	}
	return *this;
}
template<typename T>
TVector<T> TVector<T>::operator+(const TVector& tmp)
{
	TVector<T> res(*this);
	if (size == tmp.size)
	{
		res = *this;
		for (int i = 0; i < size; i++)
		{
			res.arr[i] = arr[i] + tmp.arr[i];
		}
	}
	return res;
}
template<typename T>
TVector<T> TVector<T>::operator-(const TVector& tmp)
{
	TVector<T> res(*this);
	if (size == tmp.size)
	{
		res = *this;
		for (int i = 0; i < size; i++)
		{
			res.arr[i] = arr[i] - tmp.arr[i];
		}
	}
	return res;
}
template<typename T>
TVector<T> TVector<T>::operator*(const TVector<T>& tmp)
{
	T res(0);
	if (size == tmp.size && start == tmp.start)
	{
		for (int i = 0; i < size; i++)
		{
			res = arr[i] * tmp.arr[i];
		}
	}
	return res;
}
template<typename T>
TVector<T> TVector<T>::operator+(const T& val)
{
	TVector<T> result(*this);
	if (val != 0)
	{
		for (int i = 0; i < result.size; i++)
		{
			result.arr[i] += val;
		}
	}
	return result;
}
template<typename T>
TVector<T> TVector<T>::operator-(const T& val)
{
	TVector<T> result(*this);
	if (val != 0)
	{
		for (int i = 0; i < result.size; i++)
		{
			result.arr[i] -= val;
		}
	}
	return result;
}
template<typename T>
TVector<T> TVector<T>::operator*(const T& k)
{
	TVector<T> res(*this);
	for (int i = 0; i < size; i++)
	{
		res.arr[i] *= k;
	}
	return res;
}
template <typename T>
T& TVector<T>::operator[](int k) {
	if (!(k < start || k > size + start))
	{
		return arr[k - start];
	}
}
