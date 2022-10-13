#include "TSet.h"

TSet::TSet(int _u_size)
{
	u_size = _u_size;
	TB = TBitField(u_size);
}

TSet::TSet(const TSet& tmp)
{
	u_size = tmp.u_size;
	TB = tmp.TB;
}

TSet& TSet::operator=(TSet tmp)
{
	if (u_size != tmp.u_size)
	{
		u_size = tmp.u_size;
	}
	TB = tmp.TB;
	return (*this);
}

TSet::~TSet() {}

void TSet::Add(int k)
{
	TB.Add(k, u_size);
}

void TSet::Del(int k)
{
	TB.del(k, u_size);
}

std::string TSet::TSetToString()
{
	return TB.TBitFieldToString(u_size);
}

TSet TSet::operator&(TSet tmp)
{
	TSet res;
	if (u_size == tmp.u_size)
	{
		res = TSet(*this);
		res.TB = TB & tmp.TB;
	}
	return res;
}

TSet TSet::operator|(TSet tmp)
{
	TSet res;
	if (u_size == tmp.u_size)
	{
		res = TSet(*this);
		res.TB = TB | tmp.TB;
	}
	return res;
}

TSet TSet::operator~()
{
	TSet res(*this);
	res.TB = ~TB;
	return res;
}

int TSet::GetSize() {
	return TB.GetNumSize(u_size);
}
