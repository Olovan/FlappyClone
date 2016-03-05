#include <SFML/Graphics.hpp>
#include <iostream>
#include <Player.h>


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800,600), "FlappyClone", sf::Style::Close);
	sf::View view(sf::Vector2f(0,0), sf::Vector2f(800, 600));
	window.setView(view);
	Player player;

	
	sf::Clock clock;
	sf::Time previousTime;
	while(window.isOpen())
	{
		//Get Time Elapsed
		sf::Time deltaTime = clock.getElapsedTime() - previousTime;
		previousTime= clock.getElapsedTime();	
		//Poll Events
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		//Clear Window
		window.clear();


		//Update
		player.update(deltaTime.asSeconds());

		//Draw Calls
		window.draw(player.sprite);	



		//Display Window
		window.display();
				

	}
	return 0;
}
