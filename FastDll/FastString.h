#include "IFastString.h"

class FastString : public IFastString
{
	char *m_psz;
public:
	FastString(const char *psz);
	~FastString(void);
	void Delete();
	int Length(void) const;				// 返回字符数目
	int Find(const char *psz) const;	// 返回偏移量
	int FindN(const char *psz, int n) const;
};