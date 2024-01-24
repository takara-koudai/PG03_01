#pragma once
#include "Vector2.h"

class Player
{
public:
	Player();

	void Initialize();
	void Update();
	void Draw();

	//Še“®‚«
	void UpMove();
	void DownMove();
	void RightMove();
	void LeftMove();


private:

	Vector2 Pos_;

	float speed_;

};

