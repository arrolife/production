#include "Enemy.h"
#include "StatusManager.h"
#include "PlayScene.h"

Enemy::Enemy()
{

	UIImage[0] = LoadGraph("data/image/UI/exclamation_gray.png");
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

		if (!isDead) {
			AttackCount += 1;
			if (AttackCount >= statusmanager.EAttackWaiting) {
				AttackCount = 0;
				statusmanager.Attack(0);
				AttackMotion = true;
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

	DrawExtendGraph(0, 0, 100, 100, UIImage[0], true);


	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

		switch (statusmanager.ELevel) {
		case 1:
			//7:5 = 140:100
			//*20
				DrawExtendGraph(statusmanager.Ex, statusmanager.Ey, statusmanager.Ex + statusmanager.EWidth, statusmanager.Ey + statusmanager.EHeight, hImage[0], true);
			
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
