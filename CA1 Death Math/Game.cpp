// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#include "Game.h"
#define PLAYER_BAR 32
#define ENEMY_BAR 8

static int loopCount = 0;	// Counts the number of times the game loop has run

// create the objects
Player* pPlayer = new Player;
Enemy* pEnemy1 = new Enemy;
Enemy* pEnemy2 = new Enemy;
Enemy* pEnemy3 = new Enemy;
Enemy* pEnemy4 = new Enemy;

std::list<GameObject*> listOfGameObjects;	// List of pointers to GameObjects

// Create the objects & assign values
void Game::init() {
	// Assign each enemy and player unique typeID, health, speed, x, y
	pPlayer->spawn("Player", 160, 4, 12, 12);	// Max Health = 160
	pEnemy1->spawn("Enemy 1", 80, 1, 2, 23);	// Speed is between 1 and 4
	pEnemy2->spawn("Enemy 2", 125, 2, 22, 1);
	pEnemy3->spawn("Enemy 3", 150, 3, 1, 2);
	pEnemy4->spawn("Enemy 4", 160, 4, 23, 22);

	// Set Enemy Directions
	pEnemy1->setDirection(North);
	pEnemy2->setDirection(South);
	pEnemy3->setDirection(East);
	pEnemy4->setDirection(West);
	
	// Place the objects on the list
	listOfGameObjects.push_back(pPlayer);
	listOfGameObjects.push_back(pEnemy1);
	listOfGameObjects.push_back(pEnemy2);
	listOfGameObjects.push_back(pEnemy3);
	listOfGameObjects.push_back(pEnemy4);
	
	// Create and display game logo
	Logo logo;			// Create logo
	logo.drawLogo();	// Display Game Logo

	logo.drawName();	// More Logo stuff

	ClearScreen();		// Clear the screen
}


// cycle through the enemy & player objects & call draw() for each object
void Game::draw() {
	// Keep track of original colours
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	
	LoopCounter();								// Display number of times game has looped

	displayHealthBars();						// Display Player Health Bar	
	
	drawGrid();									// Draw the grid displaying game object positions

	// SET TEXT COLOUR FOR GAME OBJECT COORDS
	SetConsoleTextAttribute(hstdout, 0x81);		// Grey bg, Navy txt

	std::list<GameObject*>::const_iterator it;	// iterator for Game Objects list

	// Cycle through the enemy & player objects and call the draw function for each object
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		(*it)->draw();							
	}

	// Reset colours
	FlushConsoleInputBuffer(hstdin);
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}


// cycle through the enemy & player objects & call update() for each object
void Game::update() {	
	std::list<GameObject*>::const_iterator it;	// read-only iterator, handles pointers to game objects

	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		(*it)->update();						// Call the update function for each object
	}
}

/* if 2 objects occupy the same coords declare a battle must take place. The object with the higher health wins. 
  The loser will have its health set to 0. Get game objects coords & check is there any objects with the same coords */
