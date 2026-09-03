#include "TitleScene.h"
#include "Back.h"
#include "Screen.h"

TitleScene::TitleScene()
{
	isBlink = false;
	BlinkCount = 0;

	hImage[0] = LoadGraph("data/image/UI/title.png");
	hImage[1] = LoadGraph("data/image/UI/click.png");

	BGMHandle = LoadSoundMem("data/sound/bgm/map1.mp3");

	PlaySoundMem(BGMHandle, DX_PLAYTYPE_BACK);

	new Back();
}

TitleScene::~TitleScene()
{
	
}

void TitleScene::Update()
{

	WaitCount += 1;

	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 || (GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) && WaitCount >= WaitTime) {
		StopSoundMem(BGMHandle);
		WaitCount = 0;
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}

	BlinkCount += 1;

	if (BlinkCount >= 60) {
		BlinkCount = 0;
		isBlink = !isBlink;
	}

}


void TitleScene::Draw()
{
	
	int y = - 50;

	if (!isBlink) {
		DrawGraph(480, 410, hImage[1], true);
	}
	
	DrawExtendGraph((Screen::WIDTH - TitleWidth) / 2, y,
		(Screen::WIDTH - TitleWidth) / 2 + TitleWidth, y + TitleHeight, hImage[0], true);

}
