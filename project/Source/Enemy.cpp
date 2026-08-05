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
	hImage[1] = LoadGraph("data/image/enemy/slime_red.png");
	hImage[2] = LoadGraph("data/image/enemy/slime_big_green.png");
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{

	Player* player = FindGameObject<Player>();

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

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

		if (player->isAttack) {

			statusmanager.Ehp -= 1;

		}

		break;

	case GameState::result:
		
		TimeCount = 0;
		AttackWait = 0;
		RandomSelect = false;
		UIMotion = false;
		AttackMotion = false;
		Move = 0;
		UISizeChange = 0;
		isAttack = false;
		Back = false;
		
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

		for (int i = 0; i < statusmanager.Ehp; i++) {
			DrawBox(i * 32, 128, (i + 1) * 32, 128 + 32, GetColor(0, 0, 0), true);
		}

		switch (statusmanager.ELevel) {
		case 1:
		case 2:
		case 3:
			//7:5 = 140:100
			//*20 (statusmanager.UISize01 / 2)

				

			DrawExtendGraph(statusmanager.Ex - Move, statusmanager.Ey, statusmanager.Ex + statusmanager.EWidth - Move, statusmanager.Ey + statusmanager.EHeight, hImage[statusmanager.ELevel - 1], true);
			
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
				}
				else if (AttackMotion) {

					isAttack = false;

					if (!isAttack && !Back) {
						isAttack = true;
					}

					Move -= MotionSpeed;
					Back = true;
					if (Move < 0) {
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

		
		default:
			
			break;
		}

		break;

	case GameState::result:

		break;

	}

	
}