void Game::battle() {
	std::list<GameObject*>::const_iterator it;

	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)				// Cycle through list of game objects
	{
		if ((*it)->getID() != "Player")														// Player obviously has it's own coordinates
		{
			if (((*it)->getX()) == ((*pPlayer).getX()) && ((*it)->getY()) == ((*pPlayer).getY())) // if enemy coordinates = player coords
			{
				// Common to all 3 messages
				SetConsoleTextAttribute(hstdout, 0xC0);										// Red BG, Black txt
				std::cout << "Player and " << (*it)->getID();
				std::cout << " are getting ready to rumble!!!\n\t\t\t\t\t\t " << std::endl;				// Fight
				std::cout << "\t\tPlayer Health: " << (*pPlayer).getHealth() << "\t\t " << std::endl;	// Player Health
				std::cout << "\t\t" << (*it)->getID() << "'s Health: " 
					<< (*it)->getHealth() << "\t\t \n\t\t\t\t\t\t " << std::endl;			// Enemy Health

 /* DRAW */		if (((*pPlayer).getHealth()) == ((*it)->getHealth()))						// Player health equalt to enemy health
				{
					(*it)->setHealth(((*it)->getHealth()) - 20);							// Deduct 20 from Enemy health for draw
					(*pPlayer).setHealth(((*pPlayer).getHealth()) - 20);					// Deduct 20 from Player
					std::cout << "\tThis fight has ended in a draw\t\t " << std::endl;
					std::cout << " Player and " << (*it)->getID() << " both receive damage points!! " << std::endl;
				}
 /* LOSE */		else if (((*pPlayer).getHealth()) < ((*it)->getHealth()))					// Player health less than Enemies
				{	
					// Display relevant message, and set health value 
					std::cout << "\t   " << (*it)->getID() << " Has Won The Battle\t\t " << std::endl;
					std::cout << "\t  And was stronger by " << (*it)->getHealth() - (*pPlayer).getHealth() << " points!  \t " << std::endl;
					std::cout << "\t        Player is a loser!!!\t\t " << std::endl;

					(*pPlayer).setHealth(0);												// Set Player Health to 0
				}
  /* WIN */		else																		// Player health greater than Enemies
				{				
					std::cout << "\t    Player has defeated " << (*it)->getID() << "\t\t " << std::endl;

					if((*pPlayer).getHealth() - (*it)->getHealth() == 1)					// If there is only 1 point between the objects
						std::cout << "\t  And was stronger by " << 
							(*pPlayer).getHealth() - (*it)->getHealth() << " point!  \t " << std::endl; // 1 point
					else
						std::cout << "\t  And was stronger by " << 
							(*pPlayer).getHealth() - (*it)->getHealth() << " points! \t " << std::endl; // > 1 point
					std::cout << "\t  Player has won this battle!!!\t\t " << std::endl;

					(*it)->setHealth(0);								// Might deduct from enemy health so fight isn't one sided	
				}
				SetConsoleTextAttribute(hstdout, 0x0F);					// Reset  - Black BG, White txt
			}	// end if
		}	// end if
	}	// end for
	std::cin.get();	// Pause the message on screen, so ClearScreen doesn't wipe it
}

// Cycle through the enemy and player objects and call the info function for each object
void Game::info() {
	std::list<GameObject*>::const_iterator it;	// read-only iterator, handles pointers to game objects

	// Message Heading
	SetConsoleTextAttribute(hstdout, 0xF1);								// White BG, Blue txt
	std::cout << std::setw(34) << "INFORMATION\t\t\t " << std::endl;
	SetConsoleTextAttribute(hstdout, 0x71);								// Grey BG, Blue txt

	// Print the Name and Coordinates for each Game Object
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{		
		SetConsoleTextAttribute(hstdout, 0x75);
		std::cout << "    " << (*it)->getID(); 
		SetConsoleTextAttribute(hstdout, 0x71);
		std::cout << "\t\t\tCoordinates:\t " << std::endl <<
			"    Speed: " << (*it)->getSpeed() << " Health: " << (*it)->getHealth() <<
			"  \tX: " << (*it)->getX() << "  \tY: " << (*it)->getY() << "\t " << std::endl;
	}

	// Press Enter To Continue
	SetConsoleTextAttribute(hstdout, 0x01);							   // Black BG, Blue text				
	std::cout << "\n\t     Press Enter To Continue\t\t " << std::endl;
	SetConsoleTextAttribute(hstdout, 0x0F);							   // Reset colour Black bg, White txt	
	std::cin.get();													   // Pause the screen

	ClearScreen();													   // Clear the screen
}


// remove any objects from the list whose health is 0  (Using isAlive function);
void Game::clean() {
	// cycle through loop
	std::list<GameObject*>::const_iterator it = listOfGameObjects.begin(); // Iterator set to list start

	while (it != listOfGameObjects.end())								   // Cycle through list
	{
		if ((*it)->isAlive())											   // if it is alive iterate
			++it;														   // Increment iterator
		else															   // Otherwise...
				it = listOfGameObjects.erase(it);						   // Erase object from list
	}	// end while
}	// end clean


