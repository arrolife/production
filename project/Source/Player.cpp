#include "Player.h"
#include "StatusManager.h"
#include "PlayScene.h"

Player::Player()
{
	hImage[0] = LoadGraph("data/image/black.avif");
}

Player::~Player()
{
}

void Player::Update()
{

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

		isDead = false;

		if (!isDead) {

			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !isClick)
			{
				AttackCount += 10;
				isClick = true;
			}
			AttackCount += 1;
			if (AttackCount >= statusmanager.PAttackWaiting) {
				AttackCount = 0;
				statusmanager.Attack(1);
			}
		}
		if (statusmanager.Php <= 0 && !isDead) {
			isDead = true;
		}
		break;

	case GameState::result:
		
		AttackCount = 0;
		break;

	}

	if (GetMouseInput() == 0) {
		isClick = false;
	}

}

void Player::Draw()
{

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:
		if (!isDead) {
			DrawExtendGraph(0, 0, 128, 128, hImage[0], true);
		}
		break;

	case GameState::result:
		if (!isDead) {
			DrawExtendGraph(0, 0, 128, 128, hImage[0], true);
		}
		break;

	}

	
}
