#pragma once

#include "IScene.h"
#include "Manager/InputManager.h"

class ClearScene : public IScene {
public:
	~ClearScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	InputManager* inputManager_ = nullptr;
};