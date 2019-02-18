#include "stdafx.h"
#include <stdio.h>

static HWND edit_box;


class People
{
};


class A
{
public:
	int ia;

public:
	A() { printf("构造 A\n"); }
};

class B : A
{
public:
	B() { printf("构造 B\n"); }

public:
	int ib;
};

void U_main()
{
	HINSTANCE hDll;	//DLL句柄
	hDll = LoadLibrary(L"..\\Debug\\FastDll.dll");
	if (hDll != NULL) {
		printf("Load DLL Ok!\n");
		FreeLibrary(hDll);
	}
	else {
		printf("Load FastDll.dll Error\n");
	}
}