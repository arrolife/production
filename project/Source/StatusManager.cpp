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
int StatusManager::AttackPattern[3] = {1, 0, 0};

int StatusManager::Ex = 0; //いろいろ面倒なので全敵Ex固定
int StatusManager::Ey = 0;
int StatusManager::EWidth = 0;
int StatusManager::EHeight = 0;
float StatusManager::UIx01 = 0;
float StatusManager::UIy01 = 0;
float StatusManager::UISize01 = 300;
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
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 500.0f;
		
		
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
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 500.0f;

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
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 470.0f;
		
		
		break;

	case 4:

		MaxEhp = 13;
		AttackSpeed = 1.5f;
		EAttackWaitMin = 160;
		EAttackWaitMax = 270;

		Ex = 1160;
		Ey = 800;
		EWidth = 140;
		EHeight = 130;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 470.0f;
		
		break;

	case 5:

		MaxEhp = 15;
		AttackSpeed = 2.3f;
		EAttackWaitMin = 10;
		EAttackWaitMax = 180;

		Ex = 1160;
		Ey = 800;
		EWidth = 140;
		EHeight = 130;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 470.0f;
		
		break;

	case 6:

		MaxEhp = 20;
		AttackSpeed = 1.2f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 400;

		Ex = 1160;
		Ey = 750;
		EWidth = 140;
		EHeight = 180;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 7:

		MaxEhp = 22;
		AttackSpeed = 1.4f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 300;

		Ex = 1160;
		Ey = 750;
		EWidth = 140;
		EHeight = 180;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 8:

		MaxEhp = 22;
		AttackSpeed = 1.8f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 200;

		Ex = 1160;
		Ey = 720;
		EWidth = 170;
		EHeight = 210;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 9:

		MaxEhp = 25;
		AttackSpeed = 2.0f;
		EAttackWaitMin = 80;
		EAttackWaitMax = 170;

		Ex = 1160;
		Ey = 720;
		EWidth = 170;
		EHeight = 210;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 10:

		MaxEhp = 30;
		AttackSpeed = 2.5f;
		EAttackWaitMin = 5;
		EAttackWaitMax = 150;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 11:

		MaxEhp = 30;
		AttackSpeed = 2.5f;
		EAttackWaitMin = 5;
		EAttackWaitMax = 150;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
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
