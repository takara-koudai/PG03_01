#include "StageScene.h"
#include "Novice.h"

void StageScene::Initialize()
{
	player_ = std::make_unique<Player>();
	player_->Initialize(keys_, prekeys_);

	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void StageScene::Update()
{
	Novice::ScreenPrintf(640, 500, "Stage");

	if (enemy_->IsActive()) 
	{
		sceneNo = CLEAR;
	}

	player_->Update();
	enemy_->Update();

	CheckOnCollision();
}

void StageScene::Draw()
{
	player_->Draw();
	enemy_->Draw();
}

void StageScene::CheckOnCollision()
{
	const std::list<PlayerBullet*>& playerbullets = player_->GetBullet();

	Vector2 posA, posB, posC, radiusA, radiusB;

	posC = player_->GetPosition();

	posB = enemy_->GetPosition();

	radiusB = enemy_->GetRadius();

	for (PlayerBullet* bullet : playerbullets) {

		posA = bullet->GetPosition();

		radiusA = bullet->GetRadius();

		if (posA.x <= posB.x + radiusB.x &&
			posB.x <= posA.x + radiusA.x &&
			posA.y <= posB.y + radiusB.y &&
			posB.y <= posA.y + radiusA.y)
		{
			bullet->OnCollision(posC);

			enemy_->OnCollision();
		}
	}
}
