#include <bits/stdc++.h>
#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <algorithm>
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(a);i>=(b);i--)
#define max(x,y) ((x)<(y)?(y):(x))
#define min(y,x) ((x)<(y)?(x):(y))
#define MEM(a,b) memset(a,(b),sizeof(a))
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)//判断这个键是否按下
#define KEY_UP(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 0 : 1)//判断这个键是否弹起
#define KEY_EVERY(lpkeyState) GetKeyboardState(lpKeyState)//获得所有的256个键（键盘按键、鼠标按键等等）的状态，lpKeyState是指向一个256bit的数组，存放所有键的状态。
#define KEY_NOW(nVirtKey) GetKeyState(nVirtKey)//用于判断nVirtKey的状态。用返回值的最高位表示，最高位为1表示当前键处于down的状态；最高位为0当前键处于up状态。此函数从消息队列中读取消息进行处理。
#define setcolor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x)//设置颜色
#define getkey(x) GetAsyncKeyState(x)
#define GetWindow() GetForegroundWindow();//得到窗口信息
/*
鼠标左键 : MOUSE_MOVED 
鼠标右键 ：MOUSE_EVENT
鼠标滚轮 : MOUSE_WHEELED
MK_CONTROL当CTRL键按下时。
MK_LBUTTON当鼠标左键按下时。
MK_MBUTTON当鼠标中键按下时。
MK_RBUTTON当鼠标右键按下时.
MK_SHIFT当SHIFT按下时。
*/
using std::cin;
using std::cout;
using std::endl;
int brand();
void GOTO(int x,int y);
int brand(){return (rand()<<16)|(rand()<<1)|(rand()&1);}
void bsrand(){srand(GetTickCount());}
void cls(){system("cls");}
void retr(){//退出程序 
    HWND hWnd=GetForegroundWindow();
    ShowWindow(hWnd,SW_HIDE);
    exit(0);
}
void Window_Hide(HWND hWnd){ShowWindow(hWnd,0);}//隐藏窗口
void Window_Show(HWND hWnd){ShowWindow(hWnd,1);}//显示窗口
int getmouse_y(){//获取鼠标在屏幕中x的位置 
    POINT pt; 
    GetCursorPos(&pt);
    return pt.x;
}
int getmouse_x(){//获取鼠标在屏幕中y的位置 
    POINT pt; 
    GetCursorPos(&pt);
    return pt.y;
}
void setmouse(int y,int x){SetCursorPos(x,y);}//设置鼠标在屏幕中的位置 
void click_left(){//鼠标左键点击
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);  
    Sleep(5);//要留给某些应用的反应时间   
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); 
}
void click_right(){//鼠标右键点击
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);  
    Sleep(5);   
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);  
}
void GOTO(int x,int y){//将光标移动到屏幕中的位置
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.Y = x;
    csbiInfo.dwCursorPosition.X = y;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
/* 
附录1:(COLOR) 
<span style="white-space:pre">    </span>字
    1   深蓝色
    2   深绿色
    3   深青色
    4   深红色
    5   深粉色
    6   黄色
    7   深白色
    8   灰色
    9   浅蓝色
    10  浅绿色
    11  浅青色
    12  浅红色
    13  浅粉色
    14  浅黄色
    15  浅白色

    背景 
    1~15        黑色
    16~31       深蓝色
    32~47       深绿色
    48~63       深青色
    64~79       深红色
    80~95       深粉色
    96~111      深黄色
    112~127     深白色
    128~143     灰色
    144~159     浅蓝色
    160~175     浅绿色
    176~191     浅青色
    192~207     浅红色
    208~223     浅粉色
    224~239     浅黄色
    240~255     浅白色

附录2(KEY NUMBER) 
    VK_LBUTTON             鼠标左键                      0x01 
    VK_RBUTTON             鼠标右键                      0x02 
    VK_CANCEL              Ctrl + Break                  0x03 
    VK_MBUTTON             鼠标中键                      0x04 

    VK_BACK                Backspace 键                   0x08 
    VK_TAB                 Tab 键                        0x09 

    VK_RETURN              回车键                        0x0D 

    VK_SHIFT               Shift 键                      0x10 
    VK_CONTROL             Ctrl 键                       0x11 
    VK_MENU                Alt 键                         0x12 
    VK_PAUSE               Pause 键                      0x13 
    VK_CAPITAL             Caps Lock 键                  0x14 

    VK_ESCAPE              Esc 键                        0x1B 

    VK_SPACE               空格键                       0x20 
    VK_PRIOR               Page Up 键                    0x21 
    VK_NEXT                Page Down 键                  0x22 
    VK_END                 End 键                        0x23 
    VK_HOME                Home 键                       0x24 
    VK_LEFT                左箭头键                      0x25 
    VK_UP                  上箭头键                      0x26 
    VK_RIGHT               右箭头键                      0x27 
    VK_DOWN                下箭头键                      0x28 
    VK_SNAPSHOT            Print Screen 键               0x2C 
    VK_Insert              Insert 键                     0x2D 
    VK_Delete              Delete 键                     0x2E 

    '0' – '9'             数字 0 - 9                    0x30 - 0x39 
    'A' – 'Z'             字母 A - Z                    0x41 - 0x5A 

    VK_LWIN                左WinKey(104键盘才有)         0x5B 
    VK_RWIN                右WinKey(104键盘才有)         0x5C 
    VK_APPS                AppsKey(104键盘才有)          0x5D 

    VK_NUMPAD0            小键盘 0 键                    0x60 
    VK_NUMPAD1            小键盘 1 键                    0x61 
    VK_NUMPAD2            小键盘 2 键                    0x62 
    VK_NUMPAD3            小键盘 3 键                    0x63 
    VK_NUMPAD4            小键盘 4 键                    0x64 
    VK_NUMPAD5            小键盘 5 键                    0x65 
    VK_NUMPAD6            小键盘 6 键                    0x66 
    VK_NUMPAD7            小键盘 7 键                    0x67 
    VK_NUMPAD8            小键盘 8 键                    0x68 
    VK_NUMPAD9            小键盘 9 键                    0x69 

    VK_F1 - VK_F24        功能键F1 – F24                0x70 - 0x87 

    VK_NUMLOCK            Num Lock 键                    0x90 
    VK_SCROLL             Scroll Lock 键                 0x91 
*/
