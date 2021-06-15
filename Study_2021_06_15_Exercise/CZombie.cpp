#include "CZombie.h"
#include "GlobalValue.h"
#include<iostream>
#include<windows.h>

CZombie::CZombie(string a_Name, int a_Speed, int a_Def) : CUnit(a_Name)
{
	m_Unitype = Zombie;
	m_Speed = a_Speed;
	m_Def = a_Def;
}

CZombie::~CZombie()
{
}

void CZombie::OnEnable(int _Num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	cout << g_str[_Num] << " : 좀비 등장 준비" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void CZombie::OnUpdate(int _Num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("이름(%s) 이속(%d) 방어력(%d)\n", g_str[_Num].c_str(), m_Speed, m_Def);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void CZombie::OnDisable(int _Num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << g_str[_Num] << " : 좀비 퇴장 준비" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
