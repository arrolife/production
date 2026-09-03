#pragma once
#include "../Library/GameObject.h"
#include <math.h>

class Player : public GameObject {

public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

	bool isAttack = false;
	int Php = 3;
	int MaxPhp = 3;
	int PlayerLevel = 0;
	int MaxAttackCount = 7; //初期値7
	int MotionSpeed = 80;

private:

	
	int hImage[5];
	int UIImage[1];
	int CircleImage[17];
	int CircleNumber = 0;
	int AttackCount = 0;
	bool isDead = false;
	bool isClick = false;


	int Move = 0;
	
	bool Back = false;

	bool DodgedMotion = false;
	int CoolCount = 20;
	bool CoolTime = false;

	bool AttackMotion = false;
	
	int Px = 760;
	int Py = 720;
	int PWidth = 100 * 2;
	int PHeight = 105 * 2;

	double angleDeg = 0.0;
	double angleRad = angleDeg * DX_PI_F / 180.0;

};
