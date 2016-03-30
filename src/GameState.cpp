#include <GameState.h>


namespace GameState 
{
	bool playerDead = false;	
	int score = 0;


	void increaseScore(int value) {score += value;}
	void resetScore() {setScore(0);}
	


	void setScore(int value) 
	{
		score = value;
	}

} /* namespace GameState */
