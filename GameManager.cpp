#include "GameManager.h"
#include "Novice.h"

GameManager::GameManager()
{
	//�e�V�[���̔z��
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	for (int i = 0; i < SceneMax; i++) {
		//�Q�[���}�l�[�W���[���L�[�����ׂẴV�[���ɔ��f������
		sceneArr_[i]->Setkeys(keys_, preKeys_);

	}

	//�����V�[���̐ݒ�
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager() {}


int GameManager::Loop()
{
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();   //�t���[���J�n

		//�L�[���͂��󂯎��,main����ړ�
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		//�V�[���̃`�F�b�N
		preSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//�V�[���ύX�`�F�b�N
		if (preSceneNo_ != currentSceneNo_)
		{
			sceneArr_[currentSceneNo_]->Initialize();
		}

		//�X�V����
		sceneArr_[currentSceneNo_]->Update(); //�V�[�����Ƃ̍X�V����

		//�`�揈��
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();  //�t���[���̏I��

		//ESC�L�[�������ꂽ�u�ԃ��[�v�𔲂���
		if (keys_[DIK_ESCAPE] && preKeys_[DIK_ESCAPE]) {
			break;
		}

	}

	return 0;
}