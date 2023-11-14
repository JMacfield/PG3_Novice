#pragma once

#include "Vector2.h"

class Enemy {
public:
	void Initialize();
	void Update();
	void Draw();

	void OnCollision();

	bool GetIsAlive() { return isAlive_; }
	Vector2 GetPosition() { return position_; }
	float GetSize() { return radius_; }

private:
	Vector2 position_;
	Vector2 velocity_;

	float radius_;
	bool isAlive_;
};