// Draw the grid to display game objects positions
void Game::drawGrid()
{
	// Set background text in the grid - for no paticular reason
	char* board[25][25] = { { "* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","__","__","__"," _","__","__","  ","__","_ ","__","__","_ ","_ ","  ","_ ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| "," _","  ","\\ "," _","__","|/"," _"," \\","_ ","  ","_|"," |"," |"," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| ","| ","| ","| ","|_","_ ","/ ","/_","\\ ","\\|"," |"," |"," |","_|"," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| ","| ","| ","| "," _","_|","| "," _","  ","||"," |"," |","  ","_ "," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| ","|/"," /","| ","|_","__","| ","| ","| ","||"," |"," |"," |"," |"," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","|_","__","/ ","\\_","__","_/","\\_","| ","|_","/\\","_/"," \\","_|"," |","_/","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","__","_ "," _","__","  ","__","_ ","__","__","_ ","__","__","_ ","  ","_ ","  ","_ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| "," \\","/ "," |"," /"," _"," \\","_ ","  ","_/","  ","__"," \\"," |"," |"," |"," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ",". "," ."," |","/ ","/_","\\ ","\\|"," |"," |"," /","  ","\\/"," |"," |","_|"," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ","|\\","/|"," |","| "," _","  ","||"," |"," |"," |","  ","  "," |","  ","_ "," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ","| "," |"," |","| ","| ","| ","||"," |"," |"," \\","__","/\\"," |"," |"," |"," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","\\_","| "," |","_/","\\_","| ","|_","/\\","_/","  ","\\_","__","_/"," \\","_|"," |","_/","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","__","_ "," _","__","__","_ ","__","__","_ ","_ ","  ","_ ","  ","__","_ ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  "," /"," _"," \\"," |"," _","__"," \\","  ","__","_|"," \\"," |"," |"," /"," _"," \\","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","/ ","/_","\\ ","\\|"," |","_/"," /"," |","__"," |","  ","\\|"," |","/ ","/_","\\ ","\\ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| "," _","  ","||","  ","  ","/|","  ","__","||"," ."," `"," |","| "," _","  ","| ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ","| ","| ","||"," |","\\ ","\\|"," |","__","_|"," |","\\ "," |","| ","| ","| ","| ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","\\_","| ","|_","/\\","_|"," \\","_\\","__","__","/\\","_|"," \\","_/","\\_","| ","|_","/ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* ","* " } };

	std::list<GameObject*>::const_iterator it;

	// Get Game Object Positions
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		int x = (*it)->getX();					// Local variable to store x coord
		int y = (*it)->getY();					// local variable to store y coord

		if ((*it)->getID() == "Player")			// If the GameObject is Player represent it with an X
			board[y][x] = "X ";					// COORDS REVERSED!!!
		else if ((*it)->getID() == "Enemy 1")	// Represent Enemy 1 with E1
			board[y][x] = "E1";
		else if ((*it)->getID() == "Enemy 2")	// Represent Enemy 2 with E2
			board[y][x] = "E2";
		else if ((*it)->getID() == "Enemy 3")	// Represent Enemy 3 with E3
			board[y][x] = "E3";
		else if ((*it)->getID() == "Enemy 4")	// Represent Enemy 4 with E4
			board[y][x] = "E4";
	}

	// IMPACT POINT	 - store an impact point for each object to display where the object collided with the border
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		int impactX = (*it)->getImpactX();					// Get impact x coord
		int impactY = (*it)->getImpactY();					// Get impact y coord
		board[impactY][impactX] = "@ ";
		board[0][0] = "* ";									// Using 0s to reset impactX and impactY 		
		// reset impact point
		(*it)->setImpactX(0);								// reset impactX so impact points only draw once
		(*it)->setImpactY(0);								// reset impactY so impact points only draw once
	}

	// Print board
	SetConsoleTextAttribute(hstdout, 0xF9);					// White bg, Blue txt -> Grid Heading
	std::cout << "            PLAYER & ENEMY POSITIONS:            " << std::endl;
	SetConsoleTextAttribute(hstdout, 0x0F);					// Black bg, White txt
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++)
		{
			if (board[i][j] == "X ")						// X - represents the Player
				SetConsoleTextAttribute(hstdout, 0x0C);		// Black bg, Red txt
			else if (board[i][j] == "E1" || board[i][j] == "E2" || board[i][j] == "E3" || board[i][j] == "E4")	// Enemies
				SetConsoleTextAttribute(hstdout, 0x0A);		// Black bg, Green txt
			else if (board[i][j] == "* ")					// * - represents the border of the grid
				SetConsoleTextAttribute(hstdout, 0x09);		// Black bg, Gey txt
			else if (board[i][j] == "@ ")					// @ represents impact point on boundary
				SetConsoleTextAttribute(hstdout, 0x04);		// Black bg, Red txt
			else											// Background text in the arena
				SetConsoleTextAttribute(hstdout, 0x08);		// Black bg, Grey txt

			std::cout << board[i][j];						// Print each array position for board
		}
		std::cout << std::endl;								// New line
	}
}

