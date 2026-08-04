#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject {

public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;


private:

	int hImage[5];
	int AttackCount = 0;
	bool isDead = false;
	bool isClick = false;
	bool isAttack = false;


	bool isGuard = false;
	bool JustGuard = false;
	bool Just = false;

	bool AttackMotion = false;
	
	int Px = 760;
	int Py = 720;
	int PWidth = 100 * 2;
	int PHeight = 105 * 2;

};
