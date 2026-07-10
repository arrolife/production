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

};

enum class GameState {
	home,
	battle,
	result,
	training,
	clear
};

extern GameState gamestate;
