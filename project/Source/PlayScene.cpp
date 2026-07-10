#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Back.h"
#include "StatusManager.h"

GameState gamestate;

PlayScene::PlayScene()
{
	gamestate = GameState::home;

	new Back();
	new Player();
	new Enemy();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{

	switch (gamestate) {

	case GameState::home:


		AutoAddCount += 1;

		if (AutoAddCount >= 10 * 60) {

			switch (ReleaseLevel) {

			case 1:
				statusmanager.AddStatusPoint(1);
				break;

			case 2:
				statusmanager.AddStatusPoint(1);
				break;

			case 3:
				statusmanager.AddStatusPoint(2);
				break;

			case 4:
				statusmanager.AddStatusPoint(25);
				break;

			case 5:
				statusmanager.AddStatusPoint(250);
				break;

			}

		}


		if (CheckHitKey(KEY_INPUT_B)) {
			isLevelSelect = true;
		}

		if (CheckHitKey(KEY_INPUT_T)) {
			gamestate = GameState::training;
		}

		if (isLevelSelect) {
			if (CheckHitKey(KEY_INPUT_1)) {
				if (ReleaseLevel >= 1) {
					SelectLevel = 1;
					gamestate = GameState::battle;
				}
			}
			if (CheckHitKey(KEY_INPUT_2)) {
				if (ReleaseLevel >= 2) {
					SelectLevel = 2;
					gamestate = GameState::battle;
				}
			}
			if (CheckHitKey(KEY_INPUT_3)) {
				if (ReleaseLevel >= 3) {
					SelectLevel = 3;
					gamestate = GameState::battle;
				}
			}
			if (CheckHitKey(KEY_INPUT_4)) {
				if (ReleaseLevel >= 4) {
					SelectLevel = 4;
					gamestate = GameState::battle;
				}
			}
			if (CheckHitKey(KEY_INPUT_5)) {
				if (ReleaseLevel >= 5) {
					SelectLevel = 5;
					gamestate = GameState::battle;
				}
			}
		}

		break;

	case GameState::battle:

		if (!StatusSet) {
			statusmanager.SetEnemyStatus(SelectLevel);
			statusmanager.Php = statusmanager.MaxPhp;
			StatusSet = true;
			isLevelSelect = false;
		}

		if (statusmanager.Php <= 0) {
			isWin = false;
			gamestate = GameState::result;
		}
		else if (statusmanager.Ehp <= 0) {
			isWin = true;

			switch (SelectLevel) {

			case 1:
				statusmanager.AddStatusPoint(1);
				break;

			case 2:
				statusmanager.AddStatusPoint(10);
				break;

			case 3:
				statusmanager.AddStatusPoint(100);
				break;

			case 4:
				statusmanager.AddStatusPoint(1000);
				break;

			case 5:
				statusmanager.AddStatusPoint(10000);
				break;

			}

			
			if (SelectLevel == ReleaseLevel) {
				ReleaseLevel += 1;
			}
			SelectLevel = 0;
			gamestate = GameState::result;

			
		}

		break;

	case GameState::result:

		StatusSet = false;

		if (CheckHitKey(KEY_INPUT_H)) {
			gamestate = GameState::home;
		}

		break;

	case GameState::training:

		if (CheckHitKey(KEY_INPUT_H)) {
			gamestate = GameState::home;
		}

		if (statusmanager.StatusPoint >= statusmanager.NextNeedPoint) {

			if (CheckHitKey(KEY_INPUT_1)) {
				statusmanager.AddMaxPhp();
			}
			if (CheckHitKey(KEY_INPUT_2)) {
				statusmanager.AddPAtack();
			}
			if (CheckHitKey(KEY_INPUT_3)) {
				statusmanager.SubtractPAtackWaiting();
			}
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
	DrawFormatString(100, 600, GetColor(0, 0, 0), "MaxPhp = %d", statusmanager.MaxPhp);
	DrawFormatString(100, 650, GetColor(0, 0, 0), "PAtack = %d", statusmanager.PAtack);
	DrawFormatString(100, 700, GetColor(0, 0, 0), "PAtackWaiting = %f", statusmanager.PAtackWaiting);

}
