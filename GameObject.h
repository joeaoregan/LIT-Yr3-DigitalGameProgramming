// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <iostream>
#include <string>
#include <iomanip>

class GameObject
{
	// global functions friends of the GameObjects class
	friend std::ostream& operator<<(std::ostream& os, const GameObject& aGameObject);

public:	
	GameObject(int damage = 3);			// Constructor with default value of 3 for damage
	~GameObject();						// Deconstructor

	void spawn(std::string typeID, int health, int speed, int x, int y);	// create an object
	void draw();						// print to the screen the typeID and its x and y coords
	virtual void update();				// virtual function
	void info();						// print all info relating to the object
	bool isAlive();						// return true if its health is greater than 0
	
	// Getter Methods
	std::string getID() const;			// Get GameObject name / ID
	int getHealth() const;				// Get GameObject health
	int getSpeed() const;				// Get GameObject speed
	int getX() const;					// Get GameObject X coord
	int getY() const;					// Get GameObject Y coord
	int getDamage() const;				// Get GameObject Damage
	// Setter Methods
	void setHealth(int health);			// set the health, Max health should be 160
	int setSpeed(int speed);			// Set speed between 1 and 4
	void setX(int x);					// Set GameObject X coord
	void setY(int y);					// Set GameObject Y coord

	// Indicate where the border has been impacted
	int reboundX = 0, reboundY = 0;		// Store impact point, to highlight
	int getImpactX() const;				// Get the x coord of impact object
	int getImpactY() const;				// Get the y coord of impact object
	void setImpactX(int x);				// Set and reset objects impact x coord
	void setImpactY(int y);				// Set and reset objects impact y coord

	// Change GameObject direction
	int rebound;											// Amount to bounce back of perimeter
	enum directionName { North = 0, South, East, West };	// Use readable values for directions
	void setDirection(int d);								// Sets the direction of the GameObject (game init())
	int direction;											// The direction GameObject is moving
	//int damage;

private:
	// GameObject Variables
	std::string m_typeID;				// GameObject name
	int m_health;						// Value between 0 and 160
	int m_speed;						// Value between 1 and 4
	int m_x;							// GameObject x coord
	int m_y;							// GameObject y coord
	int m_Damage;						// Damage to reduce health after an object moves
};

#endif