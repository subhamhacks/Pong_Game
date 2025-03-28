#include "Bat.h" //importing the member declarations

Bat::Bat(float startX, float startY)
{
	m_Position.x=startX; //set the horizontal position
	m_Position.y=startY; //set the vertical position //x y came from Vector2f
	
	m_Shape.setSize(sf::Vector2f(200,50)); //Define bat size (50x5)
	m_Shape.setPosition(m_Position); //set position on screen
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds(); //return the 4 coordinates
}

RectangleShape Bat::getShape()
{
	return m_Shape; //returns the shape itself
}

void Bat::moveLeft()
{
	m_MovingLeft=true;
}

void Bat::moveRight()
{
	m_MovingRight=true;
}

void Bat::stopLeft()
{
	m_MovingLeft=false;
}

void Bat::stopRight()
{
	m_MovingRight=false;
}

void Bat::update(Time dt)
{
	if(m_MovingLeft && (m_Position.x>0))
	{
		m_Position.x-=m_Speed*dt.asSeconds();//moves left
	}
	if(m_MovingRight && (m_Position.x<=1920-200))
	{
		m_Position.x+=m_Speed*dt.asSeconds();//moves right
	}
	
	m_Shape.setPosition(m_Position); //updates bat position
}