void Game::ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Game::displayHealthBars()
{
	std::cout << " Player Health: ";

	calcHealthBar(PLAYER_BAR, "Player");

	SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, Black txt
	std::cout << " " << std::endl;						// End Of Line

	std::cout << " E1 ";
	calcHealthBar(ENEMY_BAR, "Enemy 1");				// Enemy 1 health bar
	std::cout << " E2 ";
	calcHealthBar(ENEMY_BAR, "Enemy 2");				// Enemy 2 health bar
	std::cout << " E3 ";
	calcHealthBar(ENEMY_BAR, "Enemy 3");				// Enemy 3 health bar
	std::cout << " E4 ";
	calcHealthBar(ENEMY_BAR, "Enemy 4");				// Enemy 4 health bar

	std::cout << " " << std::endl;						// End Of Line
	SetConsoleTextAttribute(hstdout, 0x0F);				// Black bg, White txt
}

void Game::calcHealthBar(int barSize, char* objectID)
{
	int posHealth=0, negHealth;
	char* barUnit = " ";

	std::list<GameObject*>::const_iterator it = listOfGameObjects.begin(); // Iterator set to start of list

	while (it != listOfGameObjects.end())				// Cycle through loop
	{
		if ((*it)->getID() == objectID)					// If object matches the one passed to the function
		{
			if (barSize == PLAYER_BAR)					// Player health bar size 32
			{
				posHealth = (*it)->getHealth() / 5;		// positive  -  Divide Health by 5 to get each bar unit
				barUnit = "_";							// Blue line separates health Bars
			}
			else										// Enemy bar size 8
				posHealth = (*it)->getHealth() / 20;	// positive  -  Bar Size 8 -> divide by 20
		}
		++it;											// Increment iterator
	}

	// PRINT THE BARS	
	negHealth = barSize - posHealth;					// Calculate negative health
	SetConsoleTextAttribute(hstdout, 0xC0);				// Red BG, Black txt
	if (posHealth == 0)									// If Objects health is 0
		std::cout << " R.I.P. ";						// Its dead
	else
	{
		SetConsoleTextAttribute(hstdout, 0x29);			// Positive Green
		for (int i = 0; i < posHealth; i++)
			std::cout << barUnit;
		SetConsoleTextAttribute(hstdout, 0xC9);			// Negative Red
		for (int i = 0; i < negHealth; i++)
			std::cout << barUnit;
	}
	SetConsoleTextAttribute(hstdout, 0x9F);				// Reset colour, Blue BG, Black txt
}

// Display Number Of Loops
void Game::LoopCounter()
{	
	loopCount++;
	SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, White txt
	std::cout << " \t\t\t\t\t\t " << std::endl;			// Blank line
	std::cout << "\t\t Loop Count: " << loopCount << "\t\t\t " << std::flush << std::endl;
	std::cout << "\t\t\t\t\t\t " << std::endl;
}

// Game Over Messages
int Game::GameOver()
{
	Logo decision;							// Draw end of game logos	
	int result = Undecided;					// Decide which message to display
	
	std::list<GameObject*>::const_iterator it = listOfGameObjects.begin(); // Iterator
	
	while ( it != listOfGameObjects.end() )
	{
		if ( (*it)->getID() == "Player" && listOfGameObjects.size() == 1 ) // No Enemies on list
			result = Win;												   // Win Game
		if ( (*listOfGameObjects.begin())->getID() != "Player" )		   // Player erased
			result = Lose;												   // Lose Game
		++it;
	}
	
	SetConsoleTextAttribute(hstdout, 0x9F);	// Blue BG, White txt
	if(result == Lose || result == Win)
		decision.drawGameOver();

	// Display different message for win lose draw
	if (result == Lose)						
		decision.drawLoser();				// Display Loser Logo
	else if (result == Win)
		decision.drawWinner();				// Display Winner Logo

	SetConsoleTextAttribute(hstdout, 0x0F);	// Reset Console text: Black BG, White txt

	return result;
}