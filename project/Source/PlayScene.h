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
	int ELevel = 1;
	bool isWin = false;

};

enum class GameState {
	home,
	battle,
	result,
	training
};

extern GameState gamestate;
