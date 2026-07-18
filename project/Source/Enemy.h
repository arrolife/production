#pragma once
#include "../Library/GameObject.h"

class Enemy : public GameObject {

public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;

private:

	int hImage[12];
	float AttackCount = 0.0f;
	float DirectionCount = 0;
	bool isAttack = false;
	bool isDead = false;
	int Ex = 0;

};