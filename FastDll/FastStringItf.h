#pragma once

class FastString;

class __declspec(dllexport) FastStringItf
{
	FastString *m_pThis;
public:
	FastStringItf(const char *psz);
	~FastStringItf(void);
	int Length(void) const;
	int Find(const char *psz) const;
};

