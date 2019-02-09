/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-11-28:
	Enemy objects update function now allows enemies to move in 
	8 Different directions South-West, South, South-East, West,
	East, North-West, North, and North-East. Direction is set at
	Random when the Enemy is spawned. And changes direction if 
	the enemy rebounds off the perimeter.
	CA1:
	Moves Enemy based on speed (and direction),  
	Deduct from health, change direction if perimiter is hit.
	Enemy can move in 4 directions North, South, East, or West
*/
#include "Enemy.h"

void Enemy::update()
{
	if (getDirection() == SW) {					// Enemy heading South-West, #1
		setX(getX() - getSpeed());				// X = X - speed (Going left)
		setY(getY() + getSpeed());				// Y = Y + speed (Going down the board)
	} 
	else if (getDirection() == South) {			// Enemy heading South, #2
		setY(getY() + getSpeed());				// Y = Y + speed (Going down the board)
	} 
	else if (getDirection() == SE) {			// Enemy Heading Sout-East, #3
		setX(getX() + getSpeed());				// X = X + speed (Going right on board)
		setY(getY() + getSpeed());				// Y = Y + speed (Going down the board)
	}
	else if (getDirection() == West) {			// Enemy Heading West, #4
		setX(getX() - getSpeed());				// X = X - speed  (Going left on board)
	}
	else if (getDirection() == East) {			// Enemy heading East, #6
		setX(getX() + getSpeed());				// X = X + speed  (Going right on board)
	}
	else if (getDirection() == NW) {	 		// Enemy heading North-West, #7
		setX(getX() - getSpeed());				// X = X - speed  (Going left on board)
		setY(getY() - getSpeed());				// Y = Y - speed (Going up the board)
	}
	else if (getDirection() == North) {			// Enemy Heading North, #8
		setY(getY() - getSpeed());				// Y = Y - speed (Going up the board)
	}
	else if (getDirection() == NE) {			// Enemy Heading North-East, #9
		setY(getY() - getSpeed());				// Y = Y - speed (Going up the board)
		setX(getX() + getSpeed());				// X = X + speed  (Going right on board)
	}

	setHealth(getHealth() - (getSpeed() * getDamage()));	// Deduct from Health

	GameObject::update();						// Call base class member function 
}