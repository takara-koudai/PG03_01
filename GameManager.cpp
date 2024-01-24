#include "GameManager.h"
#include "Novice.h"

GameManager::GameManager() 
{
	//各シーンの配列
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

		// キー入力を受け取る
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		//シーンのチェック
		prevSceneNO_ = currenSceneNo_;
		currenSceneNo_ = sceneArr_[currenSceneNo_]->GetSceneNo();

		// シーン変更チェック

		if (prevSceneNO_ != currenSceneNo_) {

			sceneArr_[currenSceneNo_]->Init(keys_, preKeys_);
		}

		//更新処理
		sceneArr_[currenSceneNo_]->Update();
		//描画処理
		sceneArr_[currenSceneNo_]->Draw();

		Novice::EndFrame();//フレームの終了

		if (preKeys_[DIK_ESCAPE] == 0 && keys_[DIK_ESCAPE] != 0) {
			break;
		}
	}

	return 0;
}
