#pragma once

#include "Vector2.h"
#include "Manager/InputManager.h"

class Player {
public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

	Vector2 GetPosition() { return position_; }
	Vector2 GetBulletPosition() { return bulletPosition_; }

private:
	Vector2 position_;
	Vector2 bulletPosition_;

	float moveSpeed_;
	bool isAttack_;

	InputManager* inputManager_;

	void Attack();
};