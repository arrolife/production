#include "Player.h"
#include "StatusManager.h"
#include "PlayScene.h"
#include "KeyUtility.h"
#include "MouseUtility.h"

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

			if (MouseUtility::CheckTrigger(MOUSE_INPUT_LEFT))
			{
				AtackCount += 10;
			}
			AtackCount += 1;
			if (AtackCount >= statusmanager.PAtackWaiting) {
				AtackCount = 0;
				statusmanager.Atack(1);
			}
		}
		if (statusmanager.Php <= 0 && !isDead) {
			isDead = true;
		}
		break;

	case GameState::result:
		
		AtackCount = 0;
		break;

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
