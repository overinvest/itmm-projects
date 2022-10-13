#pragma once
#include "TBitField.h"

class TSet
{
private:
	int u_size;
	TBitField TB;
public:
	TSet(int _u_size = 0);
	TSet(const TSet& tmp);
	~TSet();

	TSet& operator=(TSet tmp);

	void Add(int k);
	void Del(int k);
	std::string TSetToString();

	TSet operator&(TSet tmp);
	TSet operator|(TSet tmp);
	TSet operator~();
	int GetSize();
};

