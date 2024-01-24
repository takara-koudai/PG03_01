#include "Scene.h"

//タイトルシーンで初期化
int IScene::sceneNo = TITLE;

//仮想デストラクタの定義
IScene::~IScene() {}

int IScene::GetSceneNo() 
{ 
	return sceneNo; 
}
