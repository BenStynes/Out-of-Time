#include "App.h"

#include <SFML/Window/Event.hpp>

#include "SharedContext.h"

App::App() : 
	m_window { sf::VideoMode(800, 600), "OutOfTime", sf::Style::Close },
	m_sceneManager{ SharedContext { m_texHolder, m_fontHolder, m_musicHolder, m_soundHolder } },
	m_timePerFrame{ sf::seconds(1.f / 60.f) } {
}

bool App::setup() {
	// Load Textures
	m_texHolder.load(TextureId::kBase, "Assets/Texture/Backgrounds/title.png");
	
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
