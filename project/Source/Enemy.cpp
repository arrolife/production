#include "Enemy.h"
#include "StatusManager.h"
#include "PlayScene.h"

Enemy::Enemy()
{
	hImage[0] = LoadGraph("data/image/slime.png");
	hImage[1] = LoadGraph("data/image/slime_02.png");
	hImage[2] = LoadGraph("data/image/ghost.png");
	hImage[3] = LoadGraph("data/image/ghost_02.png");
	hImage[4] = LoadGraph("data/image/treant.png");
	hImage[5] = LoadGraph("data/image/treant_02.png");
	hImage[6] = LoadGraph("data/image/treant_03.png");
	hImage[7] = LoadGraph("data/image/dragon.png");
	hImage[8] = LoadGraph("data/image/dragon_02.png");
	hImage[9] = LoadGraph("data/image/demonking.png");
	hImage[10] = LoadGraph("data/image/demonking_02.png");
	hImage[11] = LoadGraph("data/image/demonking_03.png");
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

		if (!isDead) {
			AttackCount += 1;
			if (AttackCount >= statusmanager.EAttackWaiting) {
				AttackCount = 0;
				statusmanager.Attack(0);
				isAttack = true;
			}
		}

		if (statusmanager.Ehp <= 0 && !isDead) {
			isDead = true;
		}

		break;

	case GameState::result:

		isAttack = false;

		AttackCount = 0;
		break;

	}



}

void Enemy::Draw()
{

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

		switch (statusmanager.ELevel) {
		case 1:

			//7:5 = 161:115

			//*23

			if (!isAttack) {
				DrawExtendGraph(960 + 200, 780, 960 + 161 + 200, 780 + 115, hImage[0], true);
			}
			else {
				DrawExtendGraph(960 + 200, 780, 960 + 161 + 200, 780 + 115, hImage[1], true);
				DirectionCount += 1.0f;
				if (DirectionCount >= statusmanager.EAttackWaiting / 3.0f) {
					isAttack = false;
					DirectionCount = 0;
				}
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














		}

		if (!isDead) {
			DrawExtendGraph(128, 0, 256, 128, hImage[0], true);
		}
		break;

	}

	
}
