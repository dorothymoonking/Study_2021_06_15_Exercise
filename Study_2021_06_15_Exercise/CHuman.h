#pragma once
#include "CUnit.h"
#include<string>

class CHuman : public CUnit
{
public:
	int m_Hp;
	int m_IQ;

public:
	CHuman(string a_Name, int a_Hp, int a_IQ);
	~CHuman();

public:
	virtual void OnEnable(int _Num);
	virtual void OnUpdate(int _Num);
	virtual void OnDisable(int _Num);
};

