#include "ifaststring.h"

// faststring.h  µœ÷¿‡
class FastString : public IFastString
{
	const int m_cch;
	char* m_psz;
public:
	FastString(const char* psz);
	~FastString();
	int Length() const;
	int Find(const char* psz) const;
};