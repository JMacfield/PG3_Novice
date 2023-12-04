#pragma once

#include "IScene.h"
#include "Manager/InputManager.h"

#include "Object/Player.h"
#include "Object/Enemy.h"

#include <Manager/ICommand.h>
#include <Manager/InputHandler.h>

#include <memory>

class StageScene : public IScene {
public:
	~StageScene() override;
	
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* command_ = nullptr;

	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
};