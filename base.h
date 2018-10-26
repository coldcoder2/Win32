	//The Base of Win32 Application
	#include <bits/stdc++.h>
	#include <windows.h>
	#include <Winuser.h>
	#include <conio.h>
	#include <ctime>
	using namespace std;
	
	#define stdin_handle (GetStdHandle(STD_INPUT_HANDLE))
	#define stdout_handle (GetStdHandle(STD_OUTPUT_HANDLE))
	#define stderr_handle (GetStdHandle(STD_ERROR_HANDLE))

	int clean()
	{
		return system("cls");
	}
	
	bool gotoxy(short x,short y)
	{
		COORD position = {x,y};
		HANDLE handle = stdout_handle;
		return SetConsoleCursorPosition(handle,position);
	}
	
	bool show(HWND hwnd)
	{
		return ShowWindow(hwnd,SW_SHOW);
	}
	
	bool hide(HWND hwnd)
	{
		return ShowWindow(hwnd,SW_HIDE);
	}
	
