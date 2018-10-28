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
	
	#ifdef DLL
	#	ifdef DLL_FILE
	#		define API __declspec(dllexport)
	#	else
	#		define API __declspec(dllimport)
	#	endif
	#endif
	
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
	
	void Click(DWORD MouseEvent = MOUSEEVENTF_LEFTDOWN,DWORD ms = 10)
	{
		switch(MouseEvent)
		{
			case MOUSEEVENTF_LEFTDOWN:
			case MOUSEEVENTF_LEFTUP:
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				Sleep(ms);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				break;
			default:
				break;
		}
	}
	
	void LeftClick(DWORD ms = 10)
	{
		Click(MOUSEEVENTF_LEFTDOWN,ms);
	}
	
