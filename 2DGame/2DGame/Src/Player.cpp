#include"All.h"

char playerImageName[16] = "Player";

//PlayerClass::PlayerClass(Vec2 pos,Vec2 scale,int alpha,float angle): //PlayerClass のコンストラクタ
//	ObjectClass::ObjectClass(pos,scale,alpha,angle) { 
//	
//}

void PlayerClass::Init() {
	Engine::LoadTexture(playerImageName, "Res/Character01.png");
	Tex = Engine::GetTexture(playerImageName);
}

void PlayerClass::Update() {

	if (Engine::IsKeyboardKeyHeld(DIK_W)) {
		Position.Y -= PLAYER_SPPED;
	}
	if (Engine::IsKeyboardKeyHeld(DIK_S)) {
		Position.Y += PLAYER_SPPED;
	}
	if (Engine::IsKeyboardKeyHeld(DIK_A)) {
		Position.X -= PLAYER_SPPED;
	}
	if (Engine::IsKeyboardKeyHeld(DIK_D)) {
		Position.X += PLAYER_SPPED;
	}
}

void PlayerClass::Draw() {
	Engine::DrawTexture(Position.X - Tex->Width / 2 * Scale.X, Position.Y - Tex->Height / 2 * Scale.Y,
		playerImageName, Alpha, Angle, Scale.X, Scale.Y);
}

