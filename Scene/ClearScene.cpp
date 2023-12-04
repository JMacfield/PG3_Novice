#include "ClearScene.h"

ClearScene::~ClearScene() {

}

void ClearScene::Initialize() {
	inputManager_ = InputManager::GetInstance();
}

void ClearScene::Update() {
	if (inputManager_->PressKey(DIK_SPACE)) {
		sceneNumber_ = TITLE_SCENE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(200, 400, "This is Clear Scene");
	Novice::ScreenPrintf(200, 420, "Press SPACE to Title");
}

void ClearScene::Finalize() {

}