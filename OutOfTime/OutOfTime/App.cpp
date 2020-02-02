#include "App.h"

#include <SFML/Window/Event.hpp>

#include "SharedContext.h"

App::App() : 

	m_window { sf::VideoMode(1600, 1200), "OutOfTime", sf::Style::Close },
	m_sceneManager{ SharedContext {m_texHolder, m_fontHolder, m_soundHolder } },
	m_timePerFrame{ sf::seconds(1.f / 60.f) } {
}

bool App::setup() {
	// Load Textures
	m_texHolder.load(TextureId::kTitle, "Assets/Texture/Backgrounds/title.png");
	m_texHolder.load(TextureId::kGameBackground, "Assets/Texture/Backgrounds/splashScreenTexture.jpg");
	m_texHolder.load(TextureId::kGameOver, "Assets/Texture/Backgrounds/title.png");

	m_texHolder.load(TextureId::kBSOne, "Assets/Texture/BalanceSpring/BalanceSpringSet1.png");
	m_texHolder.load(TextureId::kBSTwo, "Assets/Texture/BalanceSpring/BalanceSpringSet2.png");
	m_texHolder.load(TextureId::kBSThree, "Assets/Texture/BalanceSpring/BalanceSpringSet3.png");
	m_texHolder.load(TextureId::kBSFour, "Assets/Texture/BalanceSpring/BalanceSpringSet4.png");

	m_texHolder.load(TextureId::kCWOne, "Assets/Texture/CentreWheel/SecondGearSet1.png");
	m_texHolder.load(TextureId::kCWTwo, "Assets/Texture/CentreWheel/SecondGearSet2.png");
	m_texHolder.load(TextureId::kCWThree, "Assets/Texture/CentreWheel/SecondGearSet3.png");
	m_texHolder.load(TextureId::kCWFour, "Assets/Texture/CentreWheel/SecondGearSet4.png");

	m_texHolder.load(TextureId::kFWOne, "Assets/Texture/FourthWheel/FourthWheelSet1.png");
	m_texHolder.load(TextureId::kFWTwo, "Assets/Texture/FourthWheel/FourthWheelSet2.png");
	m_texHolder.load(TextureId::kFWThree, "Assets/Texture/FourthWheel/FourthWheelSet3.png");
	m_texHolder.load(TextureId::kFWFour, "Assets/Texture/FourthWheel/FourthWheelSet4.png");

	m_texHolder.load(TextureId::kMSOne, "Assets/Texture/MainSpring/MainSpringSet1.png");
	m_texHolder.load(TextureId::kMSTwo, "Assets/Texture/MainSpring/MainSpringSet2.png");
	m_texHolder.load(TextureId::kMSThree, "Assets/Texture/MainSpring/MainSpringSet3.png");
	m_texHolder.load(TextureId::kMSFour, "Assets/Texture/MainSpring/MainSpringSet4.png");

	m_texHolder.load(TextureId::kTWOne, "Assets/Texture/ThirdWheel/ThirdWheelSet1.png");
	m_texHolder.load(TextureId::kTWTwo, "Assets/Texture/ThirdWheel/ThirdWheelSet2.png");
	m_texHolder.load(TextureId::kTWThree, "Assets/Texture/ThirdWheel/ThirdWheelSet3.png");
	m_texHolder.load(TextureId::kTWFour, "Assets/Texture/ThirdWheel/ThirdWheelSet4.png");


	// Load Font
	m_fontHolder.load(FontId::kRoboto, "Assets/Fonts/MOD20.TTF");
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
