#include <SFML/Graphics.hpp>


class Player
{
public:
//Constructors/Destructors
	Player();
	~Player();



	sf::RectangleShape sprite;
	sf::Vector2f size = sf::Vector2f(25, 25);

	float gravity = 800;
	float jumpVel = 300;
	float jumpPause = 0.3;
	float maxSpeed = 500;
	

//Member functions
	void update(float deltaTime);

private:
	/* data */
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Texture texture;
	float timeToNextJump = 0;
};



