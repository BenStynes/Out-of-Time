#include "GameoverScene.h"

GameoverScene::GameoverScene(SceneManager& sceneManager, const SceneType sceneType)
	: BaseScene{ sceneManager, sceneType, false }
{
}

void GameoverScene::handleEvents(const sf::Event& event)
{
}

void GameoverScene::update(const sf::Time deltaTime) {
}

void GameoverScene::render(sf::RenderWindow& window) {
}

void GameoverScene::onEnter() {
	std::cout << "Entered Title Scene";
}

void GameoverScene::onExit() {
	std::cout << "Entered Title Scene";
}
