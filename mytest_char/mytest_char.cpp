// mytest_char.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "mytest_char.h"
#include <stdio.h>
#include <io.h >
#include <fcntl.h >

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


//>>yuanyuan
HBITMAP g_hbmBall = NULL;
#define EDIT_BUF_INCREMENT 1024

static HWND edit_box;
enum
{
    ID_EXIT = 100,
    ID_REFRESH,
    ID_EDIT
};
static char *edit_buffer = NULL;

static int edit_buffer_size = 0;
static int edit_buffer_pos = 0;

static void edit_printf(const char *s, ...)
{
    //va_list args;
    //va_start(args, s);

    //if (edit_buffer_size - edit_buffer_pos < EDIT_BUF_INCREMENT) {
    //    char *tmp = realloc(edit_buffer, edit_buffer_size + EDIT_BUF_INCREMENT);

    //    if (tmp) {
    //        edit_buffer = tmp;
    //        edit_buffer_size += EDIT_BUF_INCREMENT;
    //    } else {
    //        return;
    //    }
    //}

    //edit_buffer_pos += vsnprintf(edit_buffer + edit_buffer_pos,
    //                             EDIT_BUF_INCREMENT - 1, s, args);
    //va_end(args);
}

//<<yuanyuan

void InitConsoleWindow(void)
{
	int hCrt;
	FILE *hf;
	AllocConsole();
	hCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	hf = _fdopen(hCrt, "w");
	*stdout = *hf;
	setvbuf(stdout, NULL, _IONBF, 0);
	// test code
	fprintf(stdout, "InitConsoleWindow OK!\n");
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MYTEST_CHAR, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	InitConsoleWindow();

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MYTEST_CHAR));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYTEST_CHAR));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+2);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MYTEST_CHAR);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU,
		0, 0, 1024, 768, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	//YY-->
	//edit_box = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL,
	//	WS_CHILD | WS_VISIBLE | WS_VSCROLL |
	//	ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL
	//	| ES_AUTOHSCROLL | ES_READONLY,
	//	CW_USEDEFAULT, CW_USEDEFAULT,
	//	CW_USEDEFAULT, CW_USEDEFAULT,
	//	hWnd, (HMENU)ID_EDIT, hInstance, NULL);
	//SendMessage(edit_box, WM_SETFONT, (WPARAM)CreateFont(13, 8, 0, 0,
	//	400, 0, 0, 0,
	//	0, 1, 2, 1,
	//	49, L"Courier"), 0);

	//SendMessage(edit_box, WM_SETTEXT, 0, (LPARAM) edit_buffer);

//<--YY
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)L"Hello0000");
	//SendMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0); // 最小化

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	//printf("MSG get in! %u\n", message);
	switch (message)
	{
	case WM_CREATE:
		g_hbmBall = (HBITMAP)LoadImage(
			GetModuleHandle(NULL), L"E:\\Nico\\Pictures\\girl.bmp",
			IMAGE_BITMAP, 0, 0,	LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		if (g_hbmBall == NULL)
			//MessageBox(hWnd, L"Could not load BMP!", L"Error", MB_OK | MB_ICONEXCLAMATION);
			printf("Load bmp error!\n");
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_RUN:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_ABOUT:
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			//for(int i=0;i<1000000000;i++)
			//	;
			extern void pc_main();
			pc_main();
			extern void U_main(void);
			U_main();
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...

		if (g_hbmBall != NULL) {
			BITMAP bm;
			HDC hdcMem = CreateCompatibleDC(hdc);
			HGDIOBJ hbmOld = SelectObject(hdcMem, g_hbmBall);
			GetObject(g_hbmBall, sizeof(bm), &bm);
			memset(bm.bmBits, 0, 1800*200);
			BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
			SelectObject(hdcMem, hbmOld);
			DeleteDC(hdcMem);
		}
		else {
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));
			TextOut(hdc, 100, 200, L"g_hbmBall is NULL", 17);
		}

		// <<The GDI in Windows API>>
		// http://zetcode.com/gui/winapi/gdi/
		SetPixel(hdc, 10, 410, RGB(0, 0xFF, 0));  // green
		RECT r;
		GetClientRect(hWnd, &r);
		for (int i = 0; i < 1000; i++) {
			int x = rand() % r.right;
			int y = rand() % r.bottom;
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
