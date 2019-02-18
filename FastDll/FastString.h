#pragma once
class __declspec(dllexport) FastString
{
	char *m_psz;
public:
	FastString(const char *psz);
	~FastString(void);
	int Length(void) const;
	int Find(const char *psz) const;
};