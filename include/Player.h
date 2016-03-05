#include <SFML/Graphics.hpp>


class Player
{
public:
//Constructors/Destructors
	Player();
	~Player();



	sf::RectangleShape sprite;
	sf::Vector2f size = sf::Vector2f(25, 25);

	float gravity = 1;
	float jumpVel = 0.5;
	float jumpPause = 0.5;
	float maxSpeed = 1;
	

//Member functions
	void update(float deltaTime);

private:
	/* data */
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Texture texture;
	float timeToNextJump = 0;
};



