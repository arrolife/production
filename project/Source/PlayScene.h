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
	bool StatusSet = false;
	bool isWin = false;
	int ReleaseLevel = 1;
	bool isLevelSelect = false;
	int SelectLevel = 0;
	int AutoAddCount = 0;
	int hImage[10];
	int MouseImage = 0;
	int MouseSize = 128;
	int Mx = 1700;
	int My = 0;
	bool isClick = false;

	int MapNumber = 0;

};

enum class GameState {
	home,
	direction,
	battle,
	result,
	clear
};

extern GameState gamestate;
