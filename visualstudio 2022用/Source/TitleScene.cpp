#include "TitleScene.h"
#include "Back.h"
#include "Screen.h"

TitleScene::TitleScene()
{
	isBlink = false;
	BlinkCount = 0;

	hImage = LoadGraph("data/image/UI/title.png");
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

	BlinkCount += 1;

	if (BlinkCount >= 60) {
		BlinkCount = 0;
		isBlink = !isBlink;
	}

}


void TitleScene::Draw()
{
	SetFontSize(70);
	SetFontThickness(100);

	

	int y = - 50;

	if (!isBlink) {
		DrawString(660, 600, "Plese Mouse Click", GetColor(60, 60, 60));
	}
	
	DrawExtendGraph((Screen::WIDTH - TitleWidth) / 2, y,
		(Screen::WIDTH - TitleWidth) / 2 + TitleWidth, y + TitleHeight, hImage, true);

}
