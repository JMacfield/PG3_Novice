#include "Player.h"

#include <Novice.h>

Player::Player() {

}

Player::~Player() {

}

void Player::Initialize() {
	position_ = { 800.0f,660.0f };
	bulletPosition_ = position_;
	isAttack_ = false;

	moveSpeed_ = 4.0f;
	inputManager_ = InputManager::GetInstance();
}

void Player::Update() {
	//Attack();

	if (isAttack_) {
		bulletPosition_.y -= 6.0f;
	}

	if (bulletPosition_.y <= -5.0f) {
		isAttack_ = false;
	}
}

void Player::Draw() {
	Novice::DrawBox((int)position_.x, (int)position_.y, 64, 64, 0.0f, WHITE, kFillModeSolid);

	if (isAttack_) {
		Novice::DrawEllipse((int)bulletPosition_.x, (int)bulletPosition_.y, 32, 32, 0.0f, WHITE, kFillModeSolid);
	}
}

void Player::MoveRight() {
	this->position_.x += this->moveSpeed_;
}

void Player::MoveLeft() {
	this->position_.x -= this->moveSpeed_;
}

void Player::Attack() {
	if (inputManager_->PressKey(DIK_SPACE)) {
		if (!isAttack_) {
			bulletPosition_ = position_;
			isAttack_ = true;
		}
	}
}