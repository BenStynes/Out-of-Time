#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include "SceneManager.h"

class App {
public:
	App();
	bool setup();
	void run();

private:
	const sf::Time m_timePerFrame;
	sf::RenderWindow m_window;
	SceneManager m_sceneManager;
};

