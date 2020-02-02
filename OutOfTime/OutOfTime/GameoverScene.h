#pragma once
#include "BaseScene.h"
#include <SFML/Graphics/Sprite.hpp>

class GameoverScene final : public BaseScene {
public:
	GameoverScene(SceneManager& sceneManager, const SceneType sceneType);

	void handleEvents(const sf::Event& event);
	void update(const sf::Time deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void onEnter() override;
	void onExit() override;

private:

	sf::Music m_music;
	sf::Sprite m_sprite;
};