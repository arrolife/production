#pragma once
#include "../Library/GameObject.h"

class Enemy : public GameObject {

public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;

	bool isAttack = false;
	

private:

	int hImage[25];
	int UIImage[5];

	int AttackType = 0;
	
	bool AttackMotion = false;
	float MotionCount = 4.0f;
	float AttackSpeed = 0;

	float UISizeChange = 0;
	int Move = 0;
	int MotionSpeed = 80;

	int AttackWait = 0;
	bool RandomSelect = false;

	int TimeCount = 0;
	bool UIMotion = false;
	bool Back = false;
};