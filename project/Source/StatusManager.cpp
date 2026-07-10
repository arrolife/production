#include "StatusManager.h"

int StatusManager::MaxPhp = 100;
int StatusManager::MaxEhp = 100;
int StatusManager::Php = 100;
int StatusManager::Ehp = 100;
int StatusManager::PAtack = 100;
int StatusManager::EAtack = 10;
float StatusManager::PAtackWaiting = 5.0f * 60.0f;
float StatusManager::EAtackWaiting = 5.0f * 60.0f;
int StatusManager::StatusPoint = 0;
int StatusManager::ELevel = 1;
int StatusManager::NextNeedPoint = 1;

StatusManager statusmanager;

void StatusManager::Atack(int AtackCharacter)
{
	switch (AtackCharacter) {	
	case 1:
		Ehp -= PAtack;
		break;
	case 0:
		Php -= EAtack;
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
		EAtack = 10;
		EAtackWaiting = 5.0f * 60.0f;
		break;

	case 2:

		MaxEhp = 1000;
		EAtack = 100;
		EAtackWaiting = 5.0f * 60.0f;
		break;

	case 3:

		MaxEhp = 1000;
		EAtack = 100;
		EAtackWaiting = 5.0f * 60.0f;
		break;

	case 4:

		MaxEhp = 10000;
		EAtack = 1000;
		EAtackWaiting = 5.0f * 60.0f;
		break;

	case 5:

		MaxEhp = 100000;
		EAtack = 10000;
		EAtackWaiting = 5.0f * 60.0f;
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

void StatusManager::AddPAtack()
{
	StatusPoint -= NextNeedPoint;
	PAtack += 10;
	NextNeedPoint += 1;
}

void StatusManager::SubtractPAtackWaiting()
{
	StatusPoint -= NextNeedPoint;
	PAtackWaiting -= 5.0f;
	NextNeedPoint += 1;
}
