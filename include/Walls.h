#include <SFML/Graphics.hpp>


class Player;

class Walls
{
public:
	Walls();
	~Walls();

	sf::Color color = sf::Color::Red;
	float wallHeight = 600;
	float wallWidth = 50;
	float wallGap = 100;
	float defaultSpeed = 300.0f;


	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::RectangleShape wall1;
	sf::RectangleShape wall2;


	bool checkCollision(Player &player);
	void moveTo(sf::Vector2f destination);
	void update(float deltaTime, Player &player);
	

		

private:
	/* data */
};
