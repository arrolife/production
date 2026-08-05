#include "Player.h"
#include "StatusManager.h"
#include "PlayScene.h"
#include "../Library/GameObject.h"
#include "Enemy.h"
#include <math.h>

Player::Player()
{
	hImage[0] = LoadGraph("data/image/player/player_1.png");
	hImage[1] = LoadGraph("data/image/player/player_2.png");
	hImage[2] = LoadGraph("data/image/player/player_3.png");
}

Player::~Player()
{
}

void Player::Update()
{

	angleRad = angleDeg * DX_PI_F / 180.0;

	Enemy* enemy = FindGameObject<Enemy>();


	switch (gamestate) {

	case GameState::home:

		Php = MaxPhp;

		break;

	case GameState::battle:
		
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !isClick && !AttackMotion && !DodgedMotion)
		{
			AttackCount += 1;
			if (AttackCount >= 10) {
				AttackCount = 0;
				AttackMotion = true;
			}
			isClick = true;
		}

		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && !isClick && !AttackMotion && !DodgedMotion && !CoolTime) {
			DodgedMotion = true;
			isClick = true;
		}

	    if (GetMouseInput() == 0) {
		    isClick = false;
	    }


		if (DodgedMotion) {
			angleDeg += 25.0;
		}

		if (angleDeg >= 360) {
			angleDeg = 0;
			DodgedMotion = false;
			CoolTime = true;
		}

		if (CoolTime) {
			CoolCount -= 1;

			if (CoolCount <= 0) {
				CoolTime = false;
				CoolCount = 20;
			}
		}

		if (enemy->isAttack) {

			if (!DodgedMotion) {
				Php -= 1;
			}

		}
	
	    break;
	
	case GameState::result:

		AttackCount = 0;
		AttackMotion = false;
		isClick = false;
		DodgedMotion = false;
		angleDeg = 0;
		CoolTime = false;
		CoolCount = 20;
		Php = MaxPhp;
		Move = 0;
		isAttack = false;
		Back = false;

	    break;

	}

	

}

void Player::Draw()
{

	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:


		for (int i = 0; i < Php; i++) {
			DrawBox(i * 128, 0, (i + 1) * 128, 128, GetColor(255, 255, 255), true);
		}


		if (AttackMotion && Move < 400 && !Back) {

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
				Back = false;
			}

		}

		DrawRotaGraph(Px - 100 + Move, Py + 105, 0.4, angleRad, hImage[0], true);

		break;

	case GameState::result:

		break;

	}

	
}
