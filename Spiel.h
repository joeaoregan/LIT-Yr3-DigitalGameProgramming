/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment
*/
/*	2016-12-04:
	Added a hint to get key when Enemy is killed
	Added function getStory() to get call the function required for 
	each game text section.
	Moved coloured text to Spiel decreasing number of lines in Game
	Added friend functions to calculate and display the players stats for skill,
	strength, and luck

	2016-11-30:
	As the amount of dialogue int the game was starting to build up,
	I thought it was best to separate it out into it's own Class.
	In this file is most of the "story" in the game.

	Any prompts the player may receive to interact with, or from
	interacting with other game objects is to be dumped in here
	in no particular order. As I've already the story for level 1
	done, I suppose it would be for the best to sort it by level.

	I changed the orignal class name from JibberJabber to Gab, actually
	no I'm going to call it Spiel. It definitely needs to be a shorter
	name in any case.
*/
#ifndef SPIEL_H
#define SPIEL_H

#include "Logo.h"					// Draw Game Logo
#include <iostream>
#include <windows.h>				// for coloured text
#include <cstdlib>					// For Random Numbers
#include <ctime>					// For Random Numbers

class Spiel
{
public:
	Logo logo;						// Draw the game logos

	/*	Story
		A story is output at the beginning of level 1
		In the story the player also has stats for luck, strength, and skill set
		using randomly generated numbers
	*/
	void getStory(int s);			// Get the story required
	void l1Story1();				// Text parts 1 to 4 shown with level background
	void l1Story2();
	void l1Story3();
	void l1Story4();
	void l1Story5();				// Text parts 5 and 6 shown with map background
	void l1Story6();

	/* Level 2 Story */
	void l2Story1();				// Story at beginning of level 2

	/*	Hints
		After a certain number of game loops or, after interacting with certain game objects
		hints are dropped, so the player knows what they need to do next
	*/
	void hintLamp1();		// Hints to check out the lamp that is different
	void hintLamp2();
	void hintSword();		// After the player has talked to the guard & picked up the lamp, he reveals a sword
	void hintGuard();		// When the player gets the lamp & hasn't already talked to the guard, pointed in guards direction
	void hintGuardSpeed();	// Hint to the player that the guard speeds up at night time to keep warm
	void hintL2Lamps();		// LEVEL 2: Hint to the player to use the lamp he is carrying to light the wall lamps

	/*	Interactions
		Occur when the player occupies the same coordinates on the map as other game objets that can be interacted with
	*/
	void interactionL1Guard1();		// Interact with the guard, try and negotiate an escape
	void interactionL1Guard2();		// Interact with the guard, realise you will need to find a weapon
	void interactionSword();		// Player finds the sword, once he has interacted with the guard, and collected the lamp
	void interactionLamp();			// The player collects a Lamp
	void interactionTreasureChest();	// The player opens a treasure chest
	void interactionKey();			// Player picks up the key when the guard is dead
		
	void l1Complete();				// Level Complete - message displayed
	void l1CompleteKey();			// Level 1 complete - use key to exit dungeon message

	// Battle
	void battleBegin();				// Enemy throws the first blow
	void battle1();
	void battle2();
	
	void playerMovementInfo();		// Player Movement information is displayed on screen
	
	friend void ClearScreen();		// Friend function to clear screen, shared with & declared in Game class

	/*	Random Stats
		Friend functions are used to calculate the values for the players stats
		These values are then returned to the Game class, to update the existing values
	*/
	friend int wizardLuck(int luck);
	friend int wizardStrength(int strength);
	friend int wizardSkill(int skill);
	friend void displayStats(int skill, int strength, int luck);
	friend int choosePotion();

	// Colour Stuff
	HANDLE hstdinSp = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdoutSp = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;					// Keep track of original colours
};

#endif