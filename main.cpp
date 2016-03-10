#include <SFML/Graphics.hpp>
#include <iostream>
#include <Player.h>
#include <Walls.h>
#include <GameState.h>


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800,600), "FlappyClone", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::View view(sf::Vector2f(0,0), sf::Vector2f(800, 600));
	window.setView(view);
	Player player;
	Walls walls;

	
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
		walls.update(deltaTime.asSeconds(), player);

		//Draw Calls
		window.draw(player.sprite);	
		window.draw(walls.wall1);
		window.draw(walls.wall2);

		//Game Logic
		if(walls.position.x < -450)
			walls.position = sf::Vector2f(400, 0);
		if(GameState::playerDead == true)
		{
			player.position = sf::Vector2f(0, 0);
			walls.position = sf::Vector2f(400, 0);
			GameState::playerDead = false;
		}

		

		//Display Window
		window.display();
				

	}
	return 0;
}
