#include "StatusManager.h"

int StatusManager::MaxEhp = 5;
int StatusManager::Ehp = 5;
int StatusManager::PAttack = 1;
//int StatusManager::EAttack = 10;
float StatusManager::PAttackWaiting = 5.0f * 60.0f;
int StatusManager::EAttackWaitMin = 0;
int StatusManager::EAttackWaitMax = 0;
int StatusManager::StatusPoint = 0;
int StatusManager::ELevel = 1;
int StatusManager::NextNeedPoint = 1;

int StatusManager::Ex = 0; //いろいろ面倒なので全敵Ex固定
int StatusManager::Ey = 0;
int StatusManager::EWidth = 0;
int StatusManager::EHeight = 0;
float StatusManager::UIx01 = 0;
float StatusManager::UIy01 = 0;
float StatusManager::UISize01 = 0;
float StatusManager::AttackSpeed = 0;

StatusManager statusmanager;

void StatusManager::AddStatusPoint(int AddPoint)
{
	StatusPoint += AddPoint;
}

void StatusManager::SetEnemyStatus(int Level)
{
	ELevel = Level;

	switch (ELevel) {

	case 1:

		MaxEhp = 5;
		AttackSpeed = 1.0f;
		EAttackWaitMin = 180;
		EAttackWaitMax = 300;

		Ex = 1160;
		Ey = 830;
		EWidth = 140;
		EHeight = 100;
		UIx01 = 1080.0f; // Ex - ((UISize - EWidth) / 2)
		UIy01 = 500.0f;
		UISize01 = 300.0f;
		
		break;

	case 2:

		MaxEhp = 7;
		AttackSpeed = 1.2f;
		EAttackWaitMin = 175;
		EAttackWaitMax = 280;

		Ex = 1160;
		Ey = 830;
		EWidth = 140;
		EHeight = 100;
		UIx01 = 1080.0f; // Ex - ((UISize - EWidth) / 2)
		UIy01 = 500.0f;
		UISize01 = 300.0f;

		break;

	case 3:

		MaxEhp = 10;
		AttackSpeed = 1.2f;
		EAttackWaitMin = 175;
		EAttackWaitMax = 280;

		Ex = 1160;
		Ey = 800;
		EWidth = 140;
		EHeight = 130;
		UIx01 = 1080.0f; // Ex - ((UISize - EWidth) / 2)
		UIy01 = 470.0f;
		UISize01 = 300.0f;
		
		break;

	case 4:

		MaxEhp = 10;
		AttackSpeed = 1.5f;
		EAttackWaitMin = 160;
		EAttackWaitMax = 270;

		Ex = 1160;
		Ey = 800;
		EWidth = 140;
		EHeight = 130;
		UIx01 = 1080.0f; // Ex - ((UISize - EWidth) / 2)
		UIy01 = 470.0f;
		UISize01 = 300.0f;
		
		break;

	case 5:

		MaxEhp = 100000;
		//EAttack = 10000;
		
		break;

	}

	Ehp = MaxEhp;

}

void StatusManager::AddPAttack()
{
	StatusPoint -= NextNeedPoint;
	PAttack += 10;
	NextNeedPoint += 1;
}

void StatusManager::SubtractPAttackWaiting()
{
	StatusPoint -= NextNeedPoint;
	PAttackWaiting -= 5.0f;
	NextNeedPoint += 1;
}
