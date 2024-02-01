#include "GameManager.h"
#include "Novice.h"

GameManager::GameManager()
{
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	for (int i = 0; i < SceneMax; i++) {
		//ゲームマネージャーをキーをすべてのシーンに反映させる
		sceneArr_[i]->Setkeys(keys_, preKeys_);

	}

	//初期シーンの設定
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager() {}


int GameManager::Loop()
{
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();   //フレーム開始

		//キー入力を受け取る,mainから移動
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		//シーンのチェック
		preSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//シーン変更チェック
		if (preSceneNo_ != currentSceneNo_)
		{
			sceneArr_[currentSceneNo_]->Initialize();
		}

		//更新処理
		sceneArr_[currentSceneNo_]->Update(); //シーンごとの更新処理

		//描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();  //フレームの終了

		//ESCキーが押された瞬間ループを抜ける
		if (keys_[DIK_ESCAPE] && preKeys_[DIK_ESCAPE]) {
			break;
		}

	}

	return 0;
}