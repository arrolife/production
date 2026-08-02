#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject {

public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

private:

	int hImage[3];
	float AttackCount = 0.0f;
	bool isDead = false;
	bool isClick = false;
	int Px = 0;
	int Py = 0;
	int PWidth = 0;
	int PHeight = 0;

};

