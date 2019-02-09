/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/

/*	2016-11-29:
	Added Level logos, and a complete logo to display at the end of each level

	The level complete logo is called from the GameOver() function in Game
	when a level is complete, after the level number is displayed
*/

#include "Logo.h"

// Draw the game Logo
void Logo::drawLogo()
{
	// Colour stuff
	hstdinLogo = GetStdHandle(STD_INPUT_HANDLE);
	hstdoutLogo = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;				// Keep track of the originalcolours
	GetConsoleScreenBufferInfo(hstdoutLogo, &csbi);

	// Death
	SetConsoleTextAttribute(hstdoutLogo, 0xC0);										// Red bg, Black txt
	std::cout << std::endl << std::endl << "________                 __  .__   \t  ";
	SetConsoleTextAttribute(hstdoutLogo, 0xC7);										// Red bg, Grey txt
	std::cout << "Object " << std::endl;
	SetConsoleTextAttribute(hstdoutLogo, 0xC0);										// Red bg, Black txt
	std::cout << "\\______ \\   ____ _____ _/  |_|  |__\t";
	SetConsoleTextAttribute(hstdoutLogo, 0xC7);										// Red bg, Grey txt
	std::cout << "Oriented " << std::endl;
	SetConsoleTextAttribute(hstdoutLogo, 0xC0);										// Red bg, Black txt
	std::cout << " |    |  \\_/ __ \\\\__  \\\\   __\\  |  \\\t\t " << std::endl;
	std::cout << " |    `   \\  ___/ / __ \\|  | |   Y  \\\t\t " << std::endl;
	std::cout << "/_______  /\\___  >____  /__| |___|  /\t\t " << std::endl;
	std::cout << "        \\/     \\/___  \\/      __  \\/     .__\t " << std::endl;

	// Match
	SetConsoleTextAttribute(hstdoutLogo, 0xC0);										// Red bg, Black txt
	std::cout << "\t      /     \\ _____ _/  |_  ____ |  |__\t " << std::endl;
	std::cout << "\t     /  \\ /  \\\\__  \\\\   __\\/ ___\\|  |  \\ " << std::endl;
	std::cout << "\t    /    Y    \\/ __ \\|  | \\  \\___|   Y  \\" << std::endl;
	SetConsoleTextAttribute(hstdoutLogo, 0xC7);										// Red bg, Grey txt
	std::cout << " K00203642";
	SetConsoleTextAttribute(hstdoutLogo, 0xC0);										// Red bg, Black txt
	std::cout << "  \\____|__  (____  /__|  \\___ > ___|  /" << std::endl;
	SetConsoleTextAttribute(hstdoutLogo, 0xC7);										// Red bg, Grey txt
	std::cout << " Joe O'Regan";
	SetConsoleTextAttribute(hstdoutLogo, 0xC0);										// Red bg, Black txt
	std::cout << "        \\/     \\/          \\/     \\/ " << std::endl;

	// Press Enter To Continue
	SetConsoleTextAttribute(hstdoutLogo, 0x0C);										// White BG, Red text				
	std::cout  << "\n\t     Press Enter To Continue\t\t " << std::endl;
	SetConsoleTextAttribute(hstdoutLogo, 0x0F);										// Reset colour Black bg, White txt	
	std::cin.get();	// Wait for input

	// Reset colours
	FlushConsoleInputBuffer(hstdinLogo);
	SetConsoleTextAttribute(hstdoutLogo, csbi.wAttributes);
}

/*	2016-11-29:
	Display the level 1 logo
*/
void Logo::drawLevel1()
{
	std::cout << "\t\t    .____                      .__     ____ \t\t\t     " << std::endl;
	std::cout << "\t\t    |    |    _______  __ ____ |  |   /_   |\t\t\t     " << std::endl;
	std::cout << "\t\t    |    |  _/ __ \\  \\/ // __ \\|  |    |   |\t\t\t     " << std::endl;
	std::cout << "\t\t    |    |__\\  ___/\\   /\\  ___/|  |__  |   |\t\t\t     " << std::endl;
	std::cout << "\t\t    |_______ \\___  >\\_/  \\___  >____/  |___|\t\t\t     " << std::endl;
	std::cout << "\t\t            \\/   \\/          \\/             \t\t\t     " << std::endl;
	std::cout << "\t\t\t\t\t\t\t\t\t\t     " << std::endl;
}

/*	2016-11-29:
	Display the level 2 logo
*/
void Logo::drawLevel2() {
	std::cout << "\t\t.____                      .__    ________  \t\t\t     " << std::endl;
	std::cout << "\t\t|    |    _______  __ ____ |  |   \\_____  \\ \t\t\t     " << std::endl;
	std::cout << "\t\t|    |  _/ __ \\  \\/ // __ \\|  |    /  ____/ \t\t\t     " << std::endl;
	std::cout << "\t\t|    |__\\  ___/\\   /\\  ___/|  |__ /       \\ \t\t\t     " << std::endl;
	std::cout << "\t\t|_______ \\___  >\\_/  \\___  >____/ \\_______ \\\t\t\t     " << std::endl;
	std::cout << "\t\t        \\/   \\/          \\/               \\/\t\t\t     " << std::endl;
	std::cout << "\t\t\t\t\t\t\t\t\t\t     " << std::endl;
}

