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
	// How to Render
	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(100, 250, 50));
	window.draw(shape);
}

void TitleScene::onEnter() {
    std::cout << "Entered Title Scene \n";
}

void TitleScene::onExit() {
    std::cout << "Exit Title Scene \n";
}
