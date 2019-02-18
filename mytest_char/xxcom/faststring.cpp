#include "faststring.h"
#include <string.h>

FastString::FastString(const char * psz)
: m_cch(strlen(psz)), m_psz(new char[m_cch + 1])
{
	strcpy(m_psz, psz);
}

FastString::~FastString()
{
	delete[] m_psz;
}

int FastString::Length() const
{
	return m_cch;
}

int FastString::Find(const char * psz) const
{
	return m_cch;
}
