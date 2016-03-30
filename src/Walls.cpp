#include <GameState.h>
#include <Walls.h>
#include <Player.h>
#include <iostream>

Walls::Walls() 
{
	wall1.setFillColor(color);	
	wall1.setSize(sf::Vector2f(wallWidth, wallHeight));
	wall2.setFillColor(color);
	wall2.setSize(sf::Vector2f(wallWidth, wallHeight));
	
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

