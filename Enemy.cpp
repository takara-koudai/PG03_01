#include "Enemy.h"
#include"Novice.h"
#include"MatrixTrans.h"

void Enemy::Initialize()
{
	position_ = { 640.0f,100.0f };

	radius_ = { 50.0f,50.0f };

	speed_ = 1.0f;
}

void Enemy::Update()
{

	position_.x = position_.x += speed_;

	if (position_.x + radius_.x >= 1280 || position_.x <= 0)
	{
		speed_ = speed_ * -1;
	}

}

void Enemy::Draw()
{
	Novice::DrawBox((int)position_.x, (int)position_.y, (int)radius_.x, (int)radius_.y, 0.0f, RED, kFillModeSolid);
}

void Enemy::OnCollision()
{
	isActive_ = true;
}

Vector2 Enemy::GetRadius()
{
	Vector2 radius;

	radius.x = radius_.x;
	radius.y = radius_.y;
	return radius;
}

Vector2 Enemy::GetPosition()
{
	Vector2 pos;

	pos.x = position_.x;
	pos.y = position_.y;
	return pos;
}
