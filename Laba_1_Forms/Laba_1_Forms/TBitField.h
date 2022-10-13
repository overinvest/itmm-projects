#pragma once
#include <string>
#include <string.h>

class TBitField
{
private:
	unsigned int* mem;
	int size;
public:
	TBitField(int U_size = 0);
	TBitField(const TBitField& tmp);
	~TBitField();
	TBitField& operator = (TBitField tmp);

private:
	int GetNumberMem(unsigned int K, unsigned int u_size);
	int GetNumberBit(unsigned int K, unsigned int u_size);

public:
	void Add(unsigned int k, unsigned int u_size);
	int GetNumSize(unsigned int u_size);
	std::string TBitFieldToString(unsigned int u_size);
	void del(unsigned int k, unsigned int u_size);
	TBitField operator&(TBitField tmp);
	TBitField operator|(TBitField tmp);
	TBitField operator~();

};





