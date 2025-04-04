#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position; //2d vector with floating point coordinates ( store (x, y) position of Ball )
	
	CircleShape m_Shape; //graphical representation of Ball
	
	float m_Speed=2000.0;//controls ball speed(pixel/sec)
	
	float m_directionX=0.2;//ball moves left & right
	float m_directionY=0.2;//ball moves downwards
public:
	Ball(float startX, float startY); //stores current position of Ball
	
	FloatRect getPosition(); //retrieves current X, Y coordinate of the ball
	
	CircleShape getShape(); //gives the shape of the ball	
	
	void reboundSides(); //called when ball hits left OR right wall
	
	void reboundBatOrTop(); //when ball hits bat or top of window
	
	void reboundBottom(); //hits bottom & GAME OVER
	
	void update(Time dt); 
};
