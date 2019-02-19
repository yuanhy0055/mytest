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

typedef int(*lpAddFun)(int, int); //宏定义函数指针类型
lpAddFun __declspec(dllimport) add(int a, int b);

void U_main()
{
	HINSTANCE hDll;	//DLL句柄
	hDll = LoadLibrary(L"..\\Debug\\FastDll.dll");
	if (hDll != NULL) {
		printf("Load DLL Ok!\n");
		lpAddFun pfunc = (lpAddFun)GetProcAddress(hDll, "add");
		printf("Call (3, 7) = %d\n", pfunc(3, 7));
		FreeLibrary(hDll);
	}
	else {
		printf("Load FastDll.dll Error\n");
	}
}