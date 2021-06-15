#pragma once
#include "CUnit.h"
#include<string>

class CZombie : public CUnit
{
public:
	int m_Speed;
	int m_Def;

public:
	CZombie(string a_Name, int a_Speed, int a_Def);
	~CZombie();

public:
	virtual void OnEnable(int _Num);
	virtual void OnUpdate(int _Num);
	virtual void OnDisable(int _Num);
};

