#include "Back.h"
#include "Screen.h"

Back::Back()
{
}

Back::~Back()
{
}

void Back::Update()
{
}

void Back::Draw()
{
	DrawBox(0, 0, Screen::WIDTH, Screen::HEIGHT, GetColor(255, 255, 255), true);
}
