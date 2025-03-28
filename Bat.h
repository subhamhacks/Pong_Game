#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_Position; //2d vector with floating point coordinates ( store (x, y) position of Bat )
	
	RectangleShape m_Shape; //graphical representation of Bat
	
public:
	Bat(float startX, float startY); //stores current position of Bat
	
	FloatRect getPosition(); //retrieves current X, Y coordinate of the bat
	
	RectangleShape getShape(); //gives the shape of the bat	
};
