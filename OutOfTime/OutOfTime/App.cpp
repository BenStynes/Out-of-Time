#include "App.h"

#include <SFML/Window/Event.hpp>

#include "SharedContext.h"

App::App() : 
	m_window { sf::VideoMode(1600U, 1200U), "OutOfTime", sf::Style::Close },
	m_sceneManager{ SharedContext { m_texHolder, m_fontHolder, m_musicHolder, m_soundHolder } },
	m_timePerFrame{ sf::seconds(1.f / 60.f) } {
}

bool App::setup() {
	// Load Textures
	m_texHolder.load(TextureId::kTitle, "Assets/Texture/Backgrounds/title.png");
	m_texHolder.load(TextureId::kGameBackground, "Assets/Texture/Backgrounds/splashScreenTexture.jpg");

	m_texHolder.load(TextureId::kBSOne, "Assets/Texture/BalanceSpring/BalanceSpringSet1");
	m_texHolder.load(TextureId::kBSTwo, "Assets/Texture/BalanceSpring/BalanceSpringSet2");
	m_texHolder.load(TextureId::kBSThree, "Assets/Texture/BalanceSpring/BalanceSpringSet3");
	m_texHolder.load(TextureId::kBSFour, "Assets/Texture/BalanceSpring/BalanceSpringSet4");

	// Load Font

	// Load Sound

	// Load Music

	return true;
}

void App::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen()) {
		m_sceneManager.updateSceneChangeRequests();

		if (m_sceneManager.isSceneStackEmpty()) {
			m_window.close();
		}

		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		while (timeSinceLastUpdate > m_timePerFrame) {
			timeSinceLastUpdate -= m_timePerFrame;

			sf::Event event;
			while (m_window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					m_window.close();
				}
			}
			m_sceneManager.handleEvents(event);
			m_sceneManager.update(m_timePerFrame);
			m_window.clear();
			m_sceneManager.render(m_window);
			m_window.display();
		}
	}
}
