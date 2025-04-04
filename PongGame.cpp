#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Bat.h" //Bat.cpp bi chaliba

#include "Ball.h"

using namespace sf;

int main()
{

	VideoMode vm(1920, 1080); // OBJECT vm CREATED

	RenderWindow window(vm, "PONG GAME"); // Add 3rd field <Style::Fullscreem> to open fullscreen by default

	View view(FloatRect(0, 0, 1920, 1080)); // Claculates the coordinates according to the main resolution
	window.setView(view);					// (left, top, width, height)
	
	Bat bat(1920/2,1080-20);
	Ball ball(1920/2 - 20,0);

	Clock clock;
	
	int score = 0;
	int lives = 3;
	
	Text messageText;
	Text GAMEOVER;
	Font font;
	font.loadFromFile("font/DIGII.TTF");
	
	messageText.setFont(font);
	messageText.setCharacterSize(36);
	messageText.setFillColor(Color::White);
	messageText.setPosition(20,20);
	GAMEOVER.setFont(font);
	GAMEOVER.setString("GAME OVER!!!");
	GAMEOVER.setFillColor(Color::Red);
	GAMEOVER.setCharacterSize(130);
	FloatRect textRect = GAMEOVER.getLocalBounds();
     GAMEOVER.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	GAMEOVER.setPosition(960, 540);
	
	//gaming loop
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) 
			{								 
				window.close();				
			}	
			
		} 

		if (Keyboard::isKeyPressed(Keyboard::Escape)) 
		{									
			window.close();							  
		} 
		
		if (Keyboard::isKeyPressed(Keyboard::Right)) 
		{									
			bat.moveRight();		  
		} 
		else
		{
			bat.stopRight();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{									
			bat.moveLeft(); 
		} 
		else
		{
			bat.stopLeft();
		}
		//collision detectionn
		if(ball.getPosition().left < 0 || ball.getPosition().left + 2*20 > 1920)
		{
			ball.reboundSides();
		}
		
		if(ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();
			score++;
		}
		
		if (ball.getPosition().intersects(bat.getPosition()))
		{
		    ball.reboundBatOrTop();

		}
		
		if (ball.getPosition().top + 40 > 1080)
		{
			ball.reboundBottom();
			lives--;
			if(lives<1)
			{
				std::cout << "GAME OVER!!!" << std::endl;
				score = 0;
				lives = 3;
			}
		}
		
		Time dt=clock.restart();
		
		bat.update(dt);
		ball.update(dt);
		
		std::stringstream ss; //used to make text string dynamically
		ss << "Score:" << score << "\nLives:" << lives ;
		messageText.setString(ss.str());
		
		window.clear();
		window.draw(messageText);
		window.draw(ball.getShape());
		window.draw(bat.getShape());
		window.display();
		 
	}	
return 0;
}
