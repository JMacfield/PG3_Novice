#include "StageScene.h"

StageScene::~StageScene() {

}

void StageScene::Initialize() {
	inputHandler_ = new InputHandler();

	inputHandler_->AssignMoveLeftCommandToPressKeyA();
	inputHandler_->AssignMoveRightCommandToPressKeyD();

	player_ = std::make_unique<Player>();
	player_->Initialize();

	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void StageScene::Update() {
	command_ = inputHandler_->HandleInput();

	if (this->command_) {
		command_->Execute(*player_);
	}

	player_->Update();
	
	enemy_->Update();

	Vector2 Distance = {
	   (enemy_->GetPosition().x - player_->GetBulletPosition().x) *
		   (enemy_->GetPosition().x - player_->GetBulletPosition().x),
	   (enemy_->GetPosition().y - player_->GetBulletPosition().y) *
		   (enemy_->GetPosition().y - player_->GetBulletPosition().y)
	};

	if (Distance.x + Distance.y <= (enemy_->GetSize() + 16.0f) * (enemy_->GetSize() + 16.0f)) {
		enemy_->OnCollision();
	}

	if (!enemy_->GetIsAlive()) {
		sceneNumber_ = CLEAR_SCENE;
	}
}

void StageScene::Draw() {
	player_->Draw();
	enemy_->Draw();
}

void StageScene::Finalize() {

}