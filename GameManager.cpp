#include "GameManager.h"
#include "Novice.h"

GameManager::GameManager() 
{
	//�e�V�[���̔z��
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currenSceneNo_ = TITLE;
}

GameManager::~GameManager() {}

void GameManager::Init() {
	sceneArr_[currenSceneNo_]->Init(keys_, preKeys_);
}

int GameManager::Run() {

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		// �L�[���͂��󂯎��
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		//�V�[���̃`�F�b�N
		prevSceneNO_ = currenSceneNo_;
		currenSceneNo_ = sceneArr_[currenSceneNo_]->GetSceneNo();

		// �V�[���ύX�`�F�b�N

		if (prevSceneNO_ != currenSceneNo_) {

			sceneArr_[currenSceneNo_]->Init(keys_, preKeys_);
		}

		//�X�V����
		sceneArr_[currenSceneNo_]->Update();
		//�`�揈��
		sceneArr_[currenSceneNo_]->Draw();

		Novice::EndFrame();//�t���[���̏I��

		if (preKeys_[DIK_ESCAPE] == 0 && keys_[DIK_ESCAPE] != 0) {
			break;
		}
	}

	return 0;
}
