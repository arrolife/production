#include "Player.h"
#include "StatusManager.h"

Player::Player()
{
	hImage[0] = LoadGraph("data/image/black.avif");
}

Player::~Player()
{
}

void Player::Update()
{

	StatusManager statusmanager;

	//statusmanager.Damage(true);

}

void Player::Draw()
{
	DrawExtendGraph(0, 0, 128, 128, hImage[0], true);
}
