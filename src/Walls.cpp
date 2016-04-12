#include <GameState.h>
#include <Walls.h>
#include <Player.h>
#include <iostream>

Walls::Walls() 
{
	texture.loadFromFile("../images/WallTexture.png"); 
	texture.setRepeated(true);

	//wall1.setFillColor(color);	
	wall1.setSize(sf::Vector2f(wallWidth, wallHeight));
	wall1.setTexture(&texture, false);
	wall1.setTextureRect(sf::IntRect(0, 0, 256, 256*wallHeight/wallWidth));
	//wall2.setFillColor(color);
	wall2.setSize(sf::Vector2f(wallWidth, wallHeight));
	wall2.setTexture(&texture, false);
	wall2.setTextureRect(sf::IntRect(0, 0, 256, 256*wallHeight/wallWidth));

	
	velocity = sf::Vector2f(-defaultSpeed, 0);

	moveTo(position);	
}

Walls::~Walls()
{

}

bool Walls::checkCollision(Player &player) 
{
	if(player.sprite.getGlobalBounds().intersects(wall1.getGlobalBounds()) || player.sprite.getGlobalBounds().intersects(wall2.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

void Walls::moveTo(sf::Vector2f destination) 
{
	wall1.setPosition(destination.x, destination.y - wallHeight - wallGap / 2); 	
	wall2.setPosition(destination.x, destination.y + wallGap / 2);
}

void Walls::update(float deltaTime, Player &player) 
{
	position = position + velocity * deltaTime;
	moveTo(position);	
	
	
	//Check For Collision with Player
	if(checkCollision(player))
	{
		GameState::playerDead = true;
	}

}

