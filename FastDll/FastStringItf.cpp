#include "stdafx.h"
#include <assert.h>
#include "FastString.h"
#include "FastStringItf.h"

FastStringItf::FastStringItf(const char * psz)
	: m_pThis(new FastString(psz))
{
	assert(m_pThis != 0);
}

FastStringItf::~FastStringItf(void)
{
	delete m_pThis;
}

int FastStringItf::Length(void) const
{
	return m_pThis->Length();
}

int FastStringItf::Find(const char * psz) const
{
	return m_pThis->Find(psz);
}

extern "C" __declspec(dllexport) FastStringItf*  CreateFastString(const char* psz);
FastStringItf * CreateFastString(const char * psz)
{
	//return nullptr;
	return new FastStringItf(psz);
}