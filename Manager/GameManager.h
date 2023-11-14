#pragma once

#include "InputManager.h"
#include "Scene/IScene.h"
#include "Scene/TitleScene.h"
#include "Scene/StageScene.h"
#include "Scene/ClearScene.h"

#include <Novice.h>

class GameManager {
public:
	GameManager();
	~GameManager();

	void Initialize();
	void Run();

private:
	InputManager* inputManager_;
	std::unique_ptr<IScene> sceneArray_[3];

	int currentSceneNumber_;
	int previousSceneNumber_;
};