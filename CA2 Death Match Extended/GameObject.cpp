/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-11-30:
	Fixed rebounds on the northern wall, objects were rebounding direction from north to south
	but not east to west, when hitting a wall at an angle

	2016-11-29:
	Changed the setSpeed() function to void type from int

	2016-11-28:
	Added direction to the list of printed items, to keep track of the direction game objects
	are moving

	2016-11-27:
	Set a random direction for game objects, direction can be any number 1 to 9 except 5

	Added more realistic rebounds for when a player hits a perimiter at an angle going up,
	it rebounds away at the opposite angle going down etc.

	2016-11-11:
	Add random coordinates to spawn, enemy objects will now spawn randomly on the
	battle grid. A unique set of objects is generated for each object so enemies
	are not destroyed in the first loop through the game.
	Each object has random direction so movement is not the same each time the
	objects are created or when the game is run.

	A separate function is used in the game class to check the coordinates are unique
*/
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

/*	2016-11-11:
	Add random coordinates to spawn, enemy objects will now spawn randomly on the
	battle grid. A unique set of objects is generated for each object so enemies
	are not destroyed in the first loop through the game. 
	Each object has random direction so movement is not the same each time the 
	objects are created or when the game is run.
*/
void GameObject::spawn(std::string typeID, int health, int speed) {			/* NEW SPAWN FOR RANDOM PLACEMENT */
	m_typeID = typeID;
	m_health = health;								// Set Health to a max of 160
	setSpeed(speed);								// Set speed between 1 and 4
	setRandomCoords();								// Set random unique coordinates for the object
	setRandomDirection();							// Set a random direction for the objects
}

/*	2016-11-11:
	This function is used to create random coordinates for Game Objects
	A separate function is used in the game class to check the coordinates are unique
*/
void GameObject::setRandomCoords() {
	int	randomNumber = rand();						// generate random number			
	setX((randomNumber % 23) + 1);					// Get a number between 1 and 23
	randomNumber = rand();		
	setY((rand() % 23) + 1);
}


/*	2016-11-11:
	Added a direction attribute for objects, default is 5 for static, unmoving objects
	CA1:
	The spawn function creates the objects, assigning a name, health, speed, and coordinates
*/
void GameObject::spawn(std::string typeID, int health, int speed, int x, int y) {
	m_typeID	= typeID;
	m_health	= health;				// Set Health to a max of 160
	setSpeed(speed);					// 2016-11-29 CA2 - Checks integer and sets speed between 1 and 4
	m_x			= x;					// Coordinates are between 1 and 23
	m_y			= y;					// The Y coordinate for the Game Object
	m_direction = 5;					// Set the game objects default to not moving
}

/*	2016-11-28:
	Added direction to the list of printed items, to keep track of the direction game objects
	are moving
	CA1:
	Print to the screen the typeID and its x and y coords - underneath game grid
*/
void GameObject::draw() {	
	std::cout << "\tName: " << m_typeID << "\tX: " << m_x << "\tY: " << m_y << "\tDirection: ";
	switch (m_direction) {
	case SW:						// South-West, #1
		std::cout << "South-West";
		break;
	case South:						// South, #2
		std::cout << "South     ";
		break;
	case SE:						// South-East, #3
		std::cout << "South-East";
		break;
	case West:						// West, #4
		std::cout << "West      ";
		break;
	case 5:							// Not moving, #5
		std::cout << "Static    ";
		break;
	case East:						// East, #6
		std::cout << "East      ";
		break;
	case NW:						// North-West, #7
		std::cout << "North-West";
		break;
	case North:						// North, #8
		std::cout << "North     ";
		break;
	case NE:						// North-East, #9
		std::cout << "North-East";
		break;
	default:
		break;
	}
		
	std::cout << "\t" << std::endl;
}


