// Joe O'Regan
// K00203642
// Digital Games Programming
// CA1

#ifndef LOGO_H
#define LOGO_H

#include <iostream>
#include <windows.h>	// for coloured text
#include <iomanip>		// add fill at start of coloured characters

class Logo
{
public:
	void drawLogo();		// Death Match Logo
	void drawGameOver();	// Game Over Logo
	void drawLoser();		// Loser Logo
	void drawWinner();		// Winner Logo
	void drawName();		// Really gone over-kill with the ASCII now

	// Colour Stuff
	HANDLE hstdinLogo = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdoutLogo = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif