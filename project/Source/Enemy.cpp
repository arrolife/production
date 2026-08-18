#include "Enemy.h"
#include "StatusManager.h"
#include "PlayScene.h"
#include "Player.h"


Enemy::Enemy()
{

	UIImage[0] = LoadGraph("data/image/UI/exclamation_black.png");
	UIImage[1] = LoadGraph("data/image/UI/exclamation_red.png");
	UIImage[2] = LoadGraph("data/image/UI/exclamation_blue.png");
	UIImage[3] = LoadGraph("data/image/UI/exclamation_purple.png");
	UIImage[4] = LoadGraph("data/image/UI/heart_red.png");

	hImage[0] = LoadGraph("data/image/enemy/slime_green.png");
	hImage[1] = LoadGraph("data/image/enemy/slime_red.png");
	hImage[2] = LoadGraph("data/image/enemy/slime_big_green.png");
	hImage[3] = LoadGraph("data/image/enemy/slime_big_red.png");
	hImage[4] = LoadGraph("data/image/enemy/slime_big_purple.png");

	hImage[5] = LoadGraph("data/image/enemy/mummy_yellow.png");
	hImage[6] = LoadGraph("data/image/enemy/zombie.png");
	hImage[7] = LoadGraph("data/image/enemy/skeleton.png");
	hImage[8] = LoadGraph("data/image/enemy/mummy_red.png");
	hImage[9] = LoadGraph("data/image/enemy/grimreaper.png");

	hImage[10] = LoadGraph("data/image/enemy/mushroom.png");
	hImage[11] = LoadGraph("data/image/enemy/frog.png");
	hImage[12] = LoadGraph("data/image/enemy/flower.png");
	hImage[13] = LoadGraph("data/image/enemy/treant.png");
	hImage[14] = LoadGraph("data/image/enemy/medusa.png");

	hImage[15] = LoadGraph("data/image/enemy/mimic.png");
	hImage[16] = LoadGraph("data/image/enemy/ghost.png");
	hImage[17] = LoadGraph("data/image/enemy/flame.png");
	hImage[18] = LoadGraph("data/image/enemy/golem.png");
	hImage[19] = LoadGraph("data/image/enemy/dragon.png");

	hImage[20] = LoadGraph("data/image/enemy/angel_silver.png");
	hImage[21] = LoadGraph("data/image/enemy/lamia.png");
	hImage[22] = LoadGraph("data/image/enemy/vampire.png");
	hImage[23] = LoadGraph("data/image/enemy/angel_black.png");
	hImage[24] = LoadGraph("data/image/enemy/demonking_01.png");

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
			int num = GetRand(statusmanager.AttackPattern[0] + statusmanager.AttackPattern[1] + statusmanager.AttackPattern[2] - 1);
			if (num <= statusmanager.AttackPattern[0] - 1) {
				AttackType = 0;
			}
			else if (num <= (statusmanager.AttackPattern[0] + statusmanager.AttackPattern[1] - 1)) {
				AttackType = 1;
			}
			else if (num <= (statusmanager.AttackPattern[0] + statusmanager.AttackPattern[1] + statusmanager.AttackPattern[2] - 1)) {
				AttackType = 2;
			}

			AttackWait = GetRand(statusmanager.EAttackWaitMax - statusmanager.EAttackWaitMin) + statusmanager.EAttackWaitMin;

			switch (AttackType) {
			case 0:
				AttackSpeed = statusmanager.AttackSpeed;
				break;
			case 1:
				AttackSpeed = statusmanager.AttackSpeed * 2;
				break;
			case 2:
				AttackSpeed = statusmanager.AttackSpeed / 2;
			}

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
		
		AttackSpeed = 0;
		TimeCount = 0;
		AttackWait = 0;
		RandomSelect = false;
		UIMotion = false;
		AttackMotion = false;
		Move = 0;
		UISizeChange = 0;
		isAttack = false;
		Back = false;
		AttackType = 0;
		
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
			//DrawBox(i * 32, 128, (i + 1) * 32, 128 + 32, GetColor(0, 0, 0), true);
			DrawExtendGraph(i * 32, 128, (i + 1) * 32, 128 + 32, UIImage[4], true);
		}

			//7:5 = 140:100
			//*20 (statusmanager.UISize01 / 2)

				

			DrawExtendGraph(statusmanager.Ex - Move, statusmanager.Ey, statusmanager.Ex + statusmanager.EWidth - Move, statusmanager.Ey + statusmanager.EHeight, hImage[statusmanager.ELevel - 1], true);
			
			if (UIMotion) {
				if (!AttackMotion) {
					if (UISizeChange < (statusmanager.UISize01 / 2)) {
						UISizeChange += AttackSpeed;
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
					UIImage[AttackType + 1], true);

			}

		break;

	case GameState::result:

		break;

	}

	
}