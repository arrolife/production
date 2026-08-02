#include "Back.h"
#include "Screen.h"

Back::Back()
{
	hImage = LoadGraph("data/image/background/grass.jpg");
}

Back::~Back()
{
}

void Back::Update()
{
}

void Back::Draw()
{
	//DrawBox(0, 0, Screen::WIDTH, Screen::HEIGHT, GetColor(255, 255, 255), true);
	DrawExtendGraph(0, 0, Screen::WIDTH, Screen::HEIGHT, hImage, true);
}
