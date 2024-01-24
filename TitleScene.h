#pragma once
#include "Scene.h"
#include <Novice.h>
#include "Input.h"

class TitleScene : public IScene 
{
public:

	void Init(char* keys, char* preKeys) override;

	void Update() override;

	void Draw() override;

private:
	char* keys_, * preKeys_;

	//int grHandle;

	Input* input_ = nullptr;
};
