#pragma once

class StatusManager {

public:

	static void AddStatusPoint(int AddPoint);
	static void SetEnemyStatus(int Level);
	static void AddPAttack(); 
	static void SubtractPAttackWaiting();

	static float PAttackWaiting;
	static int PAttack;
	static int StatusPoint;
	static int NextNeedPoint;

	static int Ehp;
	static int MaxEhp;
	static int EAttackWaitMin;
	static int EAttackWaitMax;
	//static int EAttack;
	static int ELevel;

	static int Ex;
	static int Ey;
	static int EWidth;
	static int EHeight;
	static float UIx01;
	static float UIy01;
	static float UISize01;
	static float AttackSpeed;

private:

	

};

extern StatusManager statusmanager;