#pragma once
#ifndef _INTERFACE_H_  
#define _INTERFACE_H_   
#include <iostream>  
#include <windows.h>  
using namespace std;

void gotoxy(int x, int y)//设置坐标   
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool setcolor(WORD wAttributes)//设置颜色   
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return false;
	bool bResult = SetConsoleTextAttribute(hConsole, wAttributes);
	return bResult;
}

void Front()//开始的界面   
{
	gotoxy(0, 5);
	setcolor(15);
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<****>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
	
	setcolor(0x0007);
	gotoxy(32, 10);
	cout << "学生管理系统";

	gotoxy(52, 13);
	setcolor(15);
	cout << "——BY 曹峰";

	gotoxy(0, 25);
	setcolor(15);
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>****<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	Sleep(3000);
	system("cls");
}

void Back()//结束的界面   
{
	system("cls");
	setcolor(15);
	gotoxy(20, 8);
	cout << "感谢你使用*学生管理系统*" << endl << endl;
	int i;
	for (i = 0; i < 10; i++) {
		gotoxy(20 + i, 9);
		cout << "欢迎你下次使用!!!";
		Sleep(200);
		if (i != 9) {
			gotoxy(20 + i, 9);
			putchar(' ');
		}
	}
	Sleep(3000);
	exit(0);
}

#endif  
