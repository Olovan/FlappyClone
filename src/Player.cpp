#include <Player.h>
#include <Utility.h>
#include <iostream>



Player::Player()
{
	texture.loadFromFile("../Images/Ghost1.png");

	sprite.setPosition(sf::Vector2f(0,0));
	sprite.setSize(size);

	sprite.setTexture(&texture, false);
}

Player::~Player()
{

}

void Player::update(float deltaTime) 
{
	timeToNextJump -= deltaTime;
	position = position + velocity * deltaTime;
	velocity = sf::Vector2f(velocity.x, velocity.y + (gravity * deltaTime));

	velocity.y = range(velocity.y, -maxSpeed, maxSpeed); 
	position.y = range(position.y, -300.0f, 300.0f - size.y);

	sprite.setPosition(position);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeToNextJump <= 0)
	{
		velocity = sf::Vector2f(velocity.x, -jumpVel);
		timeToNextJump = jumpPause;
		//std::cout << "Jump" << std::endl;
	}	

}



