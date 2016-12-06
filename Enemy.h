// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

// Derived class
class Enemy : public GameObject
{
public:
	virtual void update();	// Cycle through the Enemy & Player objects and their update()
};		

#endif