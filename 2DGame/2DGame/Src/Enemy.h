#pragma once
#include"All.h"

class Enemy : public ObjectClass {

protected:
	PlayerClass* player;

public:
	Enemy(Vec2 pos, Vec2 scale, int alpha, float angle,PlayerClass& p) : ObjectClass(pos, scale, alpha, angle),player(&p) {}

	void Init();
	void Update();
	void Draw();
};

#define ENEMY_SPEED (0.7f)
#define RANGE_TO_CHASE (100)
