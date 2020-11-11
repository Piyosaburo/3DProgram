#include"All.h"

//Character02.png

char enemyImageName[16] = "Enemy";

//EnemyClass::EnemyClass(Vec2 pos, Vec2 scale, int alpha, float angle) : //PlayerClass のコンストラクタ
//	ObjectClass::ObjectClass(pos, scale, alpha, angle) {
//
//}

void Enemy::Init() {
	Engine::LoadTexture(enemyImageName, "Res/Character02.png");
	Tex = Engine::GetTexture(enemyImageName);	
}

void Enemy::Update() {

	bool chase = false;

	if ((Position.X - player->GetPosition().X) * (Position.X - player->GetPosition().X) +
		(Position.Y - player->GetPosition().Y) * (Position.Y - player->GetPosition().Y) <
		RANGE_TO_CHASE * RANGE_TO_CHASE) {
		chase = true;
	}

	if (chase == true) {


		//ベクトルを用いた追尾

		Vec2 v;

		v.X = player->GetPosition().X - Position.X; //player - enemy = 敵からプレイヤーのベクトル
		v.Y = player->GetPosition().Y - Position.Y;

		float l = sqrt((v.X * v.X) + (v.Y * v.Y)); //sqrt = 平方根を求める

		Vec2 speed;
		
		speed.X = v.X / l * ENEMY_SPEED;
		speed.Y = v.Y / l * ENEMY_SPEED;

		Position.X += speed.X;
		Position.Y += speed.Y;


		//三角関数を用いた追尾

		//double r = 0;
		//r = atan2((double)player->GetPosition().Y - Position.Y, (double)player->GetPosition().X - Position.X);
		////Angle = r * (180 / 3.14) + 180;

		//Position.X += ENEMY_SPEED * cosf(r);
		//Position.Y += ENEMY_SPEED * sin(r);
	}
	else {
		
	}
}

void Enemy::Draw() {
	Engine::DrawTexture(Position.X - Tex->Width / 2 * Scale.X, Position.Y - Tex->Height / 2 * Scale.Y, enemyImageName, Alpha, Angle, Scale.X, Scale.Y);
}

