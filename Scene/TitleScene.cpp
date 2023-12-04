#include "TitleScene.h"

#include <Novice.h>

TitleScene::~TitleScene() {

}

void TitleScene::Initialize() {
	inputManager_ = InputManager::GetInstance();
}

void TitleScene::Update() {
	if (inputManager_->PressKey(DIK_SPACE)) {
		sceneNumber_ = GAME_SCENE;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(200, 400, "This is Title Scene");
	Novice::ScreenPrintf(200, 420, "Press SPACE to Continue");
}

void TitleScene::Finalize() {

}