#include<stdio.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include <conio.h>
#include<random>
#include"CUnit.h"
#include"CHuman.h"
#include"CZombie.h"
#include "GlobalValue.h"

using namespace std;
#pragma warning(disable:4996)
void main()
{
	srand((unsigned)time(NULL));
	vector<CUnit*> m_List;
	m_List.reserve(Count);

	CHuman* a_HmNode[3];
	CZombie* a_ZbNode[3];

	for (int ii = 0; ii < 4; ii++)
	{
		int Ran = rand() % 50 + 20;
		a_HmNode[ii] = new CHuman("사람", 100, Ran);
		m_List.push_back(a_HmNode[ii]);
	}

	for (int ii = 0; ii < 3; ii++)
	{
		int RanSpeed = rand() % 10 + 5;
		int RanDef = rand() % 50 + 20;
		a_ZbNode[ii] = new CZombie("좀비", RanSpeed, RanDef);
		m_List.push_back(a_ZbNode[ii]);
	}

	CUnit* a_ChrSoket;
	UnitType m_Type = Human;
	bool Time = false;
	while (true)
	{
		if (kbhit() && getch() == 27) //업데이트를 중지 시키기 위해 esc 키 누른 상태
		{
			break; //게임 플레임 루프 탈출
		}

		if (Time == false)
			cout << "낮 시간 입니다." << endl;
		else
			cout << "<밤 시간 입니다.>" << endl;

		for (int ii = 0; ii < m_List.size(); ii++)
		{
			a_ChrSoket = m_List[ii];

			if (a_ChrSoket->m_Unitype == m_Type)
			{
				a_ChrSoket->OnEnable(ii);
			}
		}

		for (int ii = 0; ii < m_List.size(); ii++)
		{
			a_ChrSoket = m_List[ii];
			if (a_ChrSoket->m_Unitype == m_Type)
			{
				a_ChrSoket->OnUpdate(ii);
			}
		}

		cout << "Enter Key를 누르면 계속...";
		cin.get();
		system("cls");

		for (int ii = 0; ii < m_List.size(); ii++)
		{
			a_ChrSoket = m_List[ii];
			if (a_ChrSoket->m_Unitype == m_Type)
			{
				a_ChrSoket->OnDisable(ii);
			}
		}

		if (m_Type == Human)
			m_Type = Zombie;
		else if (m_Type == Zombie)
			m_Type = Human;
		Time = !Time;
	}

	for (int ii = 0; ii < m_List.size(); ii++)
	{
		if (m_List[ii] != NULL)
		{
			delete m_List[ii];
			m_List[ii] = NULL;
		}
	}

	m_List.clear();
}