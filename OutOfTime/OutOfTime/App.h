#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "SceneManager.h"
#include "ResourceHolder.h"

class App {
public:
	App();
	bool setup();
	void run();

private:
	const sf::Time m_timePerFrame;
	sf::RenderWindow m_window;
	SceneManager m_sceneManager;

	ResourceHolder<TextureId, sf::Texture> m_texHolder;
	ResourceHolder<FontId,    sf::Font>    m_fontHolder;
	ResourceHolder<SoundId,   sf::Sound>   m_soundHolder;
};

