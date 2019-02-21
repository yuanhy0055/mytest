﻿#pragma once
class __declspec(dllexport) FastString
{
	char *m_psz;
public:
	int (FastString::*FPP)(void) const;
public:
	FastString(const char *psz);
	~FastString(void);
	int Length(void) const;				// 返回字符数目
	int Find(const char *psz) const;	// 返回偏移量
};