#pragma once
#include <memory>
#include "Scene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"
#include "Input.h"

class GameManager 
{
private:
	//�V�[����ێ����郁���o�֐�
	std::unique_ptr<IScene> sceneArr_[3];

	//
	int currenSceneNo_; // ���݂̃V�[��
	int prevSceneNO_; // �ߋ��̃V�[��



public:
	GameManager();
	~GameManager();

	void Init();

	int Run();

private:
	char keys_[256], preKeys_[256];

};

