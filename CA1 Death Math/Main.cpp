// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#include "Game.h"

#define GAME_LOOPS 20		// Number of times to loop the game

int main()
{
	int loopNum = 0;
	int finished = 2;
	
	Game game;				// Create a game object
	game.init();			// Call the Game Class init function
	
	// game loop	
	while(loopNum < GAME_LOOPS) // loop until 20
	{						
		loopNum++;			// Start loop at 1
		
		game.draw();		// Call draw() for each object
		game.update();		// Move Game Objects
		game.battle();		// If 2 objects occups same coords - fight
		game.info();		// Call info() for each object
		game.clean();		// Remove Game Objects from list with 0 health
		finished = game.GameOver();
		if (finished != 2) break;	// Exit loop if game is won or lost
	}

	game.info();			// Print Game Object details one more time

	return 0;
}