#pragma once
#include "Vector2.h"

class PlayerBullet
{
public:
	void Initialize(float speed, Vector2& position, const char* keys, const char* preKeys);

	void Update(Vector2& position);

	void Draw();

	void OnCollision(Vector2& position);

	Vector2 GetRadius();

	Vector2 GetPosition();

private:

	Vector2 position_;

	Vector2 radius_;

	const char* keys_;

	const char* preKeys_;

	float speed_;

	bool isShot = false;

	Vector2 seveposition_;

};

