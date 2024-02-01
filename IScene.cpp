#include "IScene.h"

int IScene::sceneNo = TITLE;

IScene::~IScene() {};

int IScene::GetSceneNo() { return sceneNo; }

void IScene::Setkeys(char* keys, char* prekeys)
{
	keys_ = keys;
	prekeys_ = prekeys;
}