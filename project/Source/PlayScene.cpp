#include "PlayScene.h"
#include "Player.h"
#include "Back.h"
#include "StatusManager.h"

PlayScene::PlayScene()
{
	new Back();
	new Player();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	StatusManager statusmanager;

	DrawString(0, 0, "PLAY SCENE", GetColor(0, 0, 0));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(0, 0, 0));

}
