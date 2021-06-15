#pragma once
#include<string>
using namespace std;

enum UnitType;

class CUnit
{
public:
	string m_Name;
	UnitType m_Unitype;

public:
	CUnit(string a_Name = "");
	~CUnit();

public:
	virtual void OnEnable(int _Num) = 0;
	virtual void OnUpdate(int _Num) = 0;
	virtual void OnDisable(int _Num) = 0;
};

