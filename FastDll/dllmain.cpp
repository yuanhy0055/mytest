﻿// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include<stdio.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		printf("process attach of dll\n");
		break;
    case DLL_THREAD_ATTACH:
		printf("thread attach of dll\n");
		break;
    case DLL_THREAD_DETACH:
		printf("thread detach of dll\n");
		break;
    case DLL_PROCESS_DETACH:
		printf("process detach of dll\n");
        break;
    }
    return TRUE;
}

