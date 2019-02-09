/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-11-27:
	Get and set the lifespan of the object. The time the object will appear on screen
	Objects with a lifespan of 11 or more will not be removed from the screen until a
	player has picked them up, e.g. the first sword object.

	Other objects such as potions will only appear on the screen for certain length of
	time. The player won't know what's in a treasure chest until he occupies the same
	coordinates as the treasure chest.

	Any object that has a lifespan of 10 or less can be decremented
*/
#include "TreasureChest.h"

void TreasureChest::update()
{
	int x = getX();
	int y = getY();

	//setLifespan(getLifespan() - 1);				// Remember to decrement the lifespan everytime the function is called

	GameObject::update();							// Call base class member function 
}


/*	2016-11-27:
	Get and set the lifespan of the object. The time the object will appear on screen 
	Objects with a lifespan of 11 or more will not be removed from the screen until a
	player has picked them up, e.g. the first sword object.
*/
void TreasureChest::setLifespan(int ls) {
	if(getLifespan() < 11)							// Any object that has a lifespan of 10 or less can be decremented
		m_lifespan = ls;
}
int TreasureChest::getLifespan() {
	return m_lifespan;
}