#include <SFML/Graphics.hpp>
#include <iostream>


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800,600), "FlappyClone", sf::Style::Close);
	
	while(window.isOpen())
	{
		//Poll Events
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		//Clear Window
		window.clear();



		//Draw Calls



		//Display Window
		window.display();
				

	}
	return 0;
}
