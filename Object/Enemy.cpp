#include "Enemy.h"

#include <Novice.h>

void Enemy::Initialize() {
	position_ = { 640.0f, 160.0f };
	velocity_ = { 2.0f, 0.0f };
	
	radius_ = 32.0f;
	isAlive_ = true;
}

void Enemy::Update() {
	position_.x += velocity_.x;

	if (position_.x >= 1200.0f || position_.x <= 64.0f) {
		velocity_.x *= -1.0f;
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(
			(int)position_.x, (int)position_.y, (int)radius_, (int)radius_, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::OnCollision() {
	isAlive_ = false;
}