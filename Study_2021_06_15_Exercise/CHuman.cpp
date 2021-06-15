#include "CHuman.h"
#include "GlobalValue.h"
#include<iostream>
#include<windows.h>

CHuman::CHuman(string a_Name, int a_Hp, int a_IQ) : CUnit(a_Name)
{
	m_Unitype = Human;
	m_Hp = a_Hp;
	m_IQ = a_IQ;
}

CHuman::~CHuman()
{

}

void CHuman::OnEnable(int _Num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << g_str[_Num] << " : 사람 등장 준비" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void CHuman::OnUpdate(int _Num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	printf("이름(%s) HP(%d) IQ(%d)\n", g_str[_Num].c_str(), m_Hp, m_IQ);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void CHuman::OnDisable(int _Num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << g_str[_Num] << " : 사람 퇴장 준비" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
