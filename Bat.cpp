#include "Bat.h" //importing the member declarations

Bat::Bat(float startX, float startY)
{
	m_Position.x=startX; //set the horizontal position
	m_Position.y=startY; //set the vertical position //x y came from Vector2f
	
	m_Shape.setSize(sf::Vector2f(50,5)); //Define bat size (50x5)
	m_Shape.setPosition(m_Position); //set position on screen
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds(); //return the 4 coordinates
}

RectangleShape Bat::getShape()
{
	return m_Shape;
}
