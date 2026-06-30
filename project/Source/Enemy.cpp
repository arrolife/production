#include "Enemy.h"
#include "StatusManager.h"
#include "PlayScene.h"

Enemy::Enemy()
{
	hImage[0] = LoadGraph("data/image/black.avif");
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
			AtackCount += 1;
			if (AtackCount >= statusmanager.EAtackWaiting) {
				AtackCount = 0;
				statusmanager.Atack(0);
			}
		}

		if (statusmanager.Ehp <= 0 && !isDead) {
			isDead = true;
		}

		break;

	case GameState::result:

		AtackCount = 0;
		break;

	}



}

void Enemy::Draw()
{

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:
		if (!isDead) {
			DrawExtendGraph(128, 0, 256, 128, hImage[0], true);
		}
		break;

	case GameState::result:
		if (!isDead) {
			DrawExtendGraph(128, 0, 256, 128, hImage[0], true);
		}
		break;

	}

	
}
