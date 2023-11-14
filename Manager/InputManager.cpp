#include "InputManager.h"

InputManager* InputManager::GetInstance() {
	static InputManager instance;

	return &instance;
}

void InputManager::Initialize() {
	for (int i = 0; i < 256; i++) {
		keys[i] = { 0 };
		preKeys[i] = { 0 };
	}
}

void InputManager::Update() {
	for (int i = 0; i < 256; i++) {
		preKeys[i] = keys[i];
	}

	Novice::GetHitKeyStateAll(keys);
}

bool InputManager::PushKey(uint8_t keyNumber) {
	if (!keys[keyNumber] && preKeys[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}

bool InputManager::PressKey(uint8_t keyNumber) {
	if (keys[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}