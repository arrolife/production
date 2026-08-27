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
	hImage[3] = LoadGraph("data/image/UI/map.png");
	hImage[4] = LoadGraph("data/image/UI/map_1.png");
	hImage[5] = LoadGraph("data/image/UI/map_2.png");
	hImage[6] = LoadGraph("data/image/UI/map_3.png");
	hImage[7] = LoadGraph("data/image/UI/map_4.png");
	hImage[8] = LoadGraph("data/image/UI/map_5.png");

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
					SelectLevel = 1;

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
				player->PlayerLevel += 1;
				player->MaxPhp += 1;
			}

			if (statusmanager.ELevel % 10 == 0 && player->MaxAttackCount != 5) {
				player->MaxAttackCount -= 1;
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

	Mx = Screen::WIDTH - MouseSize;
	int num = MouseSize / 16;
	DrawExtendGraph(Mx, My + num, Screen::WIDTH, My + MouseSize + num, hImage[MouseImage], true);


	MapNumber = statusmanager.ELevel % 5 + 3;
	if (statusmanager.ELevel % 5 == 0) {
		MapNumber = 8;
	}

	DrawExtendGraph(-20, -30 + 30, 480 - 100, 470 - 100 + 30, hImage[MapNumber], true);

}
