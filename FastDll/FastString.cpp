#include "stdafx.h"
#include "FastString.h"
#include <stdio.h>
#include <string.h>

FastString::FastString(const char *psz)
{
	m_psz = new char[strlen(psz)+1];
	strcpy(m_psz, psz);

	printf("------ ^FastString\n");
}

FastString::~FastString()
{
	delete[] m_psz;

	printf("------ ~FastString\n");
}

void FastString::Delete()
{
	delete this;
}

int FastString::Length() const
{
	return strlen(m_psz);
}

int FastString::Find(const char * psz) const
{
	printf("Find in progress...\n");
	return 7;
}

int FastString::FindN(const char * psz, int n) const
{
	printf("New Find%d ...\n", n);
	return 8;
}

extern "C" { __declspec(dllexport) int add(int x, int y); }
int add(int x, int y)
{
	return x+y+10000;
}

extern "C" __declspec(dllexport) FastString*  CreateFastString(const char* psz);
FastString * CreateFastString(const char * psz)
{
	return new FastString(psz);
}