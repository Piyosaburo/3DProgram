#pragma once
#include"All.h"

class PlayerClass : public ObjectClass {
public:
	PlayerClass(Vec2 pos, Vec2 scale ,int alpha ,float angle) : ObjectClass(pos,scale,alpha,angle) {}

	void Init();
	void Update();
	void Draw();
};

#define PLAYER_SPPED (1)