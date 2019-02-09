/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/

/*	2016-12-04:
	Add coloured text, moved the player directional infomation from the Player class
	Added friend functions to calculate and display the players stats for skill,
	strength, and luck

	2016-11-30:
	As the amount of dialogue int the game was starting to build up,
	I thought it was best to separate it out into it's own Class.
	In this file is most of the "story" in the game.

	Any prompts the player may receive to interact with, or from
	interacting with other game objects is to be dumped in here
	in no particular order. As I've already the story for level 1
	done, I suppose it would be for the best to sort it by level.

	I changed the orignal class name from JibberJabber to Gab, actually
	no I'm going to call it Spiel. It definitely needs to be a shorter
	name than JibberJabber in any case.
*/

#include "Spiel.h"

/* Game Text, Story and Colour Formatting */

void Spiel::getStory(int story)
{
	GetConsoleScreenBufferInfo(hstdoutSp, &csbi);	// Keep track of original colours

	if (story == 1)
		l1Story1();
	else if (story == 2) {
		ClearScreen();
		l1Story2();
		ClearScreen();
		l1Story3();
		ClearScreen();
		l1Story4();
		ClearScreen();
	}

	// Reset colours
	FlushConsoleInputBuffer(hstdinSp);
	SetConsoleTextAttribute(hstdoutSp, csbi.wAttributes);
}

void Spiel::l1Story1()
{


	SetConsoleTextAttribute(hstdoutSp, 0x9F);			// Blue bg, White txt
	logo.drawLevel1();									// Display level 1 logo
	SetConsoleTextAttribute(hstdoutSp, 0x0F);			// Black bg, White txt

	std::cout << "\n  You have been invited to the neighbouring kingdom. A truce is in place between" << std::endl;
	std::cout << "  your father the king and the neighbour king of the eastern kingdom. To celebrate" << std::endl;
	std::cout << "  the 7th year without hostility, a feast is to be thrown, in the eastern capitol," << std::endl;
	std::cout << "  with you the prince of west Imaginarygameland as an honoured guest." << std::endl;

	std::cout << "\n  Before you set out on the journey a local wizard has granted you some potions." << std::endl;
	std::cout << "  You must play him at his favourite dice game before he will part with them." << std::endl;
	std::cout << "  The three potions he will grant you will increase your Skill, Strength and Luck" << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
	ClearScreen();
}

/*	2016-12-04:
	calculate the players skill, strength and luck stats using the 
	friend functions wizardLuck, wizardSkill, and wizardStrength 
	and display the stats with friend function displaystats
*/
int wizardLuck(int luck)
{
	Logo logo;
	HANDLE hstdOut;
	hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int	die1 = (rand() % 6) + 1;										// generate random number for dice		
	int die2 = (rand() % 6) + 1;
	int newLuck;

	SetConsoleTextAttribute(hstdOut, 0x9F);								// Blue bg, White txt
	logo.drawLevel1();													// Display level 1 logo
	SetConsoleTextAttribute(hstdOut, 0x0F);								// Black bg, White txt

	std::cout << "\n  To roll the dice to see the luck the wizard will grant you, press ENTER";
	std::cin.get();														// Pause the screen
	std::cout << "  Player rolled a " << die1 << " and a " << die2 << std::endl;
	newLuck = luck + ((die1 + die2) * 5);								// Calculate the Luck points
	std::cout << "  Your luck has increased to " << newLuck << " units of poxiness" << std::endl;
	std::cout << "  (Poxiness has been the standard measure of luck for generations in your kingdom)" << std::endl;
	SetConsoleTextAttribute(hstdOut, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdOut, 0x0F);
	std::cin.get();
	ClearScreen();

	return newLuck;														// Return the new luck value
}

int wizardStrength(int strength)
{
	Logo logo;
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int	die1 = (rand() % 6) + 1;										// generate random number for dice		
	int die2 = (rand() % 6) + 1;
	int newStrength;

	SetConsoleTextAttribute(hStdOut, 0x9F);								// Blue bg, White txt
	logo.drawLevel1();													// Display level 1 logo
	SetConsoleTextAttribute(hStdOut, 0x0F);								// Black bg, White txt

	std::cout << "\n  To roll the dice to see the strength you will be granted, press ENTER";
	std::cin.get();														// Pause the screen
	std::cout << "  Player rolled a " << die1 << " and a " << die2 << std::endl;
	newStrength = strength + ((die1 + die2) * 5);								// Calculate the Luck points
	std::cout << "  You feel the power increase. The wizard says it is " << newStrength << " units of Schwarzenegger." << std::endl;
	std::cout << "  (The Schwarzenegger plant has been known to affect the users accent)" << std::endl;
	SetConsoleTextAttribute(hStdOut, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hStdOut, 0x0F);
	std::cin.get();
	ClearScreen();

	return newStrength;														// Return the new luck value
}

int wizardSkill(int skill)
{
	Logo logo;
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int	die1 = (rand() % 6) + 1;										// generate random number for dice		
	int die2 = (rand() % 6) + 1;
	int newSkill;

	SetConsoleTextAttribute(hStdOut, 0x9F);								// Blue bg, White txt
	logo.drawLevel1();													// Display level 1 logo
	SetConsoleTextAttribute(hStdOut, 0x0F);								// Black bg, White txt

	std::cout << "\n  To roll the dice to see the skill the wizard will gift to you, press ENTER";
	std::cin.get();														// Pause the screen
	std::cout << "  Player rolled a " << die1 << " and a " << die2 << std::endl;
	newSkill = skill + ((die1 + die2) * 5);								// Calculate the Skill points
	std::cout << "  You have been granted a " << newSkill << " skill level." << std::endl;
	SetConsoleTextAttribute(hStdOut, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hStdOut, 0x0F);
	std::cin.get();
	ClearScreen();

	return newSkill;														// Return the new luck value
}

void displayStats(int skill, int strength, int luck)
{
	Logo logo;
	HANDLE hstdout;
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hstdout, 0x9F);			// Blue bg, White txt
	logo.drawLevel1();								// Display level 1 logo
	SetConsoleTextAttribute(hstdout, 0x0F);			// Black bg, White txt
	std::cout << "\n  You now have " << skill << " Skill, " << strength << " Strength, and " << luck << " Poxiness (or luck) points. " << std::endl << std::endl;
	std::cout << "  You thank the wizard for his kindness. He wishes you safe journey, and as a gift," << std::endl;
	std::cout << "  he offers one of the remaining potions. The choice of Skill, Strength, and Luck." << std::endl;
	SetConsoleTextAttribute(hstdout, 0x0C);			// Blue bg, White txt
	std::cout << "  Enter 1. for Skill, 2. for Strength, or 3. for Luck." << std::endl;
	SetConsoleTextAttribute(hstdout, 0x0F);			// Blue bg, White txt
	//choosePotion();
}


/*  2016-12-04:
	Made choosePotion a friend function shared with Game and Spiel, and moved to Spiel from Game
	2016-11-29:
	Player has a choice of potions granted to him by the wizard before embarking on his journey
*/
int choosePotion() {
	int potionChoice;								// 2016-11-29 CA2 - A choice of potions from the wizard
	std::cout << "  Enter your choice: " << std::endl;
	std::cin >> potionChoice;
	if (potionChoice > 0 && potionChoice < 4) {
		std::cout << "  The wizard agrees with your choice of ";
		if (potionChoice == 1) {
			std::cout << "Skill." << std::endl;
			std::cout << "  A prince needs Skill to master his handling of weaponry.";
		}
		else if (potionChoice == 2) {
			std::cout << "Strength. " << std::endl;
			std::cout << "  A prince needs Strength to deal stronger blows to any foe.";
		}
		else if (potionChoice == 3) {
			std::cout << "Luck." << std::endl;
			std::cout << "  A prince needs Luck on his side when his fate is uncertain.";
		}
	}
	else
		choosePotion();
	std::cin.get();
	std::cin.get();

	return potionChoice;
}

void Spiel::l1Story2()
{
	ClearScreen();
	SetConsoleTextAttribute(hstdoutSp, 0x9F);			// Blue bg, White txt
	logo.drawLevel1();									// Display level 1 logo
	SetConsoleTextAttribute(hstdoutSp, 0x0F);			// Black bg, White txt

	std::cout << "\n  You appreciate the wizards kindness. You bid farewell, safely storing the potion." << std::endl;
	std::cout << "  On returning to the castle, the king summons you immediately. You're set to begin" << std::endl;
	std::cout << "  the journey east immediately, you have been advised to travel unarmed." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
	ClearScreen();
}

void Spiel::l1Story3()
{
	SetConsoleTextAttribute(hstdoutSp, 0x9F);			// Blue bg, White txt
	logo.drawLevel1();									// Display level 1 logo
	SetConsoleTextAttribute(hstdoutSp, 0x0F);			// Black bg, White txt

	std::cout << "\n  You do not travel alone, the princess travels with you. The king tells you that. " << std::endl;
	std::cout << "  the eastern king has invited your soon to be bride, the northern king daughter," << std::endl;
	std::cout << "  so he may cast his eyes on her storied beauty, and meet the future western queen." << std::endl;

	std::cout << "\n  Your father believes it would be a wise move. The eastern king would not risk" << std::endl;
	std::cout << "  the wrath of the northern kingdom. You agree, concerned you also have to travel " << std::endl;
	std::cout << "  unarmed to avoid any risk of offending the eastern king. You hope the powers the" << std::endl;
	std::cout << "  wizard granted are enough, and you're wrong to worry about the princesses safety." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
}

