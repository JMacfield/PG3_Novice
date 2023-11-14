#include "GameManager.h"

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::Initialize() {
	Novice::Initialize("PG3_Novice", 1280, 720);
	inputManager_ = InputManager::GetInstance();
	inputManager_->Initialize();

	sceneArray_[0] = std::make_unique<TitleScene>();
	sceneArray_[0]->Initialize();

	sceneArray_[1] = std::make_unique<StageScene>();
	sceneArray_[2] = std::make_unique<ClearScene>();

	currentSceneNumber_ = TITLE_SCENE;
}

void GameManager::Run() {
	Initialize();

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();
		inputManager_->Update();

		///
		/// ↓更新処理ここから
		///
		previousSceneNumber_ = currentSceneNumber_;
		currentSceneNumber_ = sceneArray_[currentSceneNumber_]->GetSceneNumber();

		if (currentSceneNumber_ != previousSceneNumber_) {
			sceneArray_[previousSceneNumber_]->Finalize();
			sceneArray_[currentSceneNumber_]->Initialize();
		}

		sceneArray_[currentSceneNumber_]->Update();

		///
		/// ↑更新処理ここまで
		///


		///
		/// ↓描画処理ここから
		///

		sceneArray_[currentSceneNumber_]->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager_->PushKey(DIK_ESCAPE)) {
			break;
		}
	}

	Novice::Finalize();
}