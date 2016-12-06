// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#include "Enemy.h"

// Moves Enemy based on speed (and direction),  
// Deduct from health, change direction if perimiter hit
void Enemy::update()
{
	if(direction == North)						// Enemy heading North
		setY(getY() - getSpeed() );				// Y = Y - speed (Going up the board)
	else if (direction == South)				// Enemy heading South
		setY(getY() + getSpeed());				// Y = Y + speed (Going down the board)
	else if (direction == East)					// Enemy Heading East
		setX(getX() + getSpeed());				// X = X + speed (Going right on board)
	else										// Enemy Heading West
		setX(getX() - getSpeed() );				// X = X - speed  (Going left on board)

	setHealth(getHealth() - (getSpeed() * getDamage()));	// Deduct from Health

	GameObject::update();						// Call base class member function 
}