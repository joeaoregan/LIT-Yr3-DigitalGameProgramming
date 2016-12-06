/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-12-04:
	Added setup function for level 2

	2016-11-30:
	Add random spawn time for treasure chests.  And random items selected to find in them from a fixed list of items
	Generate a random point on the loop counter between 5 and 15 to spawn the treasure chest

	Added game text to a separate class called Spiel as the current Game.cpp was getting too much to
	scroll through for one thing, and I think that's the whole point of being able to use separate files

	Weapon game objects will have different attributes that will be taken into account in the battle function. 
	Weapons with high Strength will inflict more damage on an enemy. While weapons with high Defene will 
	restrict the damage of enemy blows.

	If the player occupies the coordinates of a static game object he can interact with it. 
	This is similar to the battle() function but instead of trying to kill a Game Object, the player decides
	whether to add it to his inventory

	2016-11-29:
	Moved the logo for game to the header file so logos can be used in more than one function

	Added win level condition, so the game doesn't exit the Game Loop when levels are 
	completed, added a condition for each level 1 to 3, and 4 is now game over

	Random stats are assigned to the player for skill, strength and luck

	17-11-2016
	Add extra enemies and game objects to the game
	The player can collect and add weapons, such as swords, and other game objects such as
	lamps and potions for Skill, Strength, Luck, and Health to his inventory
*/

#ifndef GAME_H
#define GAME_H

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Logo.h"		// Draw Game Logo
#include <iostream>
#include <list>			// list of GameObjects
#include <windows.h>	// for coloured text
#include <iomanip>		// add fill at start of coloured characters
#include <conio.h>		// pause
#include <cstdlib>		// For Random Numbers
#include <ctime>		// For Random Numbers
/*	2016-11-30:
	Added game text to a separate class called Spiel as the current
	Game.cpp was getting too much to scroll through for one thing, 
	and I think that's the whole point of being able to use 
	separate files
*/
#include "Spiel.h"
/*	2016-11-30:
	Weapon game objects will have different attributes that will be 
	taken into account in the battle function. Weapons with high
	Strength will inflict more damage on an enemy. While weapons
	with high Defene will restrict the damage of enemy blows.
*/
#include "Weapon.h"
#include "TreasureChest.h"

class Game
{
private:
	/*	17-11-2016
		Add extra enemies and game objects to the game
		The player can collect and add weapons, such as swords, and other game objects such
		as lamps and potions for Skill, Strength, Luck, and Health to his inventory
		CA1:
		Instantiate the game objects
	*/

	//GameObject* pPlayer;
	GameObject* pEnemy1;	// Level 1 Enemy
	GameObject* pEnemy2;	// Level 2 Enemy
	GameObject* pEnemy3;	// Level 3 Enemy
	GameObject* pEnemy4;
	// Added to CA2
	GameObject* pEnemy5;
	GameObject* pEnemy6;
	GameObject* pEnemy7;
	GameObject* pEnemy8;
	GameObject* pEnemy9;
	GameObject* pSword;
	GameObject* pLamp;
	GameObject* pMap;
	GameObject* pKey;
	GameObject* pPotion;

	std::list<GameObject*> listOfGameObjects;	// List of pointers to Player & Enemy GameObjects
	std::list<GameObject*> listOfCollectables;	// List of pointers to Weapon & Power Up GameObjects
	std::list<GameObject*> inventory;			// Inventory: Items player has collected
	std::list<GameObject*>::const_iterator it;

	bool isDayTime;								// CA2 - Decide if it's night or daytime

	int gameState;								// The current game state Undecide/Won/Lost/Level Complete

public:
	// Constructor / Deconstructor
	Game() {}
	~Game() {}

	/*	2016-11-29:
		Moved the logo for game to the header file so logos can be used in more than
		one function
		CA1:
		Create and display game logo 
	*/
	Logo logo;
	/*	2016-11-30:
		Added a separate file to contain the story and interaction text for the game
		So the player is aware of objects that can be interacted with the game will
		drop hints.
		When a player interacts with an object text will be displayed
		And when an important even occurs in a level it can be displayed on screen
	*/
	Spiel spiel;		// Create an object of type Spiel to display game text

