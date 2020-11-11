#pragma once
#include"All.h"

class ObjectClass {

protected:
	Vec2 Position;
	Vec2 Scale;
	Texture* Tex;
	int Alpha;
	float Angle;
public:
	//ObjectClass(Vec2,Vec2,int,float);
	ObjectClass(Vec2 pos, Vec2 scale,int alpha,float angle):Position(pos),Scale(scale),Alpha(alpha),Angle(angle){}

	virtual void Init() = 0;
	virtual void Update() = 0; //�������z�֐�(���ڎg�p���Ȃ��A�h���������N���X�Ŏg�p����)
	virtual void Draw() = 0;
	Vec2 GetPosition() {
		return Position;
	}
	Vec2 GetScale() {
		return Scale;
	}
};