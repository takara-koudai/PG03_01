#include "Player.h"
#include"Novice.h"
#include"MatrixTrans.h"

Player::~Player()
{
	for (PlayerBullet* bullet : playerbullets_) {
		delete bullet;
	}
}

void Player::Initialize(const char* keys, const char* preKeys)
{
	position_ = { 640.0f,360.0f };

	radius_ = { 50.0f,50.0f };

	keys_ = keys;

	preKeys_ = preKeys;

	speed_ = 5.0f;
}

void Player::Update()
{
	if (keys_[DIK_D])
	{
		position_.x += speed_;
	}
	else if (keys_[DIK_A]) 
	{
		position_.x -= speed_;
	}

	Attack();
	for (PlayerBullet* bullet : playerbullets_) 
	{
		bullet->Update(position_);
	}
}

void Player::Draw()
{
	Novice::DrawBox((int)position_.x, (int)position_.y, (int)radius_.x, (int)radius_.y, 0.0f, WHITE, kFillModeSolid);

	for (PlayerBullet* bullet : playerbullets_) 
	{
		bullet->Draw();
	}
}

void Player::Attack()
{
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE])
	{

		const float bulletspeed = 10.0f;
		PlayerBullet* newbullet = new PlayerBullet();
		newbullet->Initialize(bulletspeed, position_, keys_, preKeys_);

		playerbullets_.push_back(newbullet);
	}
}

Vector2 Player::GetPosition()
{
	Vector2 pos;

	pos.x = position_.x;
	pos.y = position_.y;
	return pos;
}