#include "Gear.h"

void Gear::setPosition(sf::Vector2f newPoint)
{
	position = newPoint;
}

sf::Vector2f Gear::getPosition()
{
	return position;
}

void Gear::setSetNumber(int newSetNum)
{
	setNumber = newSetNum;
}

int Gear::getSetNumber()
{
	return setNumber;
}

void Gear::setGearType(sf::String newType)
{
	gearType = newType;
}

sf::String Gear::getGearType()
{
	return gearType;
}