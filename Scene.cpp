#include "Scene.h"

//�^�C�g���V�[���ŏ�����
int IScene::sceneNo = TITLE;

//���z�f�X�g���N�^�̒�`
IScene::~IScene() {}

int IScene::GetSceneNo() 
{ 
	return sceneNo; 
}
