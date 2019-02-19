﻿#include "stdafx.h"
#include "FastString.h"
#include <stdio.h>
#include <string.h>

FastString::FastString(const char *psz)
{
	m_psz = new char[strlen(psz)+1];
	strcpy(m_psz, psz);
}

extern "C" { __declspec(dllexport) int add(int x, int y); }

FastString::~FastString()
{
	delete[] m_psz;
}

int FastString::Length() const
{
	return strlen(m_psz);
}

int FastString::Find(const char * psz) const
{
	printf("Func in progress...\n");
	return 7;
}

int add(int x, int y)
{
	return x+y+10000;
}
