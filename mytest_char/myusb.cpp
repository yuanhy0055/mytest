#include "stdafx.h"
#include <stdio.h>

#include "../FastDll/FastStringItf.h"

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
typedef FastStringItf *(*crtFstr)(const char *);
crtFstr __declspec(dllimport) CreateFastString(const char* psz);

void U_main()
{
	HINSTANCE hDll;	//DLL句柄
	hDll = LoadLibrary(L"..\\Debug\\FastDll.dll");
	if (hDll != NULL) {
		printf("Load DLL Ok!\n");
		lpAddFun add = (lpAddFun)GetProcAddress(hDll, "add");
		printf("Call (3, 7) = %d\n", add(3, 7));

		//FastString *fstr = new FastString("abcde");
		crtFstr CreateFastString = (crtFstr)GetProcAddress(hDll, "CreateFastString");
		FastStringItf *fstr = CreateFastString("abcde");
		int LEN = fstr->Length();
		//fstr->Find("123");
		//delete fstr;

		FreeLibrary(hDll);
	}
	else {
		printf("Load FastDll.dll Error\n");
	}
}