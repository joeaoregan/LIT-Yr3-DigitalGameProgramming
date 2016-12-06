// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

// Display a game logo at the start of game in init()

#include "Logo.h"

// Draw the game Log
void Logo::drawLogo()
{
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
	std::cin.get();

	// Reset colours
	FlushConsoleInputBuffer(hstdinLogo);
	SetConsoleTextAttribute(hstdoutLogo, csbi.wAttributes);
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
	std::cin.get();
}