void Spiel::l1Story4()
{
	SetConsoleTextAttribute(hstdoutSp, 0x9F);			// Blue bg, White txt
	logo.drawLevel1();									// Display level 1 logo
	SetConsoleTextAttribute(hstdoutSp, 0x0F);			// Black bg, White txt

	std::cout << "\n  Arriving at the feast, the hall is filled with the eastern lords and knights. As" << std::endl;
	std::cout << "  your companions are shown to their quarters, the eastern king calls you to his" << std::endl;
	std::cout << "  side. Soon the wine is flowing, you wonder what's taking your companions so long?" << std::endl;
	std::cout << "  You turn to ask the kings leave to go find the princess. As you turn you the room" << std::endl;
	std::cout << "  begins to spin. The muffled noise washes over you as you fall to the floor." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
}

// Displayed From Inside The Dungeon - with map in background
void Spiel::l1Story5()
{
	std::cout << "\n  You wake up suddenly, you are in unfamiliar surroundings, it's damp and dark, and" << std::endl;
	std::cout << "  you are not alone. You feel a bump on your head, realising you've been imprisoned." << std::endl;
	std::cout << "  There's a soldier guarding the door. You're trapped inside the castles dungeon." << std::endl;
	std::cout << "  You have to find a way out. Where is the princess? You must find her..." << std::endl;

	std::cout << "\n  You must challenge the enemy and see can you find a way to escape from the room. " << std::endl;
	std::cout << "  You must find out where they have taken the princess, then find your companions, " << std::endl;
	std::cout << "  and flee west to alert your father to this treachery." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
}
void Spiel::l1Story6()
{
	std::cout << "\n  You have a look around, you see a door, it's locked. The soldier must have the key." << std::endl;
	std::cout << "  Unsure if you will be able to overpower him, you look to sneak up on the guard whilst" << std::endl;
	std::cout << "  he wanders aimlessly about the cell. Judging by the way he bounces carelessly off the " << std::endl;
	std::cout << "  walls, he doesn't strike you as the sharpest chisel in the tool box." << std::endl;

	std::cout << "\n  There are 6 small windows, you are too well fed to fit through those. There is rushes" << std::endl;
	std::cout << "  thrown on the floor. You can't see much else scattered around the room, there looks " << std::endl;
	std::cout << "  to be some objects hanging from the walls, you cant make them out in the dim light. " << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to start the game..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
	ClearScreen();
}

/* LEVEL 2 STORY */

void Spiel::l2Story1()
{
	SetConsoleTextAttribute(hstdoutSp, 0x9F);			// Blue bg, White txt
	logo.drawLevel2();									// Display level 1 logo
	SetConsoleTextAttribute(hstdoutSp, 0x0F);			// Black bg, White txt

	std::cout << "\n  You have entered the banquet hall, the lights are off, you can hear some feint  " << std::endl;
	std::cout << "  noises coming from across the room. You can't see the way out, the windows are " << std::endl;
	std::cout << "  boarded up. You will need to find a way to brighten up the place." << std::endl;

	SetConsoleTextAttribute(hstdoutSp, 0x09);
	std::cout << "  PRESS ENTER to continue..." << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cin.get();
}

/* Hints Text */

