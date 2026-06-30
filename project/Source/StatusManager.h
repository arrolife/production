#pragma once

class StatusManager {

public:

	static void Atack(int AtackCharacter //Plyer = 1, Enemy = 0
	);
	static void AddStatusPoint(int AddPoint);
	static void SetEnemyStatus(int Level);
	static void AddMaxPhp();
	static void AddPAtack(); 
	static void SubtractPAtackWaiting();

	static int Php;
	static int MaxPhp;
	static float PAtackWaiting;
	static int PAtack;
	static int StatusPoint;
	static int NextNeedPoint;

	static int Ehp;
	static int MaxEhp;
	static float EAtackWaiting;
	static int EAtack;
	static int ELevel;

	

private:

	

};

extern StatusManager statusmanager;