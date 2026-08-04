#include "Enemy.h"
#include "StatusManager.h"
#include "PlayScene.h"
#include "Player.h"

Enemy::Enemy()
{

	UIImage[0] = LoadGraph("data/image/UI/exclamation_black.png");
	UIImage[1] = LoadGraph("data/image/UI/exclamation_red.png");
	UIImage[2] = LoadGraph("data/image/UI/exclamation_blue.png");

	hImage[0] = LoadGraph("data/image/enemy/slime_green.png");
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

		isDead = false;

		if (!RandomSelect) {
			TimeCount = 0;
			AttackWait = GetRand(statusmanager.EAttackWaitMax - statusmanager.EAttackWaitMin) + statusmanager.EAttackWaitMin;
			RandomSelect = true;
		}
		else {
			TimeCount += 1;
			if (TimeCount >= AttackWait) {
				UIMotion = true;
			}
		}


		if (statusmanager.Ehp <= 0 && !isDead) {
			isDead = true;
		}

		break;

	case GameState::result:

		isAttack = false;
		AttackMotion = false;

		AttackCount = 0;
		break;

	}



}

void Enemy::Draw()
{
	//DrawExtendGraph(0, 0, 100, 100, UIImage[0], true);


	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

		switch (statusmanager.ELevel) {
		case 1:
			//7:5 = 140:100
			//*20 (statusmanager.UISize01 / 2)

				

				DrawExtendGraph(statusmanager.Ex - Move, statusmanager.Ey, statusmanager.Ex + statusmanager.EWidth - Move, statusmanager.Ey + statusmanager.EHeight, hImage[0], true);

				if (UIMotion) {
					if (!AttackMotion) {
						if (UISizeChange < (statusmanager.UISize01 / 2)) {
							UISizeChange += statusmanager.AttackSpeed;
						}
						else if (UISizeChange >= (statusmanager.UISize01 / 2)) {
							UISizeChange = statusmanager.UISize01 / 2;
							AttackMotion = true;
						}
					}

					if (statusmanager.Ex - Move >= 760 && AttackMotion && !Back) {
						Move += MotionSpeed;
						JustGuardJudge = true;
					}
					else if (AttackMotion){

						if (!isAttack) {
							isAttack = true;
							JustGuardJudge = false;
						}

						Move -= MotionSpeed;
						Back = true;
						if (Move < 0) {
							isAttack = false;
							AttackMotion = false;
							UIMotion = false;
							RandomSelect = false;
							Back = false;
							UISizeChange = 0;
							Move = 0;
						}
					}

					DrawExtendGraph(statusmanager.UIx01, statusmanager.UIy01, statusmanager.UIx01 + statusmanager.UISize01, statusmanager.UIy01 + statusmanager.UISize01, UIImage[0], true);

					DrawExtendGraph(statusmanager.UIx01 + (statusmanager.UISize01 / 2) - UISizeChange,
						statusmanager.UIy01 + (statusmanager.UISize01 / 2) - UISizeChange,
						statusmanager.UIx01 + statusmanager.UISize01 - (statusmanager.UISize01 / 2) + UISizeChange,
						statusmanager.UIy01 + statusmanager.UISize01 - (statusmanager.UISize01 / 2) + UISizeChange,
						UIImage[1], true);

				}

				
					

			break;

		case 2:
			DrawExtendGraph(128, 0, 256, 128, hImage[2], true);
			break;

		case 3:
			DrawExtendGraph(128, 0, 256, 128, hImage[4], true);
			break;

		case 4:
			DrawExtendGraph(128, 0, 256, 128, hImage[7], true);
			break;

		case 5:
			DrawExtendGraph(128, 0, 256, 128, hImage[9], true);
			break;
		}

		break;

	case GameState::result:

		switch (statusmanager.ELevel) {

		case 1:
			break;












		}

		if (!isDead) {
			DrawExtendGraph(128, 0, 256, 128, hImage[0], true);
		}
		break;

	}

	
}