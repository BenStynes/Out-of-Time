#include "Gear.h"

Gear::Gear() :
	m_gearType {GearType::kGearA},
	m_pos{sf::Vector2f{0.f, 0.f}}
{
}

void Gear::setPosition(sf::Vector2f newPoint)
{
	m_pos = newPoint;
}

sf::Vector2f Gear::getPosition()
{
	return m_pos;
}



void Gear::setGearType(GearType gearType)
{
	m_gearType = gearType;
}

Gear::GearType Gear::getGearType()
{
	return GearType();
}


void Gear::initialise(sf::Vector2f newPos, const sf::Texture& newTexture, GearType newGearType)
{
	m_pos = newPos;
	m_sprite.setTexture(newTexture);
	m_gearType = newGearType;
}
