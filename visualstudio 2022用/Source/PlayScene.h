#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:


	int BGMHandle[8];
	bool StatusSet = false;
	bool isWin = false;
	bool isLevelSelect = false;
	int SelectLevel = 0;
	int AutoAddCount = 0;
	int hImage[15];
	int MouseImage = 0;
	int MouseSize = 128;
	int Mx = 1700;
	int My = 0;
	bool isClick = false;

	int MapNumber = 0;
	int PanelSize = 450;
	bool PanelBlink = false;
	int BlinkCount = 0;

	int CoolTime = 300;
	int CoolTimeCount = 0;

	int BGMNumber = 0;
	int NumberCheck = 0;

	int TutorialTime = 300;
	int TutorialCount = 0;

	int ClearWaitTime = 120;
	int ClearWaitCount = 0;

};

enum class GameState {
	home,
	battle,
	result,
	clear
};

extern GameState gamestate;
