#include "ClearScene.h"
void ClearScene::Initialize() 
{ 
	input_->GetInstance(); 
}

void ClearScene::Update() 
{
	if (input_->TriggerKey(DIK_SPACE)) 
	{
		sceneNo = STAGE;
	}
}

void ClearScene::Draw() {}