/*	2016-11-29:
	Display the level 3 logo
*/
void Logo::drawLevel3() {
	std::cout << "\t\t.____                      .__    ________  \t\t\t     " << std::endl;
	std::cout << "\t\t|    |    _______  __ ____ |  |   \\_____  \\ \t\t\t     " << std::endl;
	std::cout << "\t\t|    |  _/ __ \\  \\/ // __ \\|  |     _(__  < \t\t     " << std::endl;
	std::cout << "\t\t|    |__\\  ___/\\   /\\  ___/|  |__  /       \\\t\t\t     " << std::endl;
	std::cout << "\t\t|_______ \\___  >\\_/  \\___  >____/ /______  /\t\t\t     " << std::endl;
	std::cout << "\t\t        \\/   \\/          \\/              \\/ \t\t\t     " << std::endl;
	std::cout << "\t\t\t\t\t\t\t\t\t\t     " << std::endl;
}
/*	2016-11-29:
	Display the level complete logo
	This is called from the GameOver() function in Game
	When a level is complete, after the level number is
	displayed
*/
void Logo::drawComplete() {
	std::cout << "\t     _________                       .__          __          \t\t     " << std::endl;
	std::cout << "\t     \\_   ___ \\  ____   _____ ______ |  |   _____/  |_  ____  \t\t     " << std::endl;
	std::cout << "\t     /    \\  \\/ /  _ \\ /     \\\\____ \\|  | _/ __ \\   ___/ __ \\ \t\t     " << std::endl;
	std::cout << "\t     \\     \\___(  <_> |  Y Y  |  |_> |  |_\\  ___/|  | \\  ___/ \t\t     " << std::endl;
	std::cout << "\t      \\______  /\\____/|__|_|  |   __/|____/\\___  |__|  \\___  >\t\t     " << std::endl;
	std::cout << "\t             \\/             \\/|__|             \\/          \\/ \t\t     " << std::endl;
	std::cout << "\t\t\t\t\t\t\t\t\t\t     " << std::endl;
}
// Draw Game Over Logo
void Logo::drawGameOver()
{
	std::cout << "\t  ________                          \t " << std::endl;
	std::cout << "\t /  _____/ _____     _____    ____  \t " << std::endl;
	std::cout << "\t/   \\  ___ \\__  \\   /     \\ _/ __ \\ \t " << std::endl;
	std::cout << "\t\\    \\_\\  \\ / __ \\_|  Y Y  \\\\  ___/ \t " << std::endl;
	std::cout << "\t \\______  /(____  /|__|_|  / \\___  >\t " << std::endl;
	std::cout << "\t________\\/      \\/       \\/      \\/ \t " << std::endl;
	std::cout << "\t\\_____  \\  ___  __  ____  _______   \t " << std::endl;
	std::cout << "\t /   |   \\ \\  \\/ /_/ __ \\ \\_  __ \\  \t " << std::endl;
	std::cout << "\t/    |    \\ \\   / \\  ___/  |  | \\/  \t " << std::endl;
	std::cout << "\t\\_______  /  \\_/   \\___  > |__|     \t " << std::endl;
	std::cout << "\t        \\/             \\/           \t " << std::endl;
}

// Draw Loser Logo
void Logo::drawLoser()
{
	std::cout << "    .____                                     \t " << std::endl;
	std::cout << "    |    |      ____    ______  ____  _______ \t " << std::endl;
	std::cout << "    |    |     /  _ \\  /  ___/_/ __ \\ \\_  __ \\\t " << std::endl;
	std::cout << "    |    |___ (  <_> ) \\___ \\ \\  ___/  |  | \\/\t " << std::endl;
	std::cout << "    |_______ \\ \\____/ /____  > \\___  > |__|   \t " << std::endl;
	std::cout << "            \\/             \\/      \\/         \t " << std::endl;
	std::cin.get();	// Wait for input
}

// Draw Winner Logo
void Logo::drawWinner()
{
	std::cout << "  __      __ .__                                 " << std::endl;
	std::cout << " /  \\    /  \\|__|  ____    ____    ____  _______ " << std::endl;
	std::cout << " \\   \\/\\/   /|  | /    \\  /    \\ _/ __ \\ \\_  __ \\" << std::endl;
	std::cout << "  \\        / |  ||   |  \\|   |  \\\\  ___/  |  | \\/" << std::endl;
	std::cout << "   \\__/\\  /  |__||___|  /|___|  / \\___  > |__|   " << std::endl;
	std::cout << "        \\/            \\/      \\/      \\/         " << std::endl;
	std::cin.get();	// Wait for input
}

void Logo::drawName()
{
	std::cout << "\t\t    A Game By             " << std::endl;
	std::cout << "                  ____.                     " << std::endl;
	std::cout << "                 |    | ____   ____         " << std::endl;
	std::cout << "                 |    |/  _ \\_/ __ \\       " << std::endl;
	std::cout << "             /\\__|    (  <_> )  ___/        " << std::endl;
	std::cout << "             \\________|\\____/ \\___  >       " << std::endl;
	std::cout << "                    ________/\\    \\/        " << std::endl;
	std::cout << "                    \\_____  )/              " << std::endl;
	std::cout << "                     /   |   \\              " << std::endl;
	std::cout << "                    /    |    \\             " << std::endl;
	std::cout << "                    \\_______  /             " << std::endl;
	std::cout << "      __________            \\/              " << std::endl;
	std::cout << "      \\______   \\ ____   _________    ____  " << std::endl;
	std::cout << "       |       _// __ \\ / ___\\__  \\  /    \\ " << std::endl;
	std::cout << "       |    |   \\  ___// /_/  > __ \\|   |  \\" << std::endl;
	std::cout << "       |____|_  /\\___  >___  (____  /___|  /" << std::endl;
	std::cout << "              \\/     \\/_____/     \\/     \\/ " << std::endl;
	std::cin.get();	// Pause The Screen
}