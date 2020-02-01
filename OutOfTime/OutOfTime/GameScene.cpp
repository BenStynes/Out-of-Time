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

	window.draw(m_sprite);
	m_clock.render(window);
}

void GameScene::onEnter() {
	std::cout << "Entered Game Scene \n";

	const auto& texHolder = getSharedContext().texHolder;
	m_sprite.setTexture(texHolder.get(TextureId::kGameBackground));
	m_sprite.setScale(2, 2);
}

void GameScene::onExit() {
	std::cout << "Exit Game Scene \n";
}