	// Required Functions
	void init();		// create the objects & assign each enemy & player unique typeID,
						// health, & x & y coords, max health should be 160
						// speed is between 1 and 4, & place objects on the list
	void draw();		// cycle through enemy & player objects & call draw() for each object
	void update();		// cycle through enemy & player objects & call update() for each object
	void battle();		// if 2 objects occupy same coords declare a battle must take place
						// The object with higher health wins. The loser has health set to 0
	void info();		// Cycle through enemy & player objects & call info() for each object
	void clean();		// Remove any object from the list with 0 Health (isAlive)

	// Extra nonsense
	void drawGrid();					// Draw the grid to display game object positions
	friend void ClearScreen();			// Clear the screen -- borrowed code
	friend int wizardLuck(int luck);	// Function to randomly generate Luck
	friend int wizardStrength(int strength);	// Randomly generate strength
	friend int wizardSkill(int skill);			// Randomly generate skill
	friend void displayStats(int skill, int strength, int luck);	// display luck, strength, and skill stats
	friend int choosePotion();			// Player can add 1 stat potion to his inventory

	void displayStatsBars();		// CA2 - Display the players current skill and luck, and health for all active objects
	void calcHealthBar(int, char*);	// CA2 - Calculate a Game Objects current health
	void calcSkillBar();			// CA2 - Calculate the players skill level
	void calcStrengthBar();			// CA2 - Calculate the players strength level
	void calcPoxBar();				// CA2 - Calculate the players poxiness (luck)
	void LoopCounter();				// Display number of times game has looped
	int  GameOver();				// Display Game Over message
	int getGameResult();			// Get the current state of the game
	void setGameResult(int result);	// Set the current state of the game
	
	/*	2016-11-30:
		If the player occupies the coordinates of a static game object
		He can interact with it. This is similar to the battle() function
		but instead of trying to kill a Game Object, the player decides
		whether to add it to his inventory
	*/
	void interact();
	/*
		If the player has interacted with the Level 1 enemy guarding the dungeon
		The sword will magically appear on the screen 
	*/
	bool l1EnemyInteraction;		// Flag if Player has interacted with Level 1 Enemy
	bool L2LightsOn;				// Lights on or off in level 2
	int treasureBarSize;			// 2016-12-01 size of the treasure bar lifespan timer


	void addToInventory();			// Pick up a weapon / power
	void setDayTime(bool day);		// set day or night time
	bool getDaylight();				// Find out if it's day time or night time
	void level1Setup();				// CA2 - 2016-11-29 random stats are assigned to the player for skill, strength and luck
	void level2Setup();				// Set up the beginning of level 2

	void uniqueCoords(GameObject* objectToCheck);	// Generate unique starting coordinates for all objects

	/*	2016-11-30:
		Add random spawn time for treasure chests. 
		And random items selected to find in them from a fixed list of items
	*/
	int treasureSpawnTime;			// Generate a random point on the loop counter between 5 and 15 to spawn the treasure chest
	int treasureKillTime;			// Add the lifespan to the spawn time & remove after this number is reached on the loop counter
	bool revealL2Map;				// Decides to reveal the next part of the map, when finding a map in the treasure chest
	bool hasKey;					// Player has collected the key

	/* Level 2 */
	bool knightsAwake;				// if all 4 sets of lights are on, wake up the guards
	bool lamp1Lit;					// Turn on the north wall lights
	bool lamp2Lit;					// Turn on the south wall lights
	bool lamp3Lit;					// Turn on the west wall lights
	bool lamp4Lit;					// Turn on the east wall lights
	
	//static int loopCount;
	//enum direction { North = 0, South, East, West };								// Previously used direcion enumerated list 
	enum directionName { SW = 1, South, SE, West, East = 6, NW, North, NE };		// Use readable values for directions
	enum result { Win = 0, Lose, Undecided, L1Complete, L2Complete, L3Complete };	// 2016-11-29 CA2 Added win level condition
	enum objects { Player = 0, E1, E2, E3, E4 };									// Game objects enumerated list
	enum lampsL2 { lamp1 = 1, lamp2, lamp3, lamp4, lamp5, lamp6, lamp7 };			// Level 2 Lamps enumerated list

	// Colour Stuff
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
};

#endif
