#include <Walls.h>

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
	
}

void Walls::moveTo(sf::Vector2f destination) 
{
	wall1.setPosition(destination.x, destination.y - wallHeight - wallGap / 2); 	
	wall2.setPosition(destination.x, destination.y + wallGap / 2);
}

void Walls::update(float deltaTime) 
{
	position = position + velocity * deltaTime;
	moveTo(position);	
}

