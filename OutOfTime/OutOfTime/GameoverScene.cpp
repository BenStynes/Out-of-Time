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
	std::cout << "Entered GameOver Screen \n";

	if (m_music.openFromFile("Assets/Music/GameOverMusic.wav")) {
		m_music.play();
	}

	const auto& texHolder = getSharedContext().texHolder;
	m_sprite.setTexture(texHolder.get(TextureId::kGameOver));
	m_sprite.scale(2, 2);
}

void GameoverScene::onExit() {
	std::cout << "Entered Title Scene";
}
