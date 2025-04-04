#include "Ball.h" //importing the member declarations

Ball::Ball(float startX, float startY)
{
	m_Position.x=startX; //set the horizontal position
	m_Position.y=startY; //set the vertical position //x y came from Vector2f
	
	m_Shape.setRadius(20); //Define ball size (50x5)
	m_Shape.setPosition(m_Position); //set position on screen
}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds(); //return the 4 coordinates but when u create a sprite u use local bounds to get untransformed height & width
}

CircleShape Ball::getShape()
{
	return m_Shape; //returns the shape itself
}

void Ball::reboundSides()
{
	m_directionX = -m_directionX;
}

void Ball::reboundBatOrTop()
{
	m_directionY = -m_directionY;
}

void Ball::reboundBottom()
{
	m_Position.x = 1920/2 - 20;
	m_Position.y=0;
	//m_directionY = -m_directionY; //reverse vertical direction
}

void Ball::update(Time dt)
{
	//update ball position
	m_Position.y += m_directionY*m_Speed*dt.asSeconds();
	m_Position.x += m_directionX*m_Speed*dt.asSeconds();
	
	//move the ball
	m_Shape.setPosition(m_Position);
}
