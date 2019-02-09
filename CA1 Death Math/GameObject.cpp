// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#include "GameObject.h"

#define BOARD_MIN 1		// Top & Left Edge
#define BOARD_MAX 23	// Bottom & Right Edge

// Constructor
GameObject::GameObject(int damage) :	// Constructor has default value for damage of 3
	m_Damage(damage)
{}

// Deconstructors
GameObject::~GameObject() {
	std::cout << "GameObject deconstructor" << std::endl;
}

// create an object
void GameObject::spawn(std::string typeID, int health, int speed, int x, int y) {
	m_typeID	= typeID;
	m_health	= health;				// Set Health to a max of 160
	m_speed		= setSpeed(speed);		// Set speed between 1 and 4
	m_x			= x;					// Coordinates are between 1 and 23
	m_y			= y;
}

// Print to the screen the typeID and its x and y coords - underneath game grid
void GameObject::draw() {	
	std::cout << "\tName: " << m_typeID << "\tX: " << m_x << "\tY: " << m_y << "\t\t " << std::endl;
}

//virtual function
void GameObject::update() {
	//std::cout << "Game Objects update() function" << std::endl;

	// If Enemy hits the perimiter deduct more from health
	if (getX() > BOARD_MAX || getY() > BOARD_MAX || getX() < BOARD_MIN || getY() < BOARD_MIN)
	{
		//std::cout << std::endl << getID() << " has hit the boundary!" << std::endl;
		std::cout << "\n  " << getID() << " health has taken a hit of " << getSpeed() * getDamage() << std::endl;
		std::cout << "  Aiming for coordinates X: " << getX() << " Y: " << getY() << " at speed: " << getSpeed() << std::endl;
		setHealth(getHealth() - (getSpeed() * getDamage()));	// Deduct from Health: the current speed by damage point (3 for Enemy, 2 for Player)
	}

	// Rebound Off Perimeter
	if (getY() < BOARD_MIN)						// North
	{
		// Impact Point
		setImpactX(getX());						// Set as current X coordinate
		setImpactY(0);							// Set as perimeter

		std::cout << "  " << getID() << " has hit the north boundary" << std::endl;
		if (getY() == 0)						// If game object stops on the boundary line, move it
		{
			setY(BOARD_MIN);					// Reposition to 1 on grid so game object isn't in boundary
		}
		else
		{
			rebound = getY() % BOARD_MAX;		// Get the difference between border and game object
			setY(BOARD_MIN - rebound);			// Add the difference (should be - figure) to min x grid point
		}

		//setSpeed(speed - 1);
		setDirection(South);					// Change direction from North to South
	}

	if (getY() > BOARD_MAX)						// South
	{
		// Impact Point
		setImpactX(getX());						// Set as current X coordinate
		setImpactY(BOARD_MAX + 1);				// Set as perimeter

		std::cout << "  " << getID() << " has hit the south boundary" << std::endl;
		rebound = getY() % BOARD_MAX;
		setY(BOARD_MAX - rebound);				// Bounce back the distance the object would have travelled past the boundary

												//setSpeed(speed - 1);
		setDirection(North);					// Change direction from South to North
	}

	if (getX() > BOARD_MAX)						// East
	{
		// Impact Point
		setImpactX(BOARD_MAX + 1);				// Set as perimeter
		setImpactY(getY());						// Set as current Y coordinate

		std::cout << "  " << getID() << " has hit the east boundary" << std::endl;
		rebound = getX() % BOARD_MAX;
		setX(BOARD_MAX - rebound);				// Subtract the difference and step back from boundary

												//setSpeed(speed - 1);
		setDirection(West);						// Change direction from East to West
	}

	if (getX() < BOARD_MIN)						// West
	{
		// Impact Point
		setImpactX(0);							// Set as perimeter
		setImpactY(getY());						// Set as current Y coordinate

		std::cout << "  " << getID() << " has hit the west boundary" << std::endl;
		rebound = getX() % BOARD_MAX;

		if (getX() == 0)						// If game object stops on the boundary line, move it
			setX(BOARD_MIN);					// Step back from boundary by 1
		else
			setX(BOARD_MIN - rebound);			// Rebound from postion 1

												//setSpeed(speed - 1);
		setDirection(East);						// Change direction from West to East
	}
}

// print all info relating to the object
void GameObject::info() {
	//std::cout << "Game Objects info relating to the object" << std::endl;
}

// return true if its health is greater than 0
bool GameObject::isAlive() {
	//std::cout << "Game Objects isAlive() function" << std::endl;
	if (m_health <= 0)
		return false;	// If health is less than 0 return false
	return true;		// otherwise returns true
}

//global friend function which can access all of game object's members
//overloads the << operator so you can send a Game object to cout
std::ostream& operator<<(std::ostream& os, const GameObject& aGameObject)
{
		// DOESN'T PRINT IN GAME INFO() FOR IT

	//os << "Object: " << endl;
	//os << "Name: " << aGameObject.m_typeID << ",\nCoordinates - X: " << aGameObject.m_x << " Y: " << aGameObject.m_y << std::endl;
	//os << "Health: " << aGameObject.m_health << std::endl;

	os << std::setw(54) << "\n    " << aGameObject.m_typeID << "\t\t\t\t\t " << std::endl <<
		"    Speed: " << aGameObject.m_speed <<
		" Health: " << aGameObject.m_health <<
		"\tX: " << aGameObject.m_x <<
		"\tY: " << aGameObject.m_y << "\t ";

	return os;
}

// Getter Methods

std::string GameObject::getID() const{
	return m_typeID;
}

int GameObject::getHealth() const{
	return m_health;
}

int GameObject::getSpeed() const{
	return m_speed;
}

int GameObject::getX() const{
	return m_x;
}

int GameObject::getY() const{
	return m_y;
}

int GameObject::getImpactX() const
{
	return reboundX;				// Point of impact with boundary
}

int GameObject::getImpactY() const
{
	return reboundY;				// Point of impact with boundary
}

int GameObject::getDamage() const
{
	return m_Damage;				// Damage cost for Game Objects movement
}

// Setter Methods

void GameObject::setHealth(int health)
{
	// Max health should be 160
	if (health > 160)
		m_health = 160;				// Max 160
	else if (health < 0)
		m_health = 0;				// Display minimum health as 0, over kill
	else
		m_health = health;
}

int GameObject::setSpeed(int speed)
{
	if (speed > 0 && speed <= 4)
		return speed;
	else if (speed > 4)
		return 4;
	else
		return 0;
}

void GameObject::setX(int x)
{
	m_x = x;
}

void GameObject::setY(int y)
{
	m_y = y;
}

void GameObject::setImpactX(int x)
{
	reboundX = x;
}

void GameObject::setImpactY(int y)
{
	reboundY = y;
}

// Change GameObject direction after rebounding etc
void GameObject::setDirection(int d)
{
	direction = d;
}