void Spiel::hintLamp1() {
	std::cout << "\n  It's night time, it seems like one of the lamps is brighter than the others." << std::endl;
	std::cout << "  Remembering how dark the passages were when you arrived for the feast, you" << std::endl;
	std::cout << "  may require a lamp to help you with your escape. You never know what you " << std::endl;
	std::cout << "  could find lying around here if there was enough light. " << std::endl;
	std::cin.get();									// Pause the screen
	std::cin.get();									// Pause the screen
}
void Spiel::hintLamp2() {
	std::cout << "\n  You will need to try and remove one of the lamps from the wall if you are" << std::endl;
	std::cout << "  to find a weapon in here. Unfortunately the lamp itself looks too fragile " << std::endl;
	std::cout << "  to be used as a weapon. If these rushes were to catch fire on the floor " << std::endl;
	std::cout << "  you don't want to find out the hard way how flammable they are. " << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::hintSword() {
	std::cout << "\n  You notice something shining on the floor of the dungeon. But the light is" << std::endl;
	std::cout << "  too dim through the narrow windows to make out what it is. You will need to " << std::endl;
	std::cout << "  move closer to the object to inspect it with the light from the lamp. " << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::hintGuard() {
	std::cout << "\n  You take the lamp down from the wall, wondering what was the point of there" << std::endl;
	std::cout << "  being two right beside each other, when so much of the dungeon is in darkness. " << std::endl;
	std::cout << "  But then you look up and see that the decorators haven't touched these parts " << std::endl;
	std::cout << "  in quite some time. " << std::endl;
	std::cout << "\n  Best go talk to the guard. Maybe the two of you can make shadow puppets " << std::endl;
	std::cout << "  together or something, who knows what kind of game like stuff will happen" << std::endl;
	std::cout << "  once you've interacted with the only other visible creature in here." << std::endl;
	std::cout << "\n  You really should talk to the guard, just saying. " << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::hintGuardSpeed() {
	std::cout << "\n  You notice the guard has sped up to keep himself warm now that it's dark. " << std::endl;
	std::cout << "  He's no slouch for the size of him." << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::hintL2Lamps() {

	std::cout << "\n  There appears to be lamps on the walls. If they're the same as the lamps" << std::endl;
	std::cout << "  in the western castle, only one will need to be lit on each wall." << std::endl;
	std::cin.get();									// Pause the screen
}

/* Interactions Text */

void Spiel::interactionL1Guard1() {
	std::cout << "\n  You approach the guard to have a word, and see can you negotiate an escape." << std::endl;
	std::cout << "\n  You hadn't noticed how big the guard was until you got up close. You still feel" << std::endl;
	std::cout << "  weak after being unconscious. You decide against fighting the guard if it does" << std::endl;
	std::cout << "  prove to be futile trying to talk your way out of here." << std::endl;

	std::cout << "\n  \"Hey, big fella\", you address the guard \"When will I be leaving? I could do" << std::endl;
	std::cout << "  with getting out of here. How much would it cost for you to turn a blind eye?\"" << std::endl;
	std::cout << "  \"It will cost you your life, if you try and leave through that door before it" << std::endl;
	std::cout << "  is commanded by the king. And you would need to take my life before I give up" << std::endl;
	std::cout << "  the key.\"" << std::endl;
	std::cin.get();									// Pause the screen
	std::cin.get();									// Pause the screen
}
void Spiel::interactionL1Guard2() {
	std::cout << "\n  The conversation and the size of the guard don't inspire you with any hope" << std::endl;
	std::cout << "  of leaving the dungeon just yet. You will have to find a way to surprise or" << std::endl;
	std::cout << "  overpower the guard. Your head is still spinning, you could do with a weapon." << std::endl;
	std::cout << "\n  As you turn away feeling discouraged, you cast your eyes around the room..." << std::endl;
	std::cin.get();									// Pause the screen
}

void Spiel::interactionSword() {
	std::cout << "\n  You move to the shining object. Kicking aside the rushes you unearth a " << std::endl;
	std::cout << "  longsword, similar in size to the one the bozo guard is carrying. You don't " << std::endl;
	std::cout << "  stop too long to wonder is he dumb enough to have left his old sword lying  " << std::endl;
	std::cout << "  around on the floor here.  " << std::endl;
	std::cout << "\n  You inspect the sword, the steel is rusty, the edge is dull, but the end" << std::endl;
	std::cout << "  is still pointy. It doesn't look like they had any proper armour to fit the" << std::endl;
	std::cout << "  guard. You could take him in a fight." << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::interactionLamp() {
	std::cout << "\n  The lamp is hot, you burn yourself slightly trying to take it" << std::endl;
	std::cout << "  from the wall. You immediately regret taking it once you see " << std::endl;
	std::cout << "  the state of the place. Your OCD is really hitting you hard." << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::interactionTreasureChest() {
	std::cout << "\n  The player has discovered a treasure chest. Opening it immediately " << std::endl;
	std::cout << "  there is something inside  " << std::endl;
	std::cout << "\n  Press ENTER to find out what is in the chest...  " << std::endl;
	std::cin.get();									// Pause the screen
}
void Spiel::interactionKey() {
	std::cout << "\n  The player has discovered the key to the dungeon door. It's " << std::endl;
	std::cout << "  time to get out of here. " << std::endl;
	std::cout << "\n  Press ENTER to continue to Level 2  " << std::endl;
	std::cin.get();									// Pause the screen
}

/* Level Complete Text */
void Spiel::l1Complete() {
	std::cout << "\n  You defeat the guard, while he towers over you in size an strength, he lacks any" << std::endl;
	std::cout << "  technical training with his weapon. You hide the enemy body out of sight, and close" << std::endl;
	std::cout << "  the door. You have no idea when the guards will be changing over. You need to move " << std::endl;
	std::cout << "  quickly, before the other guards are alerted. " << std::endl;
	std::cout << "\n  You have escaped the dungeon, you now head towards the banquet hall in search of" << std::endl;
	std::cout << "  the princess and your companions, you need to find a way out of the castle." << std::endl;
	std::cin.get();									// Pause the screen
	ClearScreen();
}
void Spiel::l1CompleteKey() {
	std::cout << "\n  You see the key lying by the door, collect the key to exit the dungeon" << std::endl;
	std::cin.get();									// Pause the screen
	ClearScreen();
}

/* Battle */
void Spiel::battleBegin() {
	std::cout << "\n  The player engages the Dungeon Guard in combat, moving quickly to try and catch " << std::endl;
	std::cout << "  him off guard. " << std::endl;
	std::cout << "\n  GUARD: \"Puny man, you think you can defeat me?\" " << std::endl;
	std::cout << "\n  PLAYER: \"I'm a skilled swordsman I fancy my chances no matter what your size\" " << std::endl;
	std::cout << "\n  GUARD: \"I will cut you in half!!!\" " << std::endl;
	std::cout << "\n  To continue, Press ENTER";
	std::cin.get();									// Pause the screen
}
// Enemy Attacks
void Spiel::battle1() {
	std::cout << "\n  The Dungeon Guard strikes a blow" << std::endl;
	std::cout << "  You attempt to block the strike with the edge holding the sword with all your strength" << std::endl;
	std::cout << "\n  To roll the dice and see what your next move is, Press ENTER";
	std::cin.get();									// Pause the screen
}
// Player Attacks
void Spiel::battle2() {
	std::cout << "\n  Player lashes out with his sword" << std::endl;
	std::cout << "  Using your skill and speed you attack the Dungeon Guard" << std::endl;
	std::cout << "\n  To roll the dice and see what your next move is, Press ENTER";
	std::cin.get();									// Pause the screen
}

/* Display the player movement information */
void Spiel::playerMovementInfo()
{
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cout << "  ";								// Tab text in 2 spaces from left
	SetConsoleTextAttribute(hstdoutSp, 0x2F);		// green bg, white txt
	std::cout << " Please enter ";
	SetConsoleTextAttribute(hstdoutSp, 0x20);		// green bg, black txt
	std::cout << "\t7. NW\t   8. North\t9. NE\t\t";
	SetConsoleTextAttribute(hstdoutSp, 0x02);		// Black BG, Green txt
	std::cout << " Alter Player speed by entering a preceeding digit" << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cout << "  ";
	SetConsoleTextAttribute(hstdoutSp, 0x2F);
	std::cout << " Direction to ";
	SetConsoleTextAttribute(hstdoutSp, 0x20);		// green bg, black txt
	std::cout << "\t4. West\t   5. Stay \t6. East\t\t";
	SetConsoleTextAttribute(hstdoutSp, 0x02);		// Black BG, Green txt
	std::cout << " For example, entering 12, 22, 32.  (Range 1 to 4)" << std::endl;
	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cout << "  ";
	SetConsoleTextAttribute(hstdoutSp, 0x2F);
	std::cout << " Move Player\t ";
	SetConsoleTextAttribute(hstdoutSp, 0x20);		// green bg, black txt
	std::cout << "\t1. SW\t   2. South\t3. SE\t\t";
	SetConsoleTextAttribute(hstdoutSp, 0x02);		// Black BG, Green txt
	std::cout << " Where speed will equal 1, 2, or 3 the first digit" << std::endl;

	SetConsoleTextAttribute(hstdoutSp, 0x0F);
	std::cout << "  ";
	SetConsoleTextAttribute(hstdoutSp, 0xF2);		// White BG, Green txt
	std::cout << "\t\tThe Players Default Speed Is 4\t\t\t";
	SetConsoleTextAttribute(hstdoutSp, 0x02);		// Black BG, Green txt
	std::cout << " Direction will be 2, for North.  Default Speed: 4" << std::endl;
	std::cout << "  Enter Number(s): ";
	SetConsoleTextAttribute(hstdoutSp, 0x0F);		// black bg, white txt
}

/*  2016-12-04:
Made a friend function to share use between Game and Spiel classes
and moved from Game to Spiel class
CA2:
This code remains untouched from the previous assignment
CA1:
This function clears what was on the screen so the map can be redrawn
*/
void ClearScreen()
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