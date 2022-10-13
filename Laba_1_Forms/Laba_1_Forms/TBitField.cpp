#include "TBitField.h"

TBitField::TBitField(int U_size)
{
	size = U_size / (sizeof(int) * 8) + 1;
	mem = new unsigned int[size];
	for (int i = 0; i < size; i++)
	{
		mem[i] = 0;
	}
}

TBitField::TBitField(const TBitField& tmp)
{
	size = tmp.size;
	mem = new unsigned int[size];
	for (int i = 0; i < size; i++)
	{
		mem[i] = tmp.mem[i];
	}
}

TBitField::~TBitField()
{
	delete[]mem;
}

TBitField& TBitField::operator = (TBitField tmp)
{
	if (size != tmp.size)
	{
		if (this->size != 0)
		{
			delete[]mem;
		}

		this->size = tmp.size;
		mem = new unsigned int[size];
	}
	for (int i = 0; i < size; i++)
	{
		mem[i] = tmp.mem[i];
	}
	return *this;
}

int TBitField::GetNumberMem(unsigned int K, unsigned int u_size)
{
	int L = -1;
	if (K >= 1 && K < u_size)
	{
		L = (K - 1) / (sizeof(int) * 8);
	}
	return L;
}

int TBitField::GetNumberBit(unsigned int K, unsigned int u_size)
{
	int L = -1;
	if (K >= 1 && K < u_size)
	{
		L = (K - 1) % (sizeof(int) * 8);
	}
	return L;
}

void TBitField::Add(unsigned int k, unsigned int u_size)
{
	int pos = GetNumberBit(k, u_size);
	int m = GetNumberMem(k, u_size);

	mem[m] = mem[m] | (1 << pos);
}

int TBitField::GetNumSize(unsigned int u_size) {

	int _size = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (sizeof(unsigned int) * 8); j++) {
			int k = i * (sizeof(unsigned int) * 8) + j + 1;
			if (k <= u_size) {
				if (mem[i] & (1 << j)) {
					_size++;
				}

			}
		}
	}

	return _size;
}

std::string TBitField::TBitFieldToString(unsigned int u_size)
{
	std::string STR = "";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (sizeof(unsigned int) * 8); j++) {
			int k = i * (sizeof(unsigned int) * 8) + j + 1;
			if (k <= u_size) {
				if (mem[i] & (1 << j)) {
					STR = STR + " " + std::to_string(k);
				}

			}
		}
	}
	return STR;
}

void TBitField::del(unsigned int k, unsigned int u_size)
{
	if (k > 0 && k <= u_size)
	{
		int pos = GetNumberBit(k, u_size);
		int m = GetNumberMem(k, u_size);
		mem[m] = mem[m] & (~(1 << pos));
	}
}

TBitField TBitField::operator&(TBitField tmp)
{
	TBitField res;
	if (size == tmp.size)
	{
		res = TBitField(*this);
		for (int i = 0; i < size; i++)
		{
			res.mem[i] = mem[i] & tmp.mem[i];
		}
	}
	return res;
}

TBitField TBitField::operator|(TBitField tmp)
{
	TBitField res;
	if (size == tmp.size)
	{
		res = TBitField(*this);
		for (int i = 0; i < size; i++)
		{
			res.mem[i] = mem[i] | tmp.mem[i];
		}
	}
	return res;
}

TBitField TBitField::operator~()
{
	TBitField res(*this);
	for (int i = 0; i < size; i++)
	{
		res.mem[i] = ~mem[i];
	}
	return res;
}




