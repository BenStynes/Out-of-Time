#pragma once

#include <SFML/Graphics.hpp>
class Gear
{
public:
	void setPosition(sf::Vector2f newPoint);
	sf::Vector2f getPosition();

	void setSetNumber(int newSetNum);
	int getSetNumber();

	void setGearType(sf::String newType);
	sf::String getGearType();

private:
	sf::Vector2f position{ 0.0f, 0.0f };// Position
	int setNumber{ 0 };// What set it belongs to
	sf::String gearType{ "" };// What gear type it is
};

