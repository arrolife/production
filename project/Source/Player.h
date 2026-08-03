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
	
	int Px = 760;
	int Py = 720;
	int PWidth = 100 * 2;
	int PHeight = 105 * 2;

};
