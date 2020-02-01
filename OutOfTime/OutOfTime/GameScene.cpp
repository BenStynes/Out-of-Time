#include "GameScene.h"

GameScene::GameScene(SceneManager& sceneManager, const SceneType sceneType)
	: BaseScene{ sceneManager, sceneType, false }
{
}

void GameScene::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		m_mousePos.x  =sf::Mouse::getPosition().x;
		m_mousePos.y = sf::Mouse::getPosition().y;
	}
}

void GameScene::update(const sf::Time deltaTime) {
	inRightPos = m_clock.checkForpositionOnRelease(&m_mousePos);

	for (int i = 0; i < 5; i++)
	{

		if (inRightPos)
		{
			//SET GEAR POS TO CLOCK.GETwinpos(i)
	
		}


	}
}

void GameScene::render(sf::RenderWindow& window) {
	m_clock.render(window);
}

void GameScene::onEnter() {
	std::cout << "Entered Game Scene \n";
}

void GameScene::onExit() {
	std::cout << "Exit Game Scene \n";
}
