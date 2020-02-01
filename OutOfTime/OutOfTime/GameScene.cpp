#include "GameScene.h"

GameScene::GameScene(SceneManager& sceneManager, const SceneType sceneType)
	: BaseScene{ sceneManager, sceneType, false }
{
}

void GameScene::handleEvents(const sf::Event& event)
{
}

void GameScene::update(const sf::Time deltaTime) {
}

void GameScene::render(sf::RenderWindow& window) {

}

void GameScene::onEnter() {
	std::cout << "Entered Game Scene \n";
}

void GameScene::onExit() {
	std::cout << "Exit Game Scene \n";
}
