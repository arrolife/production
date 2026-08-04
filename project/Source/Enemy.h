#pragma once
#include "../Library/GameObject.h"

class Enemy : public GameObject {

public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;

	bool isAttack = false;
	bool JustGuardJudge = false;

private:

	int hImage[12];
	int UIImage[3];
	float AttackCount = 0.0f;
	float DirectionCount = 0;
	
	bool isDead = false;
	bool AttackMotion = false;
	float MotionCount = 4.0f;

	float UISizeChange = 0;
	int Move = 0;
	int MotionSpeed = 80;

	int AttackWait = 0;
	bool RandomSelect = false;

	int TimeCount = 0;
	bool UIMotion = false;
	bool Back = false;
};