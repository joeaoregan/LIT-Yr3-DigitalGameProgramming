/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-11-30:
	The Player must have a lamp to find the sword in the darkeness of the dungeon
	If the player has a lamp when he interacts with the enemy the shine of the lamp
	will be reflected on the sword hidden beneath the rushes

	2016-11-29:
	Getter and setter methods added for extra stats such as Skill, Strength, Luck

	2016-11-24:
	The Player must have a sword to defeat the guard
	The Player can only interact with the level 1 enemy if he has no sword
	If the player picks up a sword and adds it to his inventory he can then
	fight the dungeon guard in level 1
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Spiel.h"					// Needed to output player movement information#

// Derived class
class Player : public GameObject
{
public:
	Spiel spiel;					// Create an object of type Spiel to display game text

	Player(int damage = 1);			// Constructor for player (body in cpp)

	virtual void update();			// +/- x & y coords based on speed, deduct from health, reverse if perimiter hit

	// Player Functions
	void moveDirection(int d);		// Choose direction to move Player object from keyboard

	// Player Variables
	int speedDirection;				// Store the direction, and speed for the player

	/*	2016-11-24:
		The Player must have a sword to defeat the guard
		The Player can only interact with the level 1 enemy if he has no sword */
	bool hasSword = false;
	void setHasSword(bool);
	bool getHasSword();

	/*	2016-11-30:
		The Player must have a lamp to find the sword in the darkeness of the dungeon
		If the player has a lamp when he interacts with the enemy the shine of the lamp
		will be reflected on the sword hidden beneath the rushes */
	bool hasLamp = false;
	void setHasLamp(bool);
	bool getHasLamp();

	/* Getter and setter methods for extra stats added for CA2 */
	void setSkill(int skill);
	void setStrength(int strength);
	void setPoxiness(int pox);
	const int getSkill();
	const int getStrength();
	const int getPoxiness();

private:
	int m_Skill;						// CA2 - Skill level for player
	int m_Strength;						// CA2 - Strenght for player
	int m_Poxiness;						// CA2 - Luck attribute for player
};

#endif