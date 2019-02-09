/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-11-30:
	Separating the weapons of the game into a separate class
	So far the weapons include: sword
*/
#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"

#include <iostream>
#include <windows.h>		// for coloured text

class Weapon : public GameObject
{
public:
	int getWeaponStrength();
	int getUpgradeLevel();

	void setWeaponStrength(int Strength);
	void setUpgradeLevel(int level);
private:
	int m_WeaponStrength;	// The amount of strength will determine how much damage it will inflict on an enemy
	int m_WeaponDefence;	// Amount of defence will determine how much protection the player receives from enemy strikes
	int m_UpgradeLevel;		// The upgrade level of the weapon, an upgrade level will have a minimum strength and defence
							// Some enemies such as the boss will require a hire grade of weapon to be defeated
};

#endif
