#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Back.h"
#include "StatusManager.h"
#include "Screen.h"
#include "../Library/GameObject.h"

GameState gamestate;

PlayScene::PlayScene()
{
	gamestate = GameState::home;
	hImage[0] = LoadGraph("data/image/UI/mouse.png");
	hImage[1] = LoadGraph("data/image/UI/mouse_leftclick.png");
	hImage[2] = LoadGraph("data/image/UI/mouse_rightclick.png");

	new Back();
	new Player();
	new Enemy();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{

	Player* player = FindGameObject<Player>();

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}


	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && !isClick) {
		isClick = true;
		MouseImage = 1;
	}
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && !isClick) {
		isClick = true;
		MouseImage = 2;
	}
	if (GetMouseInput() == 0) {
		isClick = false;
		MouseImage = 0;
	}


	switch (gamestate) {

	case GameState::home:

		if (CheckHitKey(KEY_INPUT_B)) {
			isLevelSelect = true;
		}

		if (isLevelSelect) {
				if (ReleaseLevel >= 1) {
					SelectLevel = 25;

					//仮
					if (!StatusSet) {
						statusmanager.SetEnemyStatus(SelectLevel);
						StatusSet = true;
						isLevelSelect = false;
					}

					gamestate = GameState::battle;
				}
		}

		break;

	case GameState::battle:

		/*if (!StatusSet) {
			statusmanager.SetEnemyStatus(SelectLevel);
			statusmanager.Php = statusmanager.MaxPhp;
			StatusSet = true;
			isLevelSelect = false;
		}*/

		if (player->Php <= 0) {
			isWin = false;
			gamestate = GameState::result;
		}

		if (statusmanager.Ehp <= 0) {
			isWin = true;
			gamestate = GameState::result;
		}

		break;

	case GameState::result:

		StatusSet = false;

		if (isWin) {
			SelectLevel += 1;
			if (statusmanager.ELevel % 5 == 0) {
				player->MaxPhp += 1;
				player->PlayerLevel += 1;
			}
			player->Php = player->MaxPhp;
			statusmanager.SetEnemyStatus(SelectLevel);
			gamestate = GameState::battle;
		}

		if (CheckHitKey(KEY_INPUT_H)) {
			gamestate = GameState::home;
		}

		break;

	}

	if (CheckHitKey(KEY_INPUT_0)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	switch (gamestate) {

	case GameState::home:
		DrawString(100, 500, "gamestate = home", GetColor(0, 0, 0));
		break;

	case GameState::battle:
		DrawString(100, 500, "gamestate = battle", GetColor(0, 0, 0));
		break;

	case GameState::result:
		DrawString(100, 500, "gamestate = result", GetColor(0, 0, 0));
		break;

	case GameState::training:
		DrawString(100, 500, "gamestate = training", GetColor(0, 0, 0));
		break;

	}


	DrawString(0, 0, "PLAY SCENE", GetColor(0, 0, 0));
	DrawString(100, 400, "Push [0]Key To Title", GetColor(0, 0, 0));

	DrawFormatString(100, 450, GetColor(0, 0, 0), "StatusPoint = %d", statusmanager.StatusPoint);
	DrawFormatString(100, 350, GetColor(0, 0, 0), "ReleaseLevel = %d", ReleaseLevel);
	DrawFormatString(100, 550, GetColor(0, 0, 0), "NextNeedPoint = %d", statusmanager.NextNeedPoint);
	DrawFormatString(100, 650, GetColor(0, 0, 0), "PAtack = %d", statusmanager.PAttack);
	DrawFormatString(100, 700, GetColor(0, 0, 0), "PAtackWaiting = %f", statusmanager.PAttackWaiting);

	Mx = Screen::WIDTH - MouseSize;
	int num = MouseSize / 16;
	DrawExtendGraph(Mx, My + num, Screen::WIDTH, My + MouseSize + num, hImage[MouseImage], true);

}
