/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment
*/
/*	2016-11-24:
	Add treasure chest to the game, which can contain potions, weapons, 
	power ups etc, a random number will be used to decide what is contained
	in the treasure chest.
	The treasure chest will have a lifespan, starting from the moment it was created 
	and ending when the loop reaches the point after it was created + the lifespan
*/

#ifndef TREASURE_CHEST_H
#define TREASURE_CHEST_H

#include "GameObject.h"

// Derived class
class TreasureChest : public GameObject
{
public:
	virtual void update();
	int startTime;					// The point on the loop counter the object was created

	void setLifespan(int ls);		// Set a lifespan of the object to appear on screen
	int getLifespan();				// Get the lifespan of the object
private:
	int m_lifespan = 10;			// The lifespan of the object from the moment it was created
};

#endif