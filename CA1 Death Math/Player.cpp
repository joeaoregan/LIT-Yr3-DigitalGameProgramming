// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#include "Player.h"

Player::Player(int damage) :
	GameObject(damage)									// Call base class constructor with argument
{}

// +/- x and y coords based on speed, deduct from health, reverse if perimiter hit
void Player::update() {									// Override base class member function
	plDirectionInfo();									// Display the player movement info
						
	std::cin >> speedDirection;							// Take in the direction the player is to move
	moveDirection(speedDirection);
	
	GameObject::update();								// Call base class member function 

	setHealth(getHealth() - getSpeed() * getDamage());	// Deduct from health: current speed * damage
}


// Move Player in the required direction
void Player::moveDirection(int speedDirection)
{
	// Set new speed to the remainder
	int newspeed = speedDirection / 10;	
	// Set direction to the modulus (number from 0 to 9)
	speedDirection = speedDirection % 10;
	// if no speed change in range, use existing speed
	if (newspeed < 1 || newspeed > 3)
		newspeed = getSpeed();				

	switch (speedDirection) {
	case 1:
		setX(getX() - newspeed);	// Left
		setY(getY() + newspeed);	// Down
		break;
	case 2:
		setY(getY() + newspeed);	// Down
		break;
	case 3:
		setX(getX() + newspeed);	// Right
		setY(getY() + newspeed);	// Down
		break;
	case 4:
		setX(getX() - newspeed);	// Left
		break;
	case 6:
		setX(getX() + newspeed);	// Right
		break;
	case 7:
		setX(getX() - newspeed);	// Left
		setY(getY() - newspeed);	// Up
		break;
	case 8:
		setY(getY() - newspeed);	// Up
		break;
	case 9:
		setX(getX() + newspeed);	// Right
		setY(getY() - newspeed);	// Up
		break;
	default:
		break;
	}
}

// Display information on directional movement for Player
void Player::plDirectionInfo()
{
	// Keep track of original colours
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdoutPl, &csbi);
	
	SetConsoleTextAttribute(hstdoutPl, 0x2F);	// green bg, white txt
	std::cout << "      Please enter direction to move " << getID() << "\t " << std::endl;
	SetConsoleTextAttribute(hstdoutPl, 0x20);	// green bg, black txt
	std::cout << "\t7. NW\t   8. North\t9. NE\t\t " << std::endl;
	std::cout << "\t4. West\t   5. Stay \t6. East\t\t " << std::endl;
	std::cout << "\t1. SW\t   2. South\t3. SE\t\t " << std::endl;

	SetConsoleTextAttribute(hstdoutPl, 0xF2);	// White BG, Green txt
	std::cout << "\tThe Players Current Speed Is 4\t\t " << std::endl;
	SetConsoleTextAttribute(hstdoutPl, 0x02);	// Black BG, Green txt
	std::cout << "Alter Player speed by entering a preceeding digit" << std::endl;
	std::cout << "For example, entering 12, 22, 32.  (Range 1 to 4)" << std::endl;
	std::cout << "Where speed will equal 1, 2, or 3 the first digit\n" <<
		"Direction will be 2, for North.  Default Speed: 4" << std::endl;
	std::cout << "Enter Number(s): ";
	SetConsoleTextAttribute(hstdoutPl, 0x0F);	// black bg, white txt

	// Reset colours
	FlushConsoleInputBuffer(hstdinPl);
	SetConsoleTextAttribute(hstdoutPl, csbi.wAttributes);
}