#include <SFML/Graphics.hpp>
#include <iostream>
#include <Player.h>
#include <Walls.h>
#include <GameState.h>

#include <string>
#include <sstream>

namespace std
{
    template <typename T>
    std::string to_string(T input)
    {
        std::ostringstream buffer;
        buffer << input;
        return buffer.str();
    }
}



int main(void)
{
	srand(time(NULL));

	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString(std::to_string(GameState::score));
	scoreText.setCharacterSize(24);
	scoreText.setColor(sf::Color::White);
	scoreText.setPosition(-380,-280);

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
		window.clear(sf::Color(50, 100, 255));


		//Update
		player.update(deltaTime.asSeconds());
		walls.update(deltaTime.asSeconds(), player);

		//Draw Calls
		window.draw(player.sprite);
		window.draw(walls.wall1);
		window.draw(walls.wall2);
		window.draw(scoreText);

		//Game Logic
		if(walls.position.x < -450)
		{
			float offset = rand() % 300 - 150;
			walls.position = sf::Vector2f(400, offset);
			GameState::setScore(GameState::score + 1);
			scoreText.setString(std::to_string(GameState::score));
		}

		if(GameState::playerDead == true)
		{
			player.position = sf::Vector2f(0, 0);
			walls.position = sf::Vector2f(400, 0);
			GameState::playerDead = false;
			GameState::resetScore();
			scoreText.setString(std::to_string(GameState::score));
		}



		//Display Window
		window.display();


	}
	return 0;
}
