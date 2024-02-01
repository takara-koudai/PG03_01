#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (keys_[DIK_SPACE] && prekeys_[DIK_SPACE])
	{
		sceneNo = STAGE;
	}
	Novice::ScreenPrintf(640, 360, "Title");

}

void TitleScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
}
