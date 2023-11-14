#pragma once

#include "IScene.h"
#include "Manager/InputManager.h"

class TitleScene : public IScene {
public:
	~TitleScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	InputManager* inputManager_ = nullptr;
};