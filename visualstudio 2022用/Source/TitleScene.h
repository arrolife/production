#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;

private:
	int hImage = 0;
	int TitleWidth = 1178;
	int TitleHeight = 840;

	int BlinkCount = 0;
	bool isBlink = false;

};
