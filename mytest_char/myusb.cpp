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
typedef FastStringItf *(*crtFstr)(const char *);
crtFstr __declspec(dllimport) CreateFastString(const char* psz);

void U_main()
{
	HINSTANCE hDll;	//DLL���
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