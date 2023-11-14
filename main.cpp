#include <Novice.h>
#include "Manager/GameManager.h"

const char kWindowTitle[] = "LE2A_03_イソガイ_ユウト";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetConsoleOutputCP(65001);

	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();
	gameManager->Run();

	return 0;
}