#pragma once
#include"IScene.h"
#include "ClearScene.h"
#include"StageScene.h"
#include"TitleScene.h"

class GameManager
{
private:

	//�V�[����ێ����郁���o�ϐ�
	std::unique_ptr<IScene> sceneArr_[3];

	//�ǂ̃X�e�[�W���Ăяo�������Ǘ�����ϐ�
	int currentSceneNo_; //���݂̃V�[��
	int preSceneNo_; //�O�̃V�[��
	//�L�[���͌��ʂ��󂯎�锠
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

public:

	GameManager(); //�R���X�g���N�^

	~GameManager(); //�f�X�g���N�^

	int Loop(); //���̊֐��ŃQ�[�����[�v���Ăяo��

};

