// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <windows.h>					// Coloured text
#include <iomanip>						// Add fill at start of coloured characters

#include "GameObject.h"

// Derived class
class Player : public GameObject
{
public:
	Player(int damage = 2);				// Constructor for player
	virtual void update();				// +/- x and y coords based on speed, deduct from health, reverse if perimiter hit
	void plDirectionInfo();				// Display information on directional movement for Player
	void moveDirection(int d);			// Choose direction to move Player object from keyboard

	int speedDirection;					// Store the direction, and speed for the player

	// Colour Stuff
	HANDLE hstdinPl = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdoutPl = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif