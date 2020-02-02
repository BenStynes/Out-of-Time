#include "Clock.h"


Clock::Clock()
{
	setUpClock();
}

void Clock::setUpClock()
{
	m_clockTexture.loadFromFile("Assets/Texture/Base.png");
	m_clockSprite.setTexture(m_clockTexture);

	m_clockSprite.setPosition(400, 300);
	m_clockSprite.setScale(2, 2);
	for (int i = 0; i < 4; i++)
	{
		winTypes[i] = 1;
	}
}

bool Clock::checkWinCondition(sf::Vector2f t_pos[], int t_types[])
{
	for (int i = 0; i < 5; i++)
	{
		if (!(t_pos[i] == m_winPositions[i] && t_types[i] == winTypes[i]))
		{
			return false;

		}

	}


	return true;
}

void Clock::render(sf::RenderWindow &t_win)
{
	t_win.draw(m_clockSprite);


}

void Clock::changePosition(sf::Vector2f t_mousePos)
{
	m_clockSprite.setPosition(t_mousePos);
}

bool Clock::checkForpositionOnRelease(sf::Vector2f t_pos[])
{
	for(int i =0 ; i < 5; i++)
    {
	float distance;
	distance = sqrt(((t_pos[i].x - m_winPositions[i].x) * ((t_pos[i].x - m_winPositions[i].x)) +
		((t_pos[i].y - m_winPositions[i].y) * (t_pos[i].y - m_winPositions[i].y))));


		if(distance < 20 + t_pos[i].x)
		{
			return true;
		}

		if (distance > 20 - t_pos[i].x)
		{
			return true;
		}

		if (distance < 20 + t_pos[i].y)
		{
			return true;
		}

		if (distance > 20 - t_pos[i].y)
		{
			return true;
		}
	}
}

sf::Vector2f Clock::getWinPosition(int t_help)
{
	switch (t_help)
	{
	default:
		break;
	
	case 0:
		return m_winPositions[0];
		break;
	case 1:
		return m_winPositions[1];
		break;
	case 2:
		return m_winPositions[2];
		break;
	case 3:
		return m_winPositions[3];
		break;
	}
}

