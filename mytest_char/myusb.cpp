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
	printf("People size = %d\n", sizeof(People));

	B b;
	/*
    edit_box = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", NULL,
                              WS_CHILD | WS_VISIBLE | WS_VSCROLL |
                              ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL
                              | ES_AUTOHSCROLL | ES_READONLY,
                              CW_USEDEFAULT, CW_USEDEFAULT,
                              CW_USEDEFAULT, CW_USEDEFAULT,
                              main_win, (HMENU) ID_EDIT, instance, NULL);

    SendMessage(edit_box, WM_SETFONT, (WPARAM) CreateFont(13, 8, 0, 0,
                400, 0, 0, 0,
                0, 1, 2, 1,
                49, "Courier"), 0);
	*/
}