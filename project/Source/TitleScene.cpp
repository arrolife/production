#include "TitleScene.h"
#include "Back.h"

TitleScene::TitleScene()
{
	new Back();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	extern const char* Version();
	DrawString(0, 20, Version(), GetColor(0,0,0));
	DrawString(0, 0, "TITLE SCENE", GetColor(0,0,0));
	DrawFormatString(100, 100, GetColor(0,0,0), "%4.1f", 1.0f / Time::DeltaTime());
	DrawString(100, 400, "Push [P]Key To Play", GetColor(0, 0, 0));
}
