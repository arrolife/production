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
		AttackPattern[0] = 1;
		AttackPattern[1] = 0;
		AttackPattern[2] = 0;


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
		AttackPattern[0] = 1;
		AttackPattern[1] = 0;
		AttackPattern[2] = 0;

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
		AttackPattern[0] = 1;
		AttackPattern[1] = 0;
		AttackPattern[2] = 0;

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
		AttackPattern[0] = 1;
		AttackPattern[1] = 0;
		AttackPattern[2] = 0;

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
		AttackPattern[0] = 4;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 800;
		EWidth = 140;
		EHeight = 130;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 470.0f;
		
		break;

	case 6:

		MaxEhp = 15;
		AttackSpeed = 1.2f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 400;
		AttackPattern[0] = 15;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 750;
		EWidth = 140;
		EHeight = 180;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 7:

		MaxEhp = 17;
		AttackSpeed = 1.4f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 300;
		AttackPattern[0] = 14;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 750;
		EWidth = 140;
		EHeight = 180;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 8:

		MaxEhp = 17;
		AttackSpeed = 1.8f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 200;
		AttackPattern[0] = 13;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 720;
		EWidth = 170;
		EHeight = 210;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f;
		
		break;

	case 9:

		MaxEhp = 20;
		AttackSpeed = 2.0f;
		EAttackWaitMin = 80;
		EAttackWaitMax = 170;
		AttackPattern[0] = 12;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

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
		AttackPattern[0] = 7;
		AttackPattern[1] = 3;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 11:

		MaxEhp = 25;
		AttackSpeed = 1.6f;
		EAttackWaitMin = 90;
		EAttackWaitMax = 350;
		AttackPattern[0] = 9;  //割合的な感じ　判定数9  0～8なら
		AttackPattern[1] = 1;  //              判定数1  9なら
		AttackPattern[2] = 0;  //              判定数0  なし

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 12:

		MaxEhp = 27;
		AttackSpeed = 1.8f;
		EAttackWaitMin = 70;
		EAttackWaitMax = 300;
		AttackPattern[0] = 17;
		AttackPattern[1] = 3;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 13:

		MaxEhp = 35;
		AttackSpeed = 2.1f;
		EAttackWaitMin = 60;
		EAttackWaitMax = 250;
		AttackPattern[0] = 4;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 14:

		MaxEhp = 30;
		AttackSpeed = 2.3f;
		EAttackWaitMin = 50;
		EAttackWaitMax = 220;
		AttackPattern[0] = 3;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 15:

		MaxEhp = 25;
		AttackSpeed = 2.7f;
		EAttackWaitMin = 5;
		EAttackWaitMax = 100;
		AttackPattern[0] = 6;
		AttackPattern[1] = 3;
		AttackPattern[2] = 1;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 16:

		MaxEhp = 20;
		AttackSpeed = 1.8f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 250;
		AttackPattern[0] = 6;
		AttackPattern[1] = 2;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 720  - 50;
		EWidth = 210;
		EHeight = 210 + 50;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 420.0f - 50;
		
		break;

	case 17:

		MaxEhp = 25;
		AttackSpeed = 2.0f;
		EAttackWaitMin = 80;
		EAttackWaitMax = 200;
		AttackPattern[0] = 3;
		AttackPattern[1] = 1;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 650;
		EWidth = 240;
		EHeight = 260;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 350.0f;
		
		break;

	case 18:

		MaxEhp = 30;
		AttackSpeed = 2.0f;
		EAttackWaitMin = 100;
		EAttackWaitMax = 300;
		AttackPattern[0] = 7;
		AttackPattern[1] = 3;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 650;
		EWidth = 240;
		EHeight = 260;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 350.0f;
		
		break;

	case 19:

		MaxEhp = 40;
		AttackSpeed = 1.5f;
		EAttackWaitMin = 50;
		EAttackWaitMax = 300;
		AttackPattern[0] = 7;
		AttackPattern[1] = 3;
		AttackPattern[2] = 0;

		Ex = 1160;
		Ey = 670;
		EWidth = 240;
		EHeight = 260;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 370.0f;
		
		break;

	case 20:

		MaxEhp = 35;
		AttackSpeed = 2.8f;
		EAttackWaitMin = 5;
		EAttackWaitMax = 250;
		AttackPattern[0] = 3;
		AttackPattern[1] = 2;
		AttackPattern[2] = 1;

		Ex = 1160;
		Ey = 630;
		EWidth = 450;
		EHeight = 260;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 330.0f;
		
		break;

	case 21:

		MaxEhp = 40;
		AttackSpeed = 2.3f;
		EAttackWaitMin = 50;
		EAttackWaitMax = 180;
		AttackPattern[0] = 1;
		AttackPattern[1] = 2;
		AttackPattern[2] = 1;

		Ex = 1160;
		Ey = 630;
		EWidth = 450;
		EHeight = 260;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 330.0f;
		
		break;

	case 22:

		MaxEhp = 35;
		AttackSpeed = 2.4f;
		EAttackWaitMin = 40;
		EAttackWaitMax = 130;
		AttackPattern[0] = 1;
		AttackPattern[1] = 3;
		AttackPattern[2] = 2;

		Ex = 1160;
		Ey = 650;
		EWidth = 250;
		EHeight = 280;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 350.0f;
		
		break;

	case 23:

		MaxEhp = 40;
		AttackSpeed = 2.5f;
		EAttackWaitMin = 30;
		EAttackWaitMax = 110;
		AttackPattern[0] = 1;
		AttackPattern[1] = 1;
		AttackPattern[2] = 2;

		Ex = 1160;
		Ey = 650;
		EWidth = 250;
		EHeight = 280;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 350.0f;
		
		break;

	case 24:

		MaxEhp = 40;
		AttackSpeed = 2.6f;
		EAttackWaitMin = 20;
		EAttackWaitMax = 150;
		AttackPattern[0] = 5;
		AttackPattern[1] = 4;
		AttackPattern[2] = 1;

		Ex = 1160;
		Ey = 630;
		EWidth = 450;
		EHeight = 260;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 330.0f;

		break;

	case 25:

		MaxEhp = 50;
		AttackSpeed = 3.0f;
		EAttackWaitMin = 10;
		EAttackWaitMax = 130;
		AttackPattern[0] = 4;
		AttackPattern[1] = 3;
		AttackPattern[2] = 2;

		Ex = 1160;
		Ey = 530;
		EWidth = 400;
		EHeight = 400;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 220.0f;

		break;

	case 26:

		MaxEhp = 60;
		AttackSpeed = 4.0f;
		EAttackWaitMin = 1;
		EAttackWaitMax = 90;
		AttackPattern[0] = 1;
		AttackPattern[1] = 1;
		AttackPattern[2] = 1;

		Ex = 1160;
		Ey = 300;
		EWidth = 600;
		EHeight = 630;
		UIx01 = Ex - ((UISize01 - EWidth) / 2); // Ex - ((UISize - EWidth) / 2)
		UIy01 = 70.0f;

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
