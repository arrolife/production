#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject {

public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

private:

	int hImage[1];
	float AttackCount = 0.0f;
	bool isDead = false;
	bool isClick = false;

};

