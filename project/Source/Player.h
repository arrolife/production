#pragma once
#include "../Library/GameObject.h"
#include "StatusManager.h"

class Player : public GameObject {

public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

private:

	int hImage[1];
	int count = 0;

};

