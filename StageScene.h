#pragma once
#include "IScene.h"
#include <memory>
#include "Player.h"
#include "Enemy.h"

class StageScene : public IScene
{
public:

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void CheckOnCollision();

private:

	std::unique_ptr<Player> player_;

	std::unique_ptr<Enemy> enemy_;

};

