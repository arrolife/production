#include "Player.h"
#include "StatusManager.h"
#include "PlayScene.h"
#include "../Library/GameObject.h"
#include "Enemy.h"

Player::Player()
{
	hImage[0] = LoadGraph("data/image/player/player_1.png");
	hImage[1] = LoadGraph("data/image/player/player_2.png");
	hImage[2] = LoadGraph("data/image/player/player_3.png");
	hImage[3] = LoadGraph("data/image/UI/shield_iron.png");
	hImage[4] = LoadGraph("data/image/UI/shield_blue.png");
}

Player::~Player()
{
}

void Player::Update()
{

	Enemy* enemy = FindGameObject<Enemy>();


	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:

		isDead = false;

		if (!isDead) {

			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !isClick && !isGuard)
			{
				AttackCount += 1;
				if (AttackCount >= 10) {
					AttackCount + 0;
					AttackMotion = true;
				}
				isClick = true;
			}
			//AttackCount += 1;
			if (AttackCount >= statusmanager.PAttackWaiting) {
				AttackCount = 0;
				statusmanager.Attack(1);
			}

			if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && !isClick) {
				
				if (enemy->JustGuardJudge && !isGuard) {
					Just = true;
				}
				isGuard = true;
			}
			if ((GetMouseInput() & MOUSE_INPUT_RIGHT) == 0) {
				isGuard = false;
				JustGuard = false;
				Just = false;
			}

		}
		if (GetMouseInput() == 0) {
			isClick = false;
		}


		if (isGuard && enemy->JustGuardJudge && Just) {
			
			JustGuard = true;
			//ダメージのフラグを書く
			//処理の終わり近くにダメージがどうなったかの処理を書く
		}


		if (statusmanager.Php <= 0 && !isDead) {
			isDead = true;
		}

		

		break;

	case GameState::result:
		
		AttackCount = 0;
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
			DrawExtendGraph(Px - PWidth, Py, Px, Py + PHeight, hImage[0], true);
		}

		if (isGuard) {
			DrawExtendGraph(0 + 690, 0 + 820, 100 + 690, 110 + 820, hImage[3], true);
		}
		if (isGuard && JustGuard) {
			DrawExtendGraph(0 + 690, 0 + 820, 100 + 690, 110 + 820, hImage[4], true);
		}

		break;

	case GameState::result:
		if (!isDead) {
			DrawExtendGraph(0, 0, 128, 128, hImage[0], true);
		}
		break;

	}

	
}
