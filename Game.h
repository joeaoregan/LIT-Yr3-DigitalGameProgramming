// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Logo.h"		// Draw Game Logo
#include <iostream>
#include <list>			// list of GameObjects
#include <windows.h>	// for coloured text
#include <iomanip>		// add fill at start of coloured characters
#include <conio.h>		// pause

class Game
{
public:
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
	void drawGrid();			// Draw the grid to display game object positions
	void ClearScreen();			// Clear the screen -- borrowed code
	void displayHealthBars();	// Display the players current health
	void calcHealthBar(int, char*);	// Display the players current health
	void LoopCounter();			// Display number of times game has looped
	int GameOver();				// Display Game Over message

	// Colour Stuff
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	enum direction { North = 0, South, East, West };
	enum result { Win = 0, Lose, Undecided };
	enum objects { Player = 0, E1, E2, E3, E4 };
};

#endif
