#pragma once

class StatusManager {

public:

	static void Attack(int AttackCharacter //Plyer = 1, Enemy = 0
	);
	static void AddStatusPoint(int AddPoint);
	static void SetEnemyStatus(int Level);
	static void AddMaxPhp();
	static void AddPAttack(); 
	static void SubtractPAttackWaiting();

	static int Php;
	static int MaxPhp;
	static float PAttackWaiting;
	static int PAttack;
	static int StatusPoint;
	static int NextNeedPoint;

	static int Ehp;
	static int MaxEhp;
	static float EAttackWaiting;
	static int EAttack;
	static int ELevel;

	static int Ex;
	static int Ey;
	static int EWidth;
	static int EHeight;

private:

	

};

extern StatusManager statusmanager;