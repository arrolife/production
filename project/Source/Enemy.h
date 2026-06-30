#pragma once
#include "../Library/GameObject.h"

class Enemy : public GameObject {

public:
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;

private:

	int hImage[1];
	float AtackCount = 0.0f;
	bool isDead = false;

};