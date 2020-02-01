#include "SplashScene.h"


SplashScene::SplashScene(SceneManager& sceneManager, const SceneType sceneType)
    : BaseScene { sceneManager, sceneType, false }
{
}

void SplashScene::handleEvents(const sf::Event& event)
{
}

void SplashScene::update(const sf::Time deltaTime) {
}

void SplashScene::render(sf::RenderWindow& window) {
}

void SplashScene::onEnter() {
    std::cout << "Entered Splash Scene \n";
}

void SplashScene::onExit() {
    std::cout << "Exit Splash Scene \n";
}
