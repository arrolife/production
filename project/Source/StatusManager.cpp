#include "StatusManager.h"

int StatusManager::MaxPhp = 100;
int StatusManager::MaxEhp = 100;
int StatusManager::Php = 100;
int StatusManager::Ehp = 100;
int StatusManager::PAttack = 1;
int StatusManager::EAttack = 10;
float StatusManager::PAttackWaiting = 5.0f * 60.0f;
float StatusManager::EAttackWaiting = 5.0f * 60.0f;
int StatusManager::StatusPoint = 0;
int StatusManager::ELevel = 1;
int StatusManager::NextNeedPoint = 1;

int StatusManager::Ex = 0;
int StatusManager::Ey = 0;
int StatusManager::EWidth = 0;
int StatusManager::EHeight = 0;

StatusManager statusmanager;

void StatusManager::Attack(int AtackCharacter)
{
	switch (AtackCharacter) {	
	case 1:
		Ehp -= PAttack;
		break;
	case 0:
		Php -= EAttack;
		break;
	}
}

void StatusManager::AddStatusPoint(int AddPoint)
{
	StatusPoint += AddPoint;
}

void StatusManager::SetEnemyStatus(int Level)
{
	ELevel = Level;

	switch (ELevel) {

	case 1:

		MaxEhp = 100;
		EAttack = 10;
		EAttackWaiting = 5.0f * 60.0f;

		Ex = 1160;
		Ey = 830;
		EWidth = 140;
		EHeight = 100;

		break;

	case 2:

		MaxEhp = 1000;
		EAttack = 100;
		EAttackWaiting = 5.0f * 60.0f;
		break;

	case 3:

		MaxEhp = 1000;
		EAttack = 100;
		EAttackWaiting = 5.0f * 60.0f;
		break;

	case 4:

		MaxEhp = 10000;
		EAttack = 1000;
		EAttackWaiting = 5.0f * 60.0f;
		break;

	case 5:

		MaxEhp = 100000;
		EAttack = 10000;
		EAttackWaiting = 5.0f * 60.0f;
		break;

	}

	Ehp = MaxEhp;

}

void StatusManager::AddMaxPhp()
{
	StatusPoint -= NextNeedPoint;
	MaxPhp += 10;
	NextNeedPoint += 1;
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
