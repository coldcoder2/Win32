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
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)//�ж�������Ƿ���
#define KEY_UP(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 0 : 1)//�ж�������Ƿ���
#define KEY_EVERY(lpkeyState) GetKeyboardState(lpKeyState)//������е�256���������̰�������갴���ȵȣ���״̬��lpKeyState��ָ��һ��256bit�����飬������м���״̬��
#define KEY_NOW(nVirtKey) GetKeyState(nVirtKey)//�����ж�nVirtKey��״̬���÷���ֵ�����λ��ʾ�����λΪ1��ʾ��ǰ������down��״̬�����λΪ0��ǰ������up״̬���˺�������Ϣ�����ж�ȡ��Ϣ���д���
#define setcolor(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x)//������ɫ
#define getkey(x) GetAsyncKeyState(x)
#define GetWindow() GetForegroundWindow();//�õ�������Ϣ
/*
������ : MOUSE_MOVED 
����Ҽ� ��MOUSE_EVENT
������ : MOUSE_WHEELED
MK_CONTROL��CTRL������ʱ��
MK_LBUTTON������������ʱ��
MK_MBUTTON������м�����ʱ��
MK_RBUTTON������Ҽ�����ʱ.
MK_SHIFT��SHIFT����ʱ��
*/
using std::cin;
using std::cout;
using std::endl;
int brand();
void GOTO(int x,int y);
int brand(){return (rand()<<16)|(rand()<<1)|(rand()&1);}
void bsrand(){srand(GetTickCount());}
void cls(){system("cls");}
void retr(){//�˳����� 
    HWND hWnd=GetForegroundWindow();
    ShowWindow(hWnd,SW_HIDE);
    exit(0);
}
void Window_Hide(HWND hWnd){ShowWindow(hWnd,0);}//���ش���
void Window_Show(HWND hWnd){ShowWindow(hWnd,1);}//��ʾ����
int getmouse_y(){//��ȡ�������Ļ��x��λ�� 
    POINT pt; 
    GetCursorPos(&pt);
    return pt.x;
}
int getmouse_x(){//��ȡ�������Ļ��y��λ�� 
    POINT pt; 
    GetCursorPos(&pt);
    return pt.y;
}
void setmouse(int y,int x){SetCursorPos(x,y);}//�����������Ļ�е�λ�� 
void click_left(){//���������
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);  
    Sleep(5);//Ҫ����ĳЩӦ�õķ�Ӧʱ��   
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); 
}
void click_right(){//����Ҽ����
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);  
    Sleep(5);   
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);  
}
void GOTO(int x,int y){//������ƶ�����Ļ�е�λ��
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.Y = x;
    csbiInfo.dwCursorPosition.X = y;
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
/* 
��¼1:(COLOR) 
<span style="white-space:pre">    </span>��
    1   ����ɫ
    2   ����ɫ
    3   ����ɫ
    4   ���ɫ
    5   ���ɫ
    6   ��ɫ
    7   ���ɫ
    8   ��ɫ
    9   ǳ��ɫ
    10  ǳ��ɫ
    11  ǳ��ɫ
    12  ǳ��ɫ
    13  ǳ��ɫ
    14  ǳ��ɫ
    15  ǳ��ɫ

    ���� 
    1~15        ��ɫ
    16~31       ����ɫ
    32~47       ����ɫ
    48~63       ����ɫ
    64~79       ���ɫ
    80~95       ���ɫ
    96~111      ���ɫ
    112~127     ���ɫ
    128~143     ��ɫ
    144~159     ǳ��ɫ
    160~175     ǳ��ɫ
    176~191     ǳ��ɫ
    192~207     ǳ��ɫ
    208~223     ǳ��ɫ
    224~239     ǳ��ɫ
    240~255     ǳ��ɫ

��¼2(KEY NUMBER) 
    VK_LBUTTON             ������                      0x01 
    VK_RBUTTON             ����Ҽ�                      0x02 
    VK_CANCEL              Ctrl + Break                  0x03 
    VK_MBUTTON             ����м�                      0x04 

    VK_BACK                Backspace ��                   0x08 
    VK_TAB                 Tab ��                        0x09 

    VK_RETURN              �س���                        0x0D 

    VK_SHIFT               Shift ��                      0x10 
    VK_CONTROL             Ctrl ��                       0x11 
    VK_MENU                Alt ��                         0x12 
    VK_PAUSE               Pause ��                      0x13 
    VK_CAPITAL             Caps Lock ��                  0x14 

    VK_ESCAPE              Esc ��                        0x1B 

    VK_SPACE               �ո��                       0x20 
    VK_PRIOR               Page Up ��                    0x21 
    VK_NEXT                Page Down ��                  0x22 
    VK_END                 End ��                        0x23 
    VK_HOME                Home ��                       0x24 
    VK_LEFT                ���ͷ��                      0x25 
    VK_UP                  �ϼ�ͷ��                      0x26 
    VK_RIGHT               �Ҽ�ͷ��                      0x27 
    VK_DOWN                �¼�ͷ��                      0x28 
    VK_SNAPSHOT            Print Screen ��               0x2C 
    VK_Insert              Insert ��                     0x2D 
    VK_Delete              Delete ��                     0x2E 

    '0' �C '9'             ���� 0 - 9                    0x30 - 0x39 
    'A' �C 'Z'             ��ĸ A - Z                    0x41 - 0x5A 

    VK_LWIN                ��WinKey(104���̲���)         0x5B 
    VK_RWIN                ��WinKey(104���̲���)         0x5C 
    VK_APPS                AppsKey(104���̲���)          0x5D 

    VK_NUMPAD0            С���� 0 ��                    0x60 
    VK_NUMPAD1            С���� 1 ��                    0x61 
    VK_NUMPAD2            С���� 2 ��                    0x62 
    VK_NUMPAD3            С���� 3 ��                    0x63 
    VK_NUMPAD4            С���� 4 ��                    0x64 
    VK_NUMPAD5            С���� 5 ��                    0x65 
    VK_NUMPAD6            С���� 6 ��                    0x66 
    VK_NUMPAD7            С���� 7 ��                    0x67 
    VK_NUMPAD8            С���� 8 ��                    0x68 
    VK_NUMPAD9            С���� 9 ��                    0x69 

    VK_F1 - VK_F24        ���ܼ�F1 �C F24                0x70 - 0x87 

    VK_NUMLOCK            Num Lock ��                    0x90 
    VK_SCROLL             Scroll Lock ��                 0x91 
*/
