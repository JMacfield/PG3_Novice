#pragma once

#include <Novice.h>
#include <stdint.h>

class InputManager {
public:
	static InputManager* GetInstance();

	void Initialize();
	void Update();

	bool PushKey(uint8_t keyNumber);
	bool PressKey(uint8_t keyNumber);

private:
	char keys[256];
	char preKeys[256];
};