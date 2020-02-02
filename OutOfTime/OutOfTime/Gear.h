#pragma once


#include <SFML/Graphics.hpp>
class Gear
{
public:

	Gear();

	enum class GearType {
		kNone,
		kGearA, 
		kGearB
	};

	void setPosition(sf::Vector2f newPoint);
	sf::Vector2f getPosition();

	void setGearType(GearType gearType);
	GearType getGearType();

	void initialise(sf::Vector2f newPos, const sf::Texture& newTexture, GearType gearType);

private:
	GearType m_gearType;
	sf::Vector2f m_pos;
	sf::Sprite m_sprite;
};

