/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-12-04:
	Moved the player direction info text to the Spiel Class with the other game text
	2016-11-30:
	Teleportation from quadrant to quadrant of the room the player is in on the map.
	If speed entered is 69, teleport the player to the opposite quadrant of the map
	e.g South-West goes to North-East, and North-West goes to South East

	The getHasLamp function is used to return the value of hasLamp, indicating whether
	a player has a Lamp game object in their inventory

	a setter function is added to set the value of the boolean variable hasLamp
	This function is used to set the hasLamp attribute of the Player object
	to true or false, based on whether he is carrying, or has dropped a Lamp

	2016-11-29:
	Updated the moveDirection function to set the players speed to the speed entered
	and add the speed with getSpeed() instead of the variable entered.
	
	Extra getter and setter methods required for new stats included in such as
	Skill, Strength and Luck

	2016-11-27:
	The moveDirection function moves a Player object in the required direction
	It also sets the direction attribute of the Player (m_direction)

	Direction is used to draw the sword on the grid, to give a visual
	indication of the direction the player is facing, and is used to
	calculate the rebound direction when the player hits the boundary
	
	Changed the layout of the direction information to suit the new wider screen size.

	2016-11-24:
	Added a setHasSword function to indicate if the player has a sword or not and set the value
	This function is used to set the hasSword attribute of the Player object
	to true or false, based on whether he is carrying, or has dropped a sword

	a get function getHasSword is used to return the value of hasSword, indicating whether
	a player has a Sword game object in their inventory
*/

#include "Player.h"

Player::Player(int damage) :
	GameObject(damage)									// Call base class constructor with argument
{}

// +/- x and y coords based on speed, deduct from health, reverse if perimiter hit
void Player::update() {									// Override base class member function
	spiel.playerMovementInfo();							// Display the player movement info
						
	std::cin >> speedDirection;							// Take in the direction the player is to move
	//if (speedDirection < 0 && speedDirection < 50)	// 2016-11-29 CA2 - Check range of numbers
	//if (!std::cin.fail())								// 2016-11-29 CA2 - Check range of numbers
	//	moveDirection(speedDirection);
	//else
		//std::cout << "not an integer";
	moveDirection(speedDirection);
	
	GameObject::update();								// Call base class member function 

	setHealth(getHealth() - getSpeed() * getDamage());	// Deduct from health: current speed * damage
}


/*	2016-11-29:
	Updated the function to set the players speed to the speed entered
	and add the speed with getSpeed() instead of the variable entered.
	2016-11-27: 
	This function moves a Player object in the required direction
	It also sets the direction attribute of the Player (m_direction)
	Direction is used to draw the sword on the grid, to give a visual
	indication of the direction the player is facing, and is used to 
	calculate the rebound direction when the player hits the boundary
*/
void Player::moveDirection(int speedDirection)
{
	int centrePoint = 12;

	/*	2016-11-30
		Teleportation from quadrant to quadrant of the room the player is in on the map.
		If speed entered is 69, teleport the player to the opposite quadrant of the map
		e.g South-West goes to North-East, and North-West goes to South East
	*/
	if (speedDirection == 69) {
		if (getX() < centrePoint && getY() > centrePoint) {			// SW quadrant of map
			setX(centrePoint + (centrePoint - getX()));
			setY(centrePoint - (getY() - centrePoint));
		}
		else if (getX() < centrePoint && getY() < centrePoint) {	// NW quadrant of map
			setX(centrePoint + (centrePoint - getX()));
			setY(centrePoint + (centrePoint - getY()));
		}
		else if (getX() > centrePoint && getY() < centrePoint) {	// NE quadrant of map
			setX(centrePoint - (getX() - centrePoint));
			setY(centrePoint + (centrePoint - getY()));
		}
		else if (getX() > centrePoint && getY() > centrePoint) {	// SE quadrant of map
			setX(centrePoint - (getX() - centrePoint));
			setY(centrePoint - (getY() - centrePoint));
		}
	}
	else {
		int newspeed = speedDirection / 10;		// Set new speed to the remainder		
		setSpeed(newspeed);						// 2016-11-29 CA2 - set the players speed
		speedDirection = speedDirection % 10;	// Set direction to the modulus (number from 0 to 9)

		switch (speedDirection) {
		case SW:								// South-West, #1
			setX(getX() - getSpeed());			// Left
			setY(getY() + getSpeed());			// Down
			setDirection(SW);
			break;
		case South:								// South, #2
			setY(getY() + getSpeed());			// Down
			setDirection(South);
			break;
		case SE:								// South-East, #3
			setX(getX() + getSpeed());			// Right
			setY(getY() + getSpeed());			// Down
			setDirection(SE);
			break;
		case West:								// West, #4
			setX(getX() - getSpeed());			// Left
			setDirection(West);
			break;
		case East:								// East, #6
			setX(getX() + getSpeed());			// Right
			setDirection(East);
			break;
		case NW:								// North-West, #7
			setX(getX() - getSpeed());			// Left
			setY(getY() - getSpeed());			// Up
			setDirection(NW);
			break;
		case North:								// North, #8
			setY(getY() - getSpeed());			// Up
			setDirection(North);
			break;
		case NE:								// North-East, #9
			setX(getX() + getSpeed());			// Right
			setY(getY() - getSpeed());			// Up
			setDirection(NE);
			break;
		case 0:
			info();
		default:
			break;
		}
	}
}

/*	2016-11-24:
    This function is used to set the hasSword attribute of the Player object 
    to true or false, based on whether he is carrying, or has dropped a sword
*/
void Player::setHasSword(bool x)
{
	hasSword = x;
}
/*
	2016-11-24:
	This function is used to return the value of hasSword, indicating whether
	a player has a Sword game object in their inventory
*/
bool Player::getHasSword()
{
	return hasSword;
}

/*	2016-11-30:
	This function is used to return the value of hasLamp, indicating whether
	a player has a Lamp game object in their inventory
	*/
bool Player::getHasLamp()
{
	return hasLamp;
}

/*	2016-11-24:
	This function is used to set the hasLamp attribute of the Player object
	to true or false, based on whether he is carrying, or has dropped a Lamp
*/
void Player::setHasLamp(bool x)
{
	hasLamp = x;
}

/*	2016-11-29
	Extra getter and setter methods required for new stats included in CA2 
*/
void Player::setSkill(int skill) {
	m_Skill = skill;
}
void Player:: setStrength(int strength) {
	m_Strength = strength;
}
void Player::setPoxiness(int pox) {
	m_Poxiness = pox;
}
const int Player::getSkill() {
	return m_Skill;
}
const int Player::getStrength() {
	return m_Strength;
}
const int Player::getPoxiness() {
	return m_Poxiness;
}