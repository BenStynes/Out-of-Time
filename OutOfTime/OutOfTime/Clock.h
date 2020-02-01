#pragma once
#include <SFML/Graphics.hpp>
#include "BaseScene.h"
class Clock
{
public:
	Clock();
	void setUpClock();
	bool checkWinCondition(sf::Vector2f t_pos[], int t_types[]);
	void render(sf::RenderWindow &t_win);
	void changePosition(sf::Vector2f t_mousePos);
	bool checkForpositionOnRelease(sf::Vector2f t_pos[]);
	sf::Vector2f getWinPosition(int t_help);

private:
	sf::Vector2f m_winPositions[4]{};
	sf::Sprite m_clockSprite;
	sf::Texture m_clockTexture;
	int winTypes[5];

};

