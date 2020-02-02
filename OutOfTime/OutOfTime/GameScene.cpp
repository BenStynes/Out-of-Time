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

	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (sf::Mouse::Button::Left == event.key.code)
		{
			if (m_music.openFromFile("Assets/Music/WinningMusic.wav"))
			{
				m_music.play();
				m_music.setLoop(false);

				const auto& fontHolder = getSharedContext().fontHolder;
				winText.setFillColor(sf::Color::White);
				winText.setOutlineColor(sf::Color::Black);
				winText.setOutlineThickness(1);
				winText.setScale(3, 3);
				winText.setPosition(500, 450);
				winText.setFont(fontHolder.get(kRoboto));
				winText.setString("\t\tYou Win!\n\nWe ran out of time.");
				m_displayText = true;
			}
		}
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

		if (m_retries < 1)
		{
			requestPushScene(SceneType::kGameover);
		}

		
	}
}

void GameScene::render(sf::RenderWindow& window) {

	window.draw(m_sprite);
	m_clock.render(window);
	if (m_displayText)
	{
		window.draw(winText);
	}

}

void GameScene::onEnter() {
	std::cout << "Entered Game Scene \n";

	const auto& texHolder = getSharedContext().texHolder;
	m_sprite.setTexture(texHolder.get(TextureId::kGameBackground));
	m_sprite.setScale(2, 2);

	initialiseGears();

	if (m_music.openFromFile("Assets/Music/BackgroundMusic.wav")) {
		m_music.play();
		m_music.setLoop(true);
	}
}

void GameScene::onExit() {
	std::cout << "Exit Game Scene \n";
}

void GameScene::initialiseGears()
{
	const auto& texHolder = getSharedContext().texHolder;
	for (int loop = 0; loop < 9; loop++)
	{
		allGears[loop].initialise(sf::Vector2f(0.0f, 0.0f), texHolder.get(TextureId(loop)), Gear::GearType::kGearA);
	}
	int i = 0;
}
