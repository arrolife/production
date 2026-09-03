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
	hImage[9] = LoadGraph("data/image/UI/panel.png");
	hImage[10] = LoadGraph("data/image/UI/panel_2.png");
	hImage[11] = LoadGraph("data/image/UI/click.png");
	hImage[12] = LoadGraph("data/image/UI/tutorial.png");
	hImage[13] = LoadGraph("data/image/UI/gameclear.png");
	hImage[14] = LoadGraph("data/image/UI/click2.png");

	BGMHandle[0] = LoadSoundMem("data/sound/bgm/map1.mp3");
	BGMHandle[1] = LoadSoundMem("data/sound/bgm/map2.mp3");
	BGMHandle[2] = LoadSoundMem("data/sound/bgm/map3.mp3");
	BGMHandle[3] = LoadSoundMem("data/sound/bgm/map4.mp3");
	BGMHandle[4] = LoadSoundMem("data/sound/bgm/map5.mp3");
	BGMHandle[5] = LoadSoundMem("data/sound/bgm/boss1.mp3");
	BGMHandle[6] = LoadSoundMem("data/sound/bgm/boss2.mp3");
	BGMHandle[7] = LoadSoundMem("data/sound/bgm/boss3.mp3");

	PlaySoundMem(BGMHandle[0], DX_PLAYTYPE_BACK);
	
	BGMNumber = 0;
	
	new Back();
	new Player();
	new Enemy();


}

PlayScene::~PlayScene()
{
	
	
}

void PlayScene::Update()
{
	//音楽ループ再生してくれるところ
	if (!CheckSoundMem(BGMHandle[BGMNumber])) {
		PlaySoundMem(BGMHandle[BGMNumber], DX_PLAYTYPE_BACK);
	}

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

		TutorialCount += 1;

		if (TutorialCount >= TutorialTime) {
			SelectLevel = 1;

			if (!StatusSet) {
				statusmanager.SetEnemyStatus(SelectLevel);
				StatusSet = true;
			}

			gamestate = GameState::battle;
		}


		break;

	case GameState::battle:


		//BGM
		switch (statusmanager.ELevel) {

		case 1:
		case 2:
		case 3:
		case 4:
			NumberCheck = BGMNumber;
			BGMNumber = 0;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 6:
		case 7:
		case 8:
		case 9:
			NumberCheck = BGMNumber;
			BGMNumber = 1;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 11:
		case 12:
		case 13:
		case 14:
			NumberCheck = BGMNumber;
			BGMNumber = 2;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 16:
		case 17:
		case 18:
		case 19:
			NumberCheck = BGMNumber;
			BGMNumber = 3;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 21:
		case 22:
		case 23:
		case 24:
			NumberCheck = BGMNumber;
			BGMNumber = 4;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 5:
		case 10:
		case 15:
		case 20:
			NumberCheck = BGMNumber;
			BGMNumber = 5;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 25:
			NumberCheck = BGMNumber;
			BGMNumber = 6;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;

		case 26:
			NumberCheck = BGMNumber;
			BGMNumber = 7;
			if (NumberCheck != BGMNumber) {
				StopSoundMem(BGMHandle[NumberCheck]);
			}
			break;



		}

		
		if (statusmanager.Ehp <= 0) {
			isWin = true;

			if (statusmanager.ELevel == 26){
				gamestate = GameState::clear;
			}
			else {
				gamestate = GameState::result;
			}

			
		}

		if (player->Php <= 0) {

			isWin = false;

			if (statusmanager.ELevel != 26) {

				switch ((statusmanager.ELevel - 1) / 5) {

				case 0:
					SelectLevel = 0;
					break;

				case 1:
					SelectLevel = 5;
					break;

				case 2:
					SelectLevel = 10;
					break;

				case 3:
					SelectLevel = 15;
					break;

				case 4:
					SelectLevel = 20;
					break;

				}
			}

			if (statusmanager.ELevel == 26) {
				SelectLevel = 25;
			}

			statusmanager.SetEnemyStatus(SelectLevel);
			gamestate = GameState::result;

		}

		break;

	case GameState::result:

		StatusSet = false;
		
		CoolTimeCount += 1;

		if (CoolTimeCount >= CoolTime) {

			CoolTimeCount = 0;

			if (isWin) {
				SelectLevel += 1;
				if (statusmanager.ELevel % 5 == 0) {
					player->PlayerLevel += 1;
					player->MaxPhp += 1;
					player->MotionSpeed += 10;
				}

				if (statusmanager.ELevel % 10 == 0 && player->MaxAttackCount != 5) {
					player->MaxAttackCount -= 1;
				}

				player->Php = player->MaxPhp;
				statusmanager.SetEnemyStatus(SelectLevel);
				gamestate = GameState::battle;
			}

			if (!isWin) {
				SelectLevel += 1;
				player->Php = player->MaxPhp;
				statusmanager.SetEnemyStatus(SelectLevel);
				gamestate = GameState::battle;
			}
		}

		break;

	case GameState::clear:

		ClearWaitCount += 1;

		if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 || (GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) && ClearWaitCount >= ClearWaitTime) {
			for (int i = 0; i < 8; i++) {
				StopSoundMem(BGMHandle[i]);
			}
			ClearWaitCount = 0;
			SceneManager::ChangeScene("TITLE");
			
		}


		break;

	}

	

	//仮
	if (CheckHitKey(KEY_INPUT_0)) {
		SceneManager::ChangeScene("TITLE");
	}

}

void PlayScene::Draw()
{

	Mx = Screen::WIDTH - MouseSize;
	int num = MouseSize / 16;
	DrawExtendGraph(Mx, My + num, Screen::WIDTH, My + MouseSize + num, hImage[MouseImage], true);


	switch (gamestate) {

	case GameState::home :

		DrawGraph(550, 200, hImage[12], true);
		Mx = 450;
		DrawExtendGraph(Mx, 310, Mx + MouseSize, 310 + MouseSize, hImage[1], true);
		DrawExtendGraph(Mx, 500, Mx + MouseSize, 500 + MouseSize, hImage[2], true);

		break;

	case GameState::result:

		if (PanelBlink) {

			MapNumber = 3;
			BlinkCount += 1;

			if (BlinkCount >= 60) {

				BlinkCount = 0;
				PanelBlink = false;
			}
		}
		else {

			BlinkCount += 1;
			MapNumber = statusmanager.ELevel % 5 + 4;
			if (statusmanager.ELevel % 5 == 0) {
				MapNumber = 4;
			}

			if (BlinkCount >= 60) {

				BlinkCount = 0;
				PanelBlink = true;
			}

		}

		if (statusmanager.ELevel != 25) {
			DrawExtendGraph((Screen::WIDTH - PanelSize) / 2, (Screen::HEIGHT - PanelSize) / 2,
				(Screen::WIDTH - PanelSize) / 2 + PanelSize, (Screen::HEIGHT - PanelSize) / 2 + PanelSize, hImage[9], true);

			DrawExtendGraph(-20 + 767, 0 + 400, 380 + 767, 400 + 400, hImage[MapNumber], true);
		}
		

		if (statusmanager.ELevel == 25) {
			DrawExtendGraph((Screen::WIDTH - PanelSize) / 2, (Screen::HEIGHT - PanelSize) / 2,
				(Screen::WIDTH - PanelSize) / 2 + PanelSize, (Screen::HEIGHT - PanelSize) / 2 + PanelSize, hImage[10], true);
		}

		break;

	case GameState::clear:
		DrawGraph(500, 250, hImage[13], true);
		DrawGraph(500, 400, hImage[14], true);
		break;

	default:
		break;

	}


	
	

}
