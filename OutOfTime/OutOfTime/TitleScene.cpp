#include "TitleScene.h"
#include <SFML/Graphics/CircleShape.hpp>


TitleScene::TitleScene(SceneManager& sceneManager, const SceneType sceneType)
    : BaseScene { sceneManager, sceneType, false }
{
}

void TitleScene::handleEvents(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Right)
		{
			//How to change scene
			requestPushScene(SceneType::kGame);
			std::cout << "the right button was pressed" << std::endl;
		}
	}
}

void TitleScene::update(const sf::Time deltaTime) {
}

void TitleScene::render(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void TitleScene::onEnter() {
	std::cout << "Entered Title Scene \n";

	if (m_music.openFromFile("Assets/Music/IntroNoise.wav")) {
		m_music.play();
	}

	const auto& texHolder = getSharedContext().texHolder;
	m_sprite.setTexture(texHolder.get(TextureId::kTitle));
	m_sprite.scale(2, 2);
}


void TitleScene::onExit() {
    std::cout << "Exit Title Scene \n";
}
