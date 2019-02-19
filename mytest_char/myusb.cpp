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
	A() { printf("���� A\n"); }
};

class B : A
{
public:
	B() { printf("���� B\n"); }

public:
	int ib;
};

typedef int(*lpAddFun)(int, int); //�궨�庯��ָ������
lpAddFun __declspec(dllimport) add(int a, int b);

void U_main()
{
	HINSTANCE hDll;	//DLL���
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