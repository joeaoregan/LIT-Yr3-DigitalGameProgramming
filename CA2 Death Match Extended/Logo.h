/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-11-29:
	Added Level logos, and a complete logo to display at the end of each level
*/
#ifndef LOGO_H
#define LOGO_H

#include <iostream>
#include <windows.h>		// for coloured text

class Logo
{
public:
	void drawLogo();		// Death Match Logo
	void drawGameOver();	// Game Over Logo
	void drawLoser();		// Loser Logo
	void drawWinner();		// Winner Logo
	void drawName();		// Really gone over-kill with the ASCII now

	/* CA 2 */
	void drawLevel1();		// Logo for level 1
	void drawLevel2();		// Logo for level 2
	void drawLevel3();		// Logo for level 3
	void drawComplete();	// Level Complete Message
	//void drawBossLevel();

	// Colour Stuff
	HANDLE hstdinLogo;
	HANDLE hstdoutLogo;
};

#endif