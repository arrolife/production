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

	UIImage[0] = LoadGraph("data/image/UI/heart_red.png");

	CircleImage[0] = LoadGraph("data/image/UI/circle");
	CircleImage[1] = LoadGraph("data/image/UI/circlefull");
	CircleImage[2] = LoadGraph("data/image/UI/circle7-1");
	CircleImage[3] = LoadGraph("data/image/UI/circle7-2");
	CircleImage[4] = LoadGraph("data/image/UI/circle7-3");
	CircleImage[5] = LoadGraph("data/image/UI/circle7-4");
	CircleImage[6] = LoadGraph("data/image/UI/circle7-5");
	CircleImage[7] = LoadGraph("data/image/UI/circle7-6");
	CircleImage[8] = LoadGraph("data/image/UI/circle6-1");
	CircleImage[9] = LoadGraph("data/image/UI/circle6-2");
	CircleImage[10] = LoadGraph("data/image/UI/circle6-3");
	CircleImage[11] = LoadGraph("data/image/UI/circle6-4");
	CircleImage[12] = LoadGraph("data/image/UI/circle6-5");
	CircleImage[13] = LoadGraph("data/image/UI/circle5-1");
	CircleImage[14] = LoadGraph("data/image/UI/circle5-2");
	CircleImage[15] = LoadGraph("data/image/UI/circle5-3");
	CircleImage[16] = LoadGraph("data/image/UI/circle5-4");

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
			if (AttackCount >= MaxAttackCount) {
				
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
			angleDeg -= 25.0;
		}

		if (angleDeg <= -360) {
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
		//Php = MaxPhp;
		Move = 0;
		isAttack = false;
		Back = false;

	    break;

	}

	

}

void Player::Draw()
{

	switch (MaxAttackCount) {

	case 7:

		if (AttackCount == 0) {
			CircleNumber = 0;
		}
		else if (AttackCount == MaxAttackCount) {
			CircleNumber = 2;
		}
		else {
			CircleNumber = AttackCount + 1;
		}

		break;

	case 6:

		if (AttackCount == 0) {
			CircleNumber = 0;
		}
		else if (AttackCount == MaxAttackCount) {
			CircleNumber = 2;
		}
		else {
			CircleNumber = AttackCount + 7;
		}

		break;

	case 5:

		if (AttackCount == 0) {
			CircleNumber = 0;
		}
		else if (AttackCount == MaxAttackCount) {
			CircleNumber = 2;
		}
		else {
			CircleNumber = AttackCount + 12;
		}

		break;

	}

	DrawExtendGraph(500, 500, 1000, 1000, CircleImage[CircleNumber], true);


	switch (gamestate) {

	case GameState::home:
		break;

	case GameState::battle:


		for (int i = 0; i < Php; i++) {
			//DrawBox(i * 128, 0, (i + 1) * 128, 128, GetColor(255, 255, 255), true);
			DrawExtendGraph(i * 128, 0, (i + 1) * 128, 128, UIImage[0], true);
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
				AttackCount = 0;
			}

		}

		int num = 0;

		switch (PlayerLevel) {

		case 0:
		case 1:
			num = 0;
			break;

		case 2:
		case 3:
			num = 1;
			break;

		default:
			num = 2;
			break;

		}


		DrawRotaGraph(Px - 100 + Move, Py + 105, 0.4, angleRad, hImage[num], true);

		break;

	case GameState::result:

		break;

	}

	
}
