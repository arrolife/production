#include "Back.h"
#include "Screen.h"
#include "StatusManager.h"

Back::Back()
{
	hImage[0] = LoadGraph("data/image/background/grass.jpg");
	hImage[1] = LoadGraph("data/image/background/desert.jpg");
	hImage[2] = LoadGraph("data/image/background/swamp.jpg");
	hImage[3] = LoadGraph("data/image/background/ruins.jpg");
	hImage[4] = LoadGraph("data/image/background/castle.jpg");
}

Back::~Back()
{
}

void Back::Update()
{

	if (statusmanager.ELevel >= 6) {
		num = 1;
	}
	if (statusmanager.ELevel >= 11) {
		num = 2;
	}
	if (statusmanager.ELevel >= 16) {
		num = 3;
	}
	if (statusmanager.ELevel >= 21) {
		num = 4;
	}
	
}

void Back::Draw()
{
	//DrawBox(0, 0, Screen::WIDTH, Screen::HEIGHT, GetColor(255, 255, 255), true);
	DrawExtendGraph(0, 0, Screen::WIDTH, Screen::HEIGHT, hImage[num], true);
}