/*	2016-11-27:
	Added more realistic rebounds for when a player hits a perimiter at an angle going up, 
	it rebounds away at the opposite angle going down etc.
	CA1: 
	virtual function. If Enemy hits the perimiter deduct more from health
*/
void GameObject::update() {	
	if (getX() > BOARD_MAX || getY() > BOARD_MAX || getX() < BOARD_MIN || getY() < BOARD_MIN) {
		std::cout << "\n  " << getID() << " health has taken a hit of " << getSpeed() * getDamage() << std::endl;
		std::cout << "  Aiming for coordinates X: " << getX() << " Y: " << getY() << " at speed: " << getSpeed() << std::endl;
		setHealth(getHealth() - (getSpeed() * getDamage()));	// Deduct from Health: the current speed by damage point (3 for Enemy, 2 for Player)
	}

	// Rebound Off Perimeter
	if (getY() < BOARD_MIN)	{					// North
		// Impact Point
		setImpactX(getX());						// Set as current X coordinate
		setImpactY(0);							// Set as perimeter

		std::cout << "  " << getID() << " has hit the north boundary" << std::endl;
		if (getY() == 0) {						// If game object stops on the boundary line, move it
			setY(BOARD_MIN);					// Reposition to 1 on grid so game object isn't in boundary
		} else {
			if (getDirection() == NE)			// 30-11-2016 Fixed angle of rebound
				setDirection(SE);
			else if (getDirection() == North)
				setDirection(South);
			else if (getDirection() == NW)
				setDirection(SW);

			rebound = getY() % BOARD_MAX;		// Get the difference between border and game object
			setY(BOARD_MIN - rebound);			// Add the difference (should be - figure) to min x grid point
		}

		setSpeed(getSpeed() - 1);
	}

	if (getY() > BOARD_MAX) {					// South
		// Impact Point
		setImpactX(getX());						// Set as current X coordinate
		setImpactY(BOARD_MAX + 1);				// Set as perimeter

		std::cout << "  " << getID() << " has hit the south boundary" << std::endl;
		rebound = getY() % BOARD_MAX;
		setY(BOARD_MAX - rebound);				// Bounce back the distance the object would have travelled past the boundary

		if (getDirection() == SE) {
			setDirection(NE);
			setX(getX() + 23 - getY());
		} else if (getDirection() == South)
			setDirection(North);
		else if (getDirection() == SW) {
			setDirection(NW);
			setX(getX() - (23 - getY()));
		}
		setSpeed(getSpeed() - 1);
	}

	if (getX() > BOARD_MAX)	{					// East
		// Impact Point
		setImpactX(BOARD_MAX + 1);				// Set as perimeter
		setImpactY(getY());						// Set as current Y coordinate

		std::cout << "  " << getID() << " has hit the east boundary" << std::endl;
		rebound = getX() % BOARD_MAX;
		setX(BOARD_MAX - rebound);				// Subtract the difference and step back from boundary

												// CA2
		if (getDirection() == SE)
			setDirection(SW);
		else if (getDirection() == East)
			setDirection(West);
		else if (getDirection() == NE)
			setDirection(NW);
		setSpeed(getSpeed() - 1);
	}

	if (getX() < BOARD_MIN)	{					// West
		// Impact Point
		setImpactX(0);							// Set as perimeter
		setImpactY(getY());						// Set as current Y coordinate

		std::cout << "  " << getID() << " has hit the west boundary" << std::endl;
		rebound = getX() % BOARD_MAX;

		if (getX() == 0)						// If game object stops on the boundary line, move it
			setX(BOARD_MIN);					// Step back from boundary by 1
		else
			setX(BOARD_MIN - rebound);			// Rebound from postion 1
		
		if (getDirection() == SW)
			setDirection(SE);
		else if (getDirection() == West)
			setDirection(East);
		else if (getDirection() == NW)
			setDirection(NE);
		setSpeed(getSpeed() - 1);
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

/* global friend function which can access all of game object's members
   overloads the << operator so you can send a Game object to cout */
std::ostream& operator<<(std::ostream& os, const GameObject& aGameObject)
{
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

const int GameObject::getHealth() const{
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

int GameObject::getImpactX() const{
	return reboundX;				// Point of impact with boundary
}

int GameObject::getImpactY() const{
	return reboundY;				// Point of impact with boundary
}

int GameObject::getDamage() const{
	return m_Damage;				// Damage cost for Game Objects movement
}

// Setter Methods

void GameObject::setHealth(int health){
	// Max health should be 160
	if (health > 160)
		m_health = 160;				// Max 160
	else if (health < 0)
		m_health = 0;				// Display minimum health as 0, over kill
	else
		m_health = health;
}

/*	2016-11-29:
	Changed function to void type
	CA1:
	returns an integer
*/
void GameObject::setSpeed(int speed){
	if (speed > 0 && speed < 5)
		m_speed = speed;
	else if (speed > 4)
		m_speed = 4;
	else if (speed < 1)
		m_speed = 1;
}

void GameObject::setX(int x){
	m_x = x;
}

void GameObject::setY(int y)
{
	m_y = y;
}

void GameObject::setImpactX(int x){
	reboundX = x;
}

void GameObject::setImpactY(int y){
	reboundY = y;
}

// Change GameObject direction after rebounding etc
void GameObject::setDirection(int d){
	m_direction = d;
}


/* CA2 */
/*  2016-11-27:
	Set a random direction for game objects, direction can be any number 1 to 9 except 5
*/
void GameObject::setRandomDirection() {
	int	randomNumber = rand();						// generate random number	
	setDirection((randomNumber % 9) + 1);					// Get a number between 1 and 23
	if (getDirection() == 5)
		setRandomDirection();
}
/*	2016-11-27:
	Returns the direction the Game Object is moving in */
int GameObject::getDirection(){
	return m_direction;
}