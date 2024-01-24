#include "TitleScene.h"

void TitleScene::Init(char* keys, char* preKeys) {

	keys_ = keys;

	preKeys_ = preKeys;

	// grHandle = Novice::LoadTexture("title.png");
}

void TitleScene::Update() {

	//if (!preKeys_[DIK_SPACE] && keys_[DIK_SPACE]) {
	//
	//	sceneNo = STAGE;
	//}

	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0)
	{
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {

	// Novice::DrawSprite(0, 0, grHandle, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
	Novice::ScreenPrintf(0, 0, "Title");
}
