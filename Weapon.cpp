/*	Joe O'Regan
K00203642
Digital Games Programming Principles
Assignment
*/
/*	2016-11-30:
Separating the weapons of the game into a separate class
So far the weapons include: sword ...a massive selection
*/

#include "Weapon.h"


int Weapon::getWeaponStrength() {
	return m_WeaponStrength;
}
int Weapon::getUpgradeLevel() {
	return m_UpgradeLevel;
}

void Weapon::setWeaponStrength(int strength) {
	m_WeaponStrength = strength;
}
void Weapon::setUpgradeLevel(int level) {
	m_UpgradeLevel = level;
}
/*
private:
	int m_weaponStrength;
	int m_upgradeLevel;*/