/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/	
/*	2016-11-30:
	Added an interact function, so player can interact with objects in the map
	such as lamps, swords, and also interact with the enemy.
	If the player occupies the coordinates of a static game object
	He can interact with it. This is similar to the battle() function
	but instead of trying to kill a Game Object, the player decides
	whether to add it to his inventory
	addToInventory() is now called from the newer interact function.
	2016-11-29:
	Changed the condition for exiting the game loop to include completing levels
	The conditions are now, win, lose, ongoing, complete level 1, complete level 2 etc
	2016-11-27:
	The game loops until the game over condition has been satisfied
	Added an addToInventory() function for objects the player can pick up
	CA1:
	The game loops 20 times, or until the game over condition has been satisfied
*/

#include "Game.h"

//#define GAME_LOOPS 20		// Number of times to loop the game

int main()
{
	srand(static_cast<unsigned int>(time(0)));	// Seed random number

	int loopNum = 0;
	int finished = 2;
	
	Game game;				// Create a game object
	game.init();			// Call the Game Class init function
	
	// game loop	
	//while (loopNum < GAME_LOOPS) // loop until 20
	while (finished >= 2 && finished < 5) // CA2 - Loop until game over condition has been triggered
	{						
		loopNum++;			// Start loop at 1
		
		game.draw();		// Call draw() for each object
		game.update();		// Move Game Objects
		/*	2016-11-30:
			If the player occupies the coordinates of a static game object
			He can interact with it. This is similar to the battle() function
			but instead of trying to kill a Game Object, the player decides
			whether to add it to his inventory
		*/
		game.interact();
		game.battle();		// If 2 objects occups same coords - fight
		//game.addToInventory();
		game.info();		// Call info() for each object
		game.clean();		// Remove Game Objects from list with 0 health
		finished = game.GameOver();
		//finished = game.getGameResult();
		if (finished < 2 || finished > 5) break;	// Exit loop if game is won or lost
	}

	game.info();			// Print Game Object details one more time

	return 0;
}