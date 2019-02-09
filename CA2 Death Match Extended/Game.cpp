/*	Joe O'Regan
	K00203642
	Digital Games Programming Principles
	Assignment 2
*/
/*	2016-12-04:	
	Added a story screen to level 2, hinting that they must light the lamps on the wall

	Set up the lights in level 2 so they turn on when the player occupies the same coordinates. When all 4 sets of 
	lights are on, the enemy knights awaken.

	Made ClearScreen a friend function so it can also be used in Spiel class
	Made 3 friend functions wizardSkill, wizardStrength, and wizardLuck to move the random stat generation test to Spiel
	and also displayStats which displays the improved player stats and then calls choosePotion so the player can 
	add a potion to their inventory

	2016-12-01
	Added a visual indicator for the length of time a treasure chest till be available on screen. A red bar counts down
	from 10 to 1 and disappears when the treasure lifespan has expired.

	Adjusted the positions of the stat and health bars, altering the number of bars needed for each level so only the bars
	that are needed, depending on the number of enemies are displayed. Also added, a check for lights being on in level 2
	the enemies aren't visible in the Banquet Hall until the lamps have been lit.

	Added a more advanced combat system, which utilised the Skill, Strength and Luck stats added for CA2
	Player uses Skill and Luck points in avoiding damage being inflicted
	Player uses Strength points when inflicting damage on the Enemy
	The player rolls a dice to decide the outcome of an attack, whether a blow is landed or defended, or avoided completely
	The dice is rolled again to decide the damage to be inflicted. The luck points used also depend on the outcome of the 
	dice roll, and also the skill points when attacking. When defending skill and strength points are calculated based on 
	a number between 1 and 5 for skill, and a number between 1 and 10 for Strength, this number depends on the level of
	Skill and Strength points a player has, and both are taken from the Enemys health total
	
	Add random spawning times for Treasure Chests
	The treasure chest will only be displayed for a period of time, decided by the lifespan assigned to it on creation
	It will spawn when the spawn time matches the loop count, and disappear when the killtime matches the loopcount
	
	In the loopCounter() function, when the loopCount is updating between daytime and nightime
	the Enemy speed is also increased. When it is daytime it decreases.

	Changed the spawn point of the player, to the doorway entrance of each level

	Added a potion object to list of Game Objects, the player is granted it by the wizard at the beginning 
	of level 1. I added 4 different potions 1 for each stat.

	Doubled the amount of luck to be deducted for getting burned by lamps. Need to find a way
	for the stats to be used up, or no point having them. changed from 5 - burned amount to
	10 - (burned amount * 2) I left health the way it is.
	
	The lamp is drawn in the same position as one of the regular wall lamps in the dungeon
	If the player collects the lamp he can use it to find the sword
	It may also come in useful once I've had some more bright ideas << Yes, I did a lamp joke

	If the Player and Enemy occupy the same coordinates, and the player has a sword,
	The Player and Enemy can then do battle. Otherwise the Enemy will interact with
	the player, and laugh at his futile attempt to fight an armed soldier.

	Added hints to the update function so the player knows to interact with objects 
	in the game. A hint is dropped that a lamp might be needed, suggesting to the 
	player that he should find a way to pick up the lamp.

	In the interact() function, if the player occupies the coordinates of a static game object
	He can interact with it. This is similar to the battle() function but instead of trying to kill 
	a Game Object, the player decides whether to add it to his inventory

	If a Player or Enemy game object moves into the same coordinates as a lamp in the dungeon it is 
	burned by the lamp and loses up to 5 health points. The amount the player loses is based on luck, 
	and the differce between 5 and amound burned is deducted from the players luck stats
	The Enemy loses 5 points every time it walks into a flame/lamp
	Once the player has picked up the "Lamp" Game Object he is no longer burned as he has learned how to handle fire

	Before the player can do battle with an enemy he must first have a weapon.
	The sword will appear after the player first interacts with the enemy by occupying the
	same coordinates as the enemy. The players hasSword will be activated as soon as the player
	picks up a sword, the player can then proceed to fight the enemy.

	If the player doesn't have a lamp and just so happens to be standing right where the Game Object Lamp might be
	He might as well pick it up. And then he can go make shadow puppets or whatever

	2016-11-29:
	Set the enemy positions in each level, with 1 enemy in the dungeon level (Level 1)
	2 enemies in the Banquet Hall (Level 2), 3 enemies in the Maiden Tower (Level 3),
	and the Boss Level takes place in the Castle Arena (Level 4), where there is a Boss
	Enemy and a number of henchmen.

	Add stat bars to display the stats for a player object including the skill and luck stat level
	Added 5 new enemy with 8 charachter health bars, and a boss with a 32 character health bar

	Fixed some formatting and text layout errors to do with the name "Boss" being less characters than "EnemyN"

	Moved the loopCount increment form the LoopCounter() function, so the screen can 
	be redrawn to display story messages, without incrementing the loop, which affects
	Game Object movement, and may also affect other events I hope to implement

	Added separate setup function for level 1 of the game that's called from init()
	Start the game by giving the player some background story
	Player has a choice of potions granted to him by the wizard before embarking on his journey

	The health bars for the player and 9 enemies, including the boss, are now displayed
	at the top of the screen. Also, stat bars for the player for skill, strength and luck
	when the displayStatBars() function is called.

	Added more doors to the other rooms on the map

	2016-11-28:
	Added randomly generated stats for Skill, Strength, and Luck. When the game begins the Player meets 
	with a wizard who plays him at a game of dice, the amount for each attribute is added based on the 
	number he rolls in the dice, this is added to his default minimum total of 100 for each

	Added, display if night or day and the current level for the player, text at top of screen

	Updated the draw() function so the sword is presented in torquise and it now points in all directions
	not just east and west. This was hard as there was many other similar characters already on the grid
	from the background writing.

	Added a door to the west side of the map, the player must unlock the door by defeating the enemy
	and retrieving the key, before he can progress to the next level

	If the enemy has been defeated and the player has all the items necessary to complete the level
	Draw the key Object

	Draw the additional 2D array grids for Dungeon, Banquet Hall, Maiden Tower, and The Areana 
	including windows, door, lamps, swords, treasure chests, and any other game objects required
	
	2016-11-27:
	Updated the function to draw the players sword pointing in the direction the player is facing,
	This gives the player a visual indication of the direction the player is heading in.
	Added 3 more grids to the display, the 4 grids are now representing 4 levels
	
	2016-11-24:
	Added 4 more enemy objects and a boss enemy object
	Also added a treasure chest and a sword
	Treasure chests will contain random power ups
	Swords will increase the players ability to defeat enemies

	Added check for the coordinates of each object, to make sure none are spawned with the same coordinates
*/

#include "Game.h"

#define LARGE_BAR 32
#define SMALL_BAR 8
//#define HOURS_PER_DAY 24		// Original values
//#define DAYLIGHT_HOURS 12
#define HOURS_PER_DAY 6			// Test values
#define DAYLIGHT_HOURS 3	
#define INITIAL_STAT_VALUE 100	// Value of Skill, Strength, and Luck assigned to Player before drinking wizards postion
#define NIGHT_SPEED 3
#define DAY_SPEED 1

bool testMode = false;			// Set true to test without story / true to skip over story, at beginning of level 1
bool testBattle = false;		// Test the battle sequence by setting true

static int loopCount = 1;		// Counts the number of times the game loop has run
static int level = 1;			// The current game level

Player* pPlayer = new Player();
TreasureChest* pTreasureChest = new TreasureChest();

/*	2016-11-29:
	Added separate setup functions for each level of the game.
	2016-11-24:
	Added 4 more enemy objects and a boss enemy object
	Also added a treasure chest and a sword
	Treasure chests will contain random power ups
	Swords will increase the players ability to defeat enemies
	CA1:
	Create the objects & assign values
	1 player object and 4 enemy objects are created
	The objects are spawned, setting the values for health, speed,
	and their x and y coordinates for their position on the map
	The objects are then added to a list of game objects
*/
void Game::init() {
	//system("mode CON: COLS=204");				// Set console window width
	setGameResult(Undecided);					// The game result hasn't been decided yet

	/* Level 1 */
	pPlayer->spawn("Player", 160, 4, 12, 12);	// Player is spawned at coordinates (12, 12), in the centre of the screen
	listOfGameObjects.push_back(pPlayer);
	/* 2016-11-30 Initial values for Skill, Strength and Luck are set */
	pPlayer->setSkill(INITIAL_STAT_VALUE);
	pPlayer->setStrength(INITIAL_STAT_VALUE);
	pPlayer->setPoxiness(INITIAL_STAT_VALUE);

	l1EnemyInteraction = false;					// The player has not yet interacted with the guard
	L2LightsOn = true;
	srand(static_cast<unsigned int>(time(0)));	// Seed the random number
	revealL2Map = false;						// Set to true when map found in treasure chest
	pEnemy1 = new Enemy();
	// create the objects
	pLamp =		new TreasureChest();
	pMap =		new TreasureChest();
	pPotion =	new TreasureChest();
	pKey =		new GameObject();
	pSword =	new Weapon();

	/* Level 2*/
	knightsAwake = false;
	pEnemy2 = new Enemy();
	pEnemy3 = new Enemy();

	/* Level 3 */
	pEnemy4 = new Enemy();
	pEnemy5 = new Enemy();
	pEnemy6 = new Enemy();
	pEnemy7 = new Enemy();
	pEnemy8 = new Enemy();
	pEnemy9 = new Enemy();
	

	/* Begin the game by drawing the game ASCII text logos  at the beginning of level 1*/
	if (level == 1) {
		if (!testMode) {		// Skip for testing
			logo.drawLogo();	// Display Game Logo
			logo.drawName();	// More Logo stuff
			ClearScreen();		// Clear the screen	before the game map is drawn
		}
	

		/* CA2 - randomly assign player stats for skill, strength and luck */
		level1Setup();
	}
	/* Enemies spawned at random coordinates */
	else if (level == 2) {
		level2Setup();
	} 
	else if (level == 3) {
		//pPlayer->setHasSword(true);
		pPlayer->setX(1);						// Spawn the player in the doorway of the Maiden Tower
		pPlayer->setY(1);
		pEnemy4->spawn("Enemy 4", 110, 4);
		uniqueCoords(pEnemy4);
		listOfGameObjects.push_back(pEnemy4);
		pEnemy5->spawn("Enemy 5", 120, 1);
		uniqueCoords(pEnemy5);
		listOfGameObjects.push_back(pEnemy5);
		//listOfEnemies.push_back(pEnemy5);
		pEnemy6->spawn("Enemy 6", 130, 2);
		uniqueCoords(pEnemy6);
		listOfGameObjects.push_back(pEnemy6);
	} 
	else if (level == 4) {
		//pPlayer->setHasSword(true);
		pPlayer->setX(1);						// Spawn the player in the doorway of the Boss Level
		pPlayer->setY(23);
		pEnemy7->spawn("Enemy 7", 140, 3);
		uniqueCoords(pEnemy7);
		listOfGameObjects.push_back(pEnemy7);
		//listOfEnemies.push_back(pEnemy7);
		pEnemy8->spawn("Enemy 8", 150, 4);
		uniqueCoords(pEnemy8);
		listOfGameObjects.push_back(pEnemy8);
		//listOfEnemies.push_back(pEnemy8);
		pEnemy9->spawn("Boss", 160, 4);
		uniqueCoords(pEnemy9);
		listOfGameObjects.push_back(pEnemy9);
		//listOfEnemies.push_back(pEnemy9);
	}		
}

/*	2016-11-29:
	Start the game by giving the player some background story 
*/
void Game::level1Setup() {
	pPlayer->setHasSword(false);				// The player has no sword when the level begins
	pPlayer->setHasLamp(false);					// The player has no lamp when the level begins
	hasKey = false;

	/* Spawn the Gaoler Enemy Object For Level 1 */
	pEnemy1->spawn("Gaoler ", 125, 1);			// Level 1: Soldier guarding the prince as he is imprisoned in the dungeon
	uniqueCoords(pEnemy1);
	listOfGameObjects.push_back(pEnemy1);
	//listOfEnemies.push_back(pEnemy1);
	
	/*	2016-11-24:
		Weapons & Powerups on static list of objects
		May also need to include on gameobjects list for checks
	*/	
	/* TREASURE CHEST */
	pTreasureChest->spawn("Treasure", 160, 4);
	pTreasureChest->setLifespan(10);
	uniqueCoords(pTreasureChest);

	treasureSpawnTime = (rand() % 11 + 5);	// Random number between 5 and 15
	//treasureSpawnTime = 2;						// TEST - Treasure Chest
	treasureKillTime = treasureSpawnTime + (*pTreasureChest).getLifespan();
	listOfGameObjects.push_back(pTreasureChest);
	listOfCollectables.push_back(pTreasureChest);

	/* MAP */
	pMap->spawn("Map L2", (*pTreasureChest).getX(), (*pTreasureChest).getY());
	listOfCollectables.push_back(pMap);
	/* POTION */
	pPotion->spawn("Potion", (*pTreasureChest).getX(), (*pTreasureChest).getY());
	listOfCollectables.push_back(pPotion);
	/* KEY */
	pKey->spawn("Key", 160, 4, 23, 14);					// Spawn a key near the door, when enemy dies
	listOfGameObjects.push_back(pKey);
	listOfCollectables.push_back(pKey);


	/*	2016-11-24:
		Create a sword object and randomly assign it unique coordintes
	*/
	/* SWORD */
	pSword->spawn("Sword", 160, 4);
	uniqueCoords(pSword);
	listOfGameObjects.push_back(pSword);
	listOfCollectables.push_back(pSword);

	/* LAMP */
	/*	2016-11-30:
		Create a Lamp object and assign it a random position amongst the other lamps on the dungeon walls 
		each time the game starts. The Lamp will be positioned on the north or south walls and drawn in 
		white.
	*/
	pLamp->spawn("Lamp", 160, 4);
	int lampPos = (rand() % 4 + 1);
	if (lampPos == 1) {
		(*pLamp).setX(4);
		(*pLamp).setY(1);
	}
	else if (lampPos == 2) {
		(*pLamp).setX(20);
		(*pLamp).setY(1);
	}
	else if (lampPos == 3) {
		(*pLamp).setX(4);
		(*pLamp).setY(23);
	}
	else if (lampPos == 4) {
		(*pLamp).setX(20);
		(*pLamp).setY(23);
	}
	listOfGameObjects.push_back(pLamp);
	listOfCollectables.push_back(pLamp);

		
	/* GAME STORY */
	if (!testMode) {									// If the game is not in test mode display the story
		spiel.getStory(1);								// Part 2 of the story

		/*	2016-12-04:
			Use the friend function wizardLuck to output the text for setting the random stats
			The improved stats for the player are then displayed and the player chooses a
			postion to carry with him
		*/
		(*pPlayer).setPoxiness(wizardLuck((*pPlayer).getPoxiness()));
		(*pPlayer).setSkill(wizardSkill((*pPlayer).getSkill()));
		(*pPlayer).setStrength(wizardStrength((*pPlayer).getStrength()));
		displayStats((*pPlayer).getSkill(), (*pPlayer).getStrength(), (*pPlayer).getPoxiness());
		/* Choose a potion to add to the players inventory */
		int potion = choosePotion();
		if (potion == 1)
			pPotion->spawn("Skill Potion", 0, 0);
		else if (potion == 2)
			pPotion->spawn("Strength Potion", 0, 0);
		else if (potion == 3)
			pPotion->spawn("Luck Potion", 0, 0);

		inventory.push_back(pPotion);

		spiel.getStory(2);								// Part 2 of story

		// Draw the map and continue with the story
		draw();
		spiel.l1Story5();								// Part 5 of the story.	
		draw();
		spiel.l1Story6();								// Part 6 of the story
	}
}

/* Start level 2 with the lights off, player turns on the 4 sets of lights to wake the enemy knights*/
void Game::level2Setup()
{
	revealL2Map = true;
	pPlayer->setHasSword(true);
	pPlayer->setHasLamp(true);
	pPlayer->setX(1);						// Spawn the player in the doorway fo the Banquet Hall
	pPlayer->setY(12);
	pEnemy2->spawn("Sir Tom", 90, 2);
	uniqueCoords(pEnemy2);
	listOfGameObjects.push_back(pEnemy2);
	pEnemy3->spawn("Sir Bob", 100, 3);
	uniqueCoords(pEnemy3);
	listOfGameObjects.push_back(pEnemy3);

	if (!testMode) {									// If the game is not in test mode display the story
		spiel.l2Story1();
		draw();
		spiel.hintL2Lamps();
	}
}
/* 24-11-2016:
	Check the coordinates of each object and make sure none are spawned with the same coordinates
*/
void Game::uniqueCoords(GameObject* objectToCheck)
{
	objectToCheck->setRandomCoords();
	//std::cout << objectToCheck->getID() << " X: " << objectToCheck->getX() << " Y: " << objectToCheck->getY() << " ";
	/* CHECK RANDOM COORDS FOR ENEMIES */
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		if (objectToCheck->getX() == (*it)->getX() && objectToCheck->getX() == (*it)->getY() && (*it)->getID() != objectToCheck->getID())
			objectToCheck->setRandomCoords();
	}
}

/*	2016-08-29:
	The health bars for the player and 9 enemies, including the boss, are now displayed 
	at the top of the screen. Also, stat bars for the player for skill, strength and luck
	when the displayStatBars() function is called.
	CA1:
	cycle through the enemy & player objects & call draw() for each object
	The loop counter is displayed at the top of the screen, indicating the number of times
	the loop has run, and also the number of moves the player has made, and therefore the 
	number of moves the player has left, with a maximum loop count of 20
	The health bars for player and enemy objects are displayed at the top of the screen.
	The grid showing the positions of the enemy and playe objects is draw.
	The draw function is then called for each of the game objects displaying the objects
	name and coordinates
*/
void Game::draw() {	
	GetConsoleScreenBufferInfo(hstdout, &csbi);	// Keep track of original colours

	ClearScreen();								// Clear the screen

	LoopCounter();								// Display number of times game has looped

	displayStatsBars();							// Display Player Health Bar	

	drawGrid();									// Draw the grid displaying game object positions

	std::list<GameObject*>::const_iterator it;	// iterator for Game Objects list

												// Cycle through the enemy & player objects and call the draw function for each object

	/* PRINT THE GAME OBJECTS */
	std::cout << "  Game Objects: ";
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		std::cout << (*it)->getID() << ", ";
	}
	std::cout << std::endl;

	/* PRINT THE COLLECTABLES */
	std::cout << "  Collectables: ";
	for (it = listOfCollectables.begin(); it != listOfCollectables.end(); it++)
	{
		std::cout << (*it)->getID() << ", ";
	}
	std::cout << std::endl;

	/* PRINT THE PLAYERS INVENTORY */
	std::cout << "  Inventory: ";
	for (it = inventory.begin(); it != inventory.end(); it++)
	{
		std::cout << (*it)->getID() << ", ";
	}
	std::cout << std::endl;

	/* if all the lights are on, wake up the 2 enemy knights */
	if (lamp1Lit == true && lamp2Lit == true && lamp3Lit == true && lamp4Lit == true)
		knightsAwake = true;

	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		if (((*it)->getID() == "Sir Tom" || (*it)->getID() == "Sir Bob") && knightsAwake == false)
			continue;
		else if ((*it)->getID() != "Sword" && (*it)->getID() != "Treasure" && (*it)->getID() != "Lamp" && (*it)->getID() != "Skill Potion" && (*it)->getID() != "Strength Potion" && (*it)->getID() != "Luck Potion" && (*it)->getID() != "Key" && (*it)->getID() != "Potion") {
			SetConsoleTextAttribute(hstdout, 0x0F);					// Black bg, White txt
			std::cout << "  ";
			SetConsoleTextAttribute(hstdout, 0x81);					// Grey bg, Navy txt
			(*it)->draw();
		}
	}

	// Reset colours
	FlushConsoleInputBuffer(hstdin);
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}

/*	2016-11-30:
	Added hints to the update function so the player knows to interact with objects 
	in the game. A hint is dropped that a lamp might be needed, suggesting to the 
	player that he should find a way to pick up the lamp.
	2016-11-29:
	Moved the loopCount increment form the LoopCounter() function, so the screen can 
	be redrawn to display story messages, without incrementing the loop, which affects
	Game Object movement, and may also affect other events I hope to implement
	*/
// cycle through the enemy & player objects & call update() for each object
void Game::update() {
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++) {
		/* Don't move the enemy knights until they are awake */
		if (((*it)->getID() == "Sir Tom" || (*it)->getID() == "Sir Bob") && knightsAwake == false)
			continue;
		else
			(*it)->update();						// Call the update function for each object
	}

	loopCount++;	// 2016-11-29 CA2 - Moved from LoopCounter(), so the screen can be redrawn without the enemies updating position

	/* Drop a hint when the lamps are lit, about one of the lamps */
	if (loopCount == DAYLIGHT_HOURS && level == 1) {
		draw();
		spiel.hintLamp1();			// Hint at the player to take the lamp
		draw();
		spiel.hintGuardSpeed();		// Point out to the player the guard speed up at night
	}
}

/*	2016-12-04:
	If the player has the same coordinates as a lamp, and it is night-time he can interact with it

	2016-11-30:
	If the player occupies the coordinates of a static game object
	He can interact with it. This is similar to the battle() function
	but instead of trying to kill a Game Object, the player decides
	whether to add it to his inventory
*/
void Game::interact() {
	// Check is the object you are interacting with an object that can be added to the players inventory
	addToInventory();

	/* PLAYER & ENEMY BURNED BY LAMP */
	/*	2016-11-30:
		If a Player or Enemy game object moves into the same coordinates as a lamp in the dungeon it is burned by the lamp and loses up to 5 health points
		The amount the player loses is based on luck, and the differce between 5 and amound burned is deducted from the players luck stats
		The Enemy loses 5 points every time it walks into a flame/lamp
		Once the player has picked up the "Lamp" Game Object he is no longer burned as he has learned how to handle fire
	*/
	if (level == 1) {
		int lampCoords[] = { 4,1,20,1,4,23,20,23,1,4,1,20,23,4,23,20 };	// Lamp coordinates for Dungeon
		int	burned = (rand() % 5) + 1;									// The amount of health points the player loses for being burned is based on luck

		if (getDaylight() == false) {
			for (int i = 0; i < 15; i += 2) {
				if ((*pPlayer).getX() == lampCoords[i] && (*pPlayer).getY() == lampCoords[i + 1] && (*pPlayer).getHasLamp() == false) {	// Player has same coords as a lamp, and it is night-time
					draw();
					std::cout << "\n  " << (*pPlayer).getID() << " has touched the lamp and has been burned, losing " << burned << " health points" << std::endl;
					std::cout << "  " << 10 - (burned * 2) << " has been deducted from the Players luck points" << std::endl;
					std::cout << "\n  Don't Play With Fire Kids!!!" << std::endl;
					(*pPlayer).setHealth((*pPlayer).getHealth() - burned);
					(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - (10 - (burned * 2)));
					std::cin.get();										// Pause the screen for player to read text
				}
				if ((*pEnemy1).getX() == lampCoords[i] && (*pEnemy1).getY() == lampCoords[i + 1]) {	// Enemy has the same coordinates as a lamp, and night-time
					draw();
					std::cout << "\n  ";
					std::cout << (*pEnemy1).getID() << " has touched the lamp and been has burned, losing 5 health points" << std::endl;
					(*pEnemy1).setHealth((*pEnemy1).getHealth() - 5);	// Enemy loses 5 health points every time they are burned
					std::cin.get();										// Pause the screen for player to read text
				}
			}
		}
	}
	/* TREASURE CHEST */
	/*	2016-11-30:
		If the players coords match the treasure chest coordinates, and the treasure chest is within it's lifespan decide what is in the treasure chest 
		Health, Skill, Strength, and Luck potions can be found, or a map of level 2 The Banquet Hall
	*/
	if ((*pPlayer).getX() == (*pTreasureChest).getX() && (*pPlayer).getY() == (*pTreasureChest).getY() && treasureSpawnTime <= loopCount && treasureKillTime >= loopCount) {
		draw();
		//spiel.interactionTreasureChest();
		treasureKillTime = 0;
		//55int	treasureFound = (rand() % 5) + 1;	// Generate a number between 1 and 5
		int treasureFound = 5; // test map
		if (treasureFound == 1) {
			std::cout << "\n  You have found a Health Potion, your will be restored to full health" << std::endl;
			(*pPlayer).setHealth(160);
		}
		if (treasureFound == 2) {
			std::cout << "\n  You have found a Skill Potion, your Skill will be increased to full Capacity" << std::endl;
			(*pPlayer).setSkill(160);
		}
		if (treasureFound == 3) {
			std::cout << "\n  You have found a Strength Potion, your Strength will be increased to full Capacity" << std::endl;
			(*pPlayer).setStrength(160);
		}
		if (treasureFound == 4) {
			std::cout << "\n  You have found a Luck Potion, your Luck will be increased to full Capacity" << std::endl;
			(*pPlayer).setPoxiness(160);
		}
		if (treasureFound == 5) {
			std::cout << "\n  You have found a Map of the castle, you can now see the layout of the Banquet Hall" << std::endl;
			revealL2Map = true;

			inventory.push_back(pMap);
		}
		std::cin.get();
	}

	/* INTERACT WITH ENEMY BEFORE A SWORD HAS BEEN PICKED UP */
	/*	2016-11-30:
		Before the player can do battle with an enemy he must first have a weapon.
		The sword will appear after the player first interacts with the enemy by occupying the
		same coordinates as the enemy. The players hasSword will be activated as soon as the player
		picks up a sword, the player can then proceed to fight the enemy.
		*/
	if (level == 1) {
		/*	2016-11-30
			If the player doesn't have a lamp and just so happens to be standing right where a lamp might be
			He might as well pick it up. And then he can go make shadow puppets or whatever. 
		*/
		if ((*pPlayer).getX() == (*pLamp).getX() && (*pPlayer).getY() == (*pLamp).getY() && (*pPlayer).getHasLamp() == false && getDaylight() == false) {
			draw();
			if (l1EnemyInteraction == false) {
				//std::cout << "Let's go make shadow puppets" << std::endl;
				spiel.hintGuard();
			}
		}
		if ((*pPlayer).getX() == (*pEnemy1).getX() && (*pPlayer).getY() == (*pEnemy1).getY() && (*pPlayer).getHasSword() == false) {
			draw();																// redraw the scene
			spiel.interactionL1Guard1();										// The player tries to persuade the guard to let him leave
			draw();																// redraw the scene
			spiel.interactionL1Guard2();

			l1EnemyInteraction = true;											// The player has interacted with the guard, and the sword can now be made visible									// The player is not encouraged by the guards response
			if ((*pPlayer).hasLamp == true) {
				draw();															// redraw the scene
				spiel.hintSword();												// Show a hint that there is a sword nearby.
			}
			else {
				draw();
				spiel.hintLamp2();
			}
		}
	}
	/* LEVEL 2*/	
	if (level == 2) {
		/* The player must light the lamps on the 4 walls, this wakes the 2 enemy knights */
		int lampCoordsL2[] = { 12,1,12,23,1,4,1,20,23,4,23,12,23,20 };

		if (getDaylight() == false) {
			for (int i = 0; i < 13; i += 2) {
				if ((*pPlayer).getX() == lampCoordsL2[i] && (*pPlayer).getY() == lampCoordsL2[i + 1] && (*pPlayer).getHasLamp() == true) {	// Player has same coords as a lamp, and it is night-time
					if (i == 0 && lamp1Lit == false) {
						std::cout << "Player has lit the north wall lamp" << std::endl;
						std::cin.get();										// Pause the screen for player to read text
						lamp1Lit = true;
					}
					if (i == 2 && lamp2Lit == false) {
						std::cout << "Player has lit the south wall lamp" << std::endl;
						std::cin.get();										// Pause the screen for player to read text
						lamp2Lit = true;
					}
					if ((i == 4 || i == 6) && lamp3Lit == false) {
						std::cout << "  Player has lit the west wall lamp" << std::endl;
						std::cin.get();										// Pause the screen for player to read text
						lamp3Lit = true;
					}
					if ((i == 8 || i == 10 || i == 12) && lamp4Lit == false) {
						std::cout << "Player has lit the east wall lamp" << std::endl;
						std::cin.get();										// Pause the screen for player to read text
						lamp4Lit = true;
					}
				}
				if ((*pEnemy1).getX() == lampCoordsL2[i] && (*pEnemy1).getY() == lampCoordsL2[i + 1]) {	// Enemy has the same coordinates as a lamp, and night-time
					draw();
					std::cout << "\n  ";
					std::cout << (*pEnemy1).getID() << " has touched the lamp and been has burned, losing 5 health points" << std::endl;
					(*pEnemy1).setHealth((*pEnemy1).getHealth() - 5);	// Enemy loses 5 health points every time they are burned
					std::cin.get();										// Pause the screen for player to read text
				}
			}
		}
	}
}

/*	2016-12-01:
	Added Treasure item, and more checks for Lamp, if player doesn't have a lamp, and it is night time, he can pick up the lamp

	2016-11-24:
	Add an Inventory of objects for the Player to collect and use such as sword, shield, potions etc.
*/
void Game::addToInventory() {
	int	burned = (rand() % 5) + 1;									// The amount of health points the player loses for being burned is based on luck

	for (it = listOfCollectables.begin(); it != listOfCollectables.end(); it++)					// Cycle through list of static game objects
	{
		if (((*it)->getX()) == ((*pPlayer).getX()) && ((*it)->getY()) == ((*pPlayer).getY()))		// if collectable coords = player coords
		{																							// The player has picked up a sword
			SetConsoleTextAttribute(hstdout, 0x0F);
			std::cout << "\n  ";
			SetConsoleTextAttribute(hstdout, 0xE1);													// Yellow BG, White txt
			std::cout << "\t\t    Player has collected a " << (*it)->getID() << "\t\t\t" << std::endl;
			SetConsoleTextAttribute(hstdout, 0x0F);													// Reset  - Black BG, White txt

			(*it)->setHealth(0);	// remove the weapon / power up

			/* SWORD */
			/*
				Player can pick up a sword if he doesn't have a sword, has a lamp, and has interacted with the enemy 
			*/
			if ((*it)->getID() == "Sword" && (*pPlayer).getHasSword() == false && (*pPlayer).getHasLamp() == true &&  l1EnemyInteraction == true) {
				(*pPlayer).setHasSword(true);														// The player has picked up a sword
				SetConsoleTextAttribute(hstdout, 0x0F);												// Reset  - Black BG, White txt
				spiel.interactionSword();															// Output the message for the player picking up a sword

				inventory.push_back(pSword);

				(*it)->setHealth(0);																// Delete the treasure chest after it is opened
			}
			/* TREASURE CHEST */
			/* 
				Player can open a treasure chest if it is within the treasure chests life span 
			*/
			else if ((*it)->getID() == "Treasure" && (loopCount >= treasureSpawnTime && loopCount <= treasureKillTime)) {
				SetConsoleTextAttribute(hstdout, 0x0F);												// Reset  - Black BG, White txt
				spiel.interactionTreasureChest();													// Output the message for the player opening a treasure chest

				(*it)->setHealth(0);																// Delete the treasure chest after it is opened
			}
			/* LAMP */
			/* 
				Player can pick up a lamp if it is night-time, and they don't already have a lamp 
			*/
			else if ((*it)->getID() == "Lamp" && (*pPlayer).getHasLamp() == false && getDaylight() == false) {	// Player doesn't have a lamp, and it is night-time
				(*pPlayer).setHasLamp(true);														// Set the player has picked up a Lamp

				SetConsoleTextAttribute(hstdout, 0x0F);												// Reset  - Black BG, White txt
				spiel.interactionLamp();
				std::cout << "\n  ";
				std::cout << (*pPlayer).getID() << " touched the lamp burning his hand, losing " << burned << " health points" << std::endl;
				std::cout << "  " << 5 - burned << " has been deducted from the Players luck points" << std::endl;
				std::cout << "\n  You have learned the hard way how to handle naked flames!!!" << std::endl;
				(*pPlayer).setHealth((*pPlayer).getHealth() - burned);
				(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - (5 - burned));

				inventory.push_back(pLamp);

				(*it)->setHealth(0);																// Delete the lamp from the game object list
			}
			/* KEY */
			else if ((*it)->getID() == "Key" && (*pPlayer).getHasLamp() == true && (*pPlayer).getHasSword() == true) {
				spiel.interactionKey();
				l1EnemyInteraction = true;
				hasKey = true;

				inventory.push_back(pKey);

				(*it)->setHealth(0);																// Delete the Key from the game object list
			}
		}	// end if
	}	// end for
	std::cin.get();	// Pause the message on screen, so ClearScreen doesn't wipe it
}


/*	2016-12-01
	Added a more advanced combat system, which utilised the Skill, Strength and Luck stats added for CA2
	Player uses Skill and Luck points in avoiding damage being inflicted
	Player uses Strength points when inflicting damage on the Enemy
	The player rolls a dice to decide the outcome of an attack, whether a blow is landed or defended, or avoided completely
	The dice is rolled again to decide the damage to be inflicted. The luck points used also depend on the outcome of the 
	dice roll, and also the skill points when attacking. When defending skill and strength points are calculated based on 
	a number between 1 and 5 for skill, and a number between 1 and 10 for Strength, this number depends on the level of
	Skill and Strength points a player has, and both are taken from the Enemys health total

	2016-11-29:
	Fixed some formatting and text layout errors to do with the name "Boss" being less characters than "EnemyN"

	CA1:
	if 2 objects occupy the same coords declare a battle must take place. The object with the higher health wins. 
	The loser will have its health set to 0. Get game objects coords & check is there any objects with the same coords 
*/
void Game::battle() {
	/* Player must roll dice to determine next move */
	int dice1, dice2, diceTotal, blowStrength, battleSkill;
	int playerHealth, enemyHealth, battleCounter = 1;
	
	/*	2016-12-01:
		Added new condidtion for testing battle
	*/
	if ((testBattle && loopCount == 2) || (level == 1 && (*pEnemy1).getX() == (*pPlayer).getX() && (*pEnemy1).getY() == (*pPlayer).getY() && (*pPlayer).getHasSword() == true)) { 
		// Begin the battle
		draw();
		spiel.battleBegin();
		ClearScreen();

		while ((*pPlayer).getHealth() != 0 && (*pEnemy1).getHealth() != 0) {
			draw();
			spiel.battle1();							// Enemy attack

			dice1 = (rand() % 6) + 1;					// generate random number		
			dice2 = (rand() % 6) + 1;
			diceTotal = dice1 + dice2;

			if (dice1 > dice2) {
				std::cout << "\n  Player has rolled a " << dice1 << ", while the Enemy has rolled a " << dice2 << std::endl;
				std::cout << "\n  The player has avoided the enemy blow" << std::endl;
				dice1 = (rand() % 6) + 1;					// generate random number		
				dice2 = (rand() % 6) + 1;
				diceTotal = dice1 + dice2;

				std::cout << "  The Enemy is deducted " << diceTotal << " health points after putting such force into a deflected blow" << std::endl;
				std::cout << "  Player's luck decreases by " << diceTotal << ", as he was lucky to avoid the blow." << std::endl;
				(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - diceTotal);
				(*pEnemy1).setHealth((*pEnemy1).getHealth() - diceTotal);
				std::cin.get();									// Pause the screen
			}
			else if (dice1 < dice2) {
				std::cout << "\n  Player has rolled a " << dice1 << ", while the Enemy has rolled a " << dice2 << std::endl;
				std::cout << "\n  Player has taken a blow from the enemies sword" << std::endl;
				std::cout << "  Roll the dice to see how much damage has been inflicted, PRESS ENTER" << std::endl;
				std::cin.get();									// Pause the screen

				dice1 = (rand() % 6) + 1;					// generate random number		
				dice2 = (rand() % 6) + 1;
				diceTotal = dice1 + dice2;
				std::cout << "  Player is deducted " << diceTotal << " health points after receving a cut his body" << std::endl;
				std::cout << "  " << 12 - diceTotal << " luck points have been deducted as a result." << std::endl;
				(*pPlayer).setHealth((*pPlayer).getHealth() - diceTotal);
				(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - (12 - diceTotal));
				std::cin.get();									// Pause the screen
			}
			else if (dice1 == dice2) {
				std::cout << "\n  Player has rolled a " << dice1 << ", while the Enemy has rolled a " << dice2 << std::endl;
				std::cout << "\n  The Player and Enemies swords clash together with great fury." << std::endl;
				std::cout << "  Roll the dice to see how much damage has been inflicted, PRESS ENTER" << std::endl;
				std::cin.get();									// Pause the screen

				dice1 = (rand() % 6) + 1;					// generate random number		
				dice2 = (rand() % 6) + 1;
				diceTotal = dice1 + dice2;
				std::cout << "  The Player and Enemy are both deducted " << diceTotal / 2 << " health points" << std::endl;
				std::cout << "  " << (12 - diceTotal) / 2 << " luck points have been deducted as a result." << std::endl;
				std::cout << "  " << diceTotal << " Skill points have been deducted, the player has invested a lot of skill in the block." << std::endl;
				(*pPlayer).setHealth((*pPlayer).getHealth() - (diceTotal / 2));
				(*pEnemy1).setHealth((*pEnemy1).getHealth() - (diceTotal / 2));
				(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - ((12 - diceTotal) / 2));
				(*pPlayer).setSkill((*pPlayer).getSkill() - diceTotal);
				std::cin.get();									// Pause the screen
			}
			// Player Attacks Enemy
			draw();
			spiel.battle2();							// Enemy attack

			dice1 = (rand() % 6) + 1;					// generate random number		
			dice2 = (rand() % 6) + 1;
			diceTotal = dice1 + dice2;

			if (dice1 > dice2) {
				std::cout << "\n  Player has rolled a " << dice1 << ", while the Enemy has rolled a " << dice2 << std::endl;
				std::cout << "\n  Player has dealt the Enemy a crushing blow " << std::endl;
				std::cout << "  Roll the dice to see how much damage has been inflicted, PRESS ENTER" << std::endl;
				std::cin.get();									// Pause the screen
				dice1 = (rand() % 6) + 1;					// generate random number		
				dice2 = (rand() % 6) + 1;
				diceTotal = dice1 + dice2;

				std::cout << "  The Enemy is deducted " << diceTotal << " health points after being struck by Player" << std::endl;
				(*pEnemy1).setHealth((*pEnemy1).getHealth() - diceTotal);
				blowStrength = ((*pPlayer).getStrength() / 32) + 1;	// A number from one to 5 is also deducted depending on players strength, (Strength is 160, so 1/5 -> divide by 32)
				std::cout << "  The Enemy is deducted a further " << blowStrength << " health points after being totally dominated by Player" << std::endl;
				(*pEnemy1).setHealth((*pEnemy1).getHealth() - diceTotal);
				battleSkill = ((*pPlayer).getSkill() / 16) + 1;	// A number from 1 to 10 is also deducted depending on players Skill, (Skill is 160, so 1/10 -> divide by 16)
				std::cout << "  and a further " << battleSkill << " health points as the Players has Skillfully wounded the Enemy" << std::endl;
				(*pEnemy1).setHealth((*pEnemy1).getHealth() - diceTotal * 2);
				std::cout << "  Player's Luck decreases by " << diceTotal << ", as he was lucky to inflict such a wound." << std::endl;
				(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - diceTotal);
				std::cout << "  Player's Strength decreases by " << blowStrength * 2 << " points after putting an equivalent force into the attack" << std::endl;
				(*pPlayer).setStrength((*pPlayer).getStrength() - (blowStrength * 2));
				std::cout << "  " << battleSkill << " Skill points have been deducted, the player has used great skill damaging the Enemy." << std::endl;
				(*pPlayer).setSkill((*pPlayer).getSkill() - battleSkill);
				std::cin.get();									// Pause the screen
			}
			else if (dice1 < dice2) {
				std::cout << "\n  Player has rolled a " << dice1 << ", while the Enemy has rolled a " << dice2 << std::endl;
				std::cout << "  Roll the dice to see how much damage has been inflicted, PRESS ENTER" << std::endl;
				std::cin.get();									// Pause the screen

				dice1 = (rand() % 6) + 1;					// generate random number		
				dice2 = (rand() % 6) + 1;
				diceTotal = dice1 + dice2;
				std::cout << "  Player is deducted " << diceTotal << " health points after exhausting his energy in the wasted attack" << std::endl;
				(*pPlayer).setHealth((*pPlayer).getHealth() - diceTotal);
				std::cin.get();									// Pause the screen
			}
			else if (dice1 == dice2) {
				std::cout << "\n  Player has rolled a " << dice1 << ", while the Enemy has rolled a " << dice2 << std::endl;
				std::cout << "\n  The Player and Enemies swords clash together with great fury." << std::endl;
				std::cout << "  Roll the dice to see how much damage has been inflicted, PRESS ENTER" << std::endl;
				std::cin.get();									// Pause the screen

				dice1 = (rand() % 6) + 1;					// generate random number		
				dice2 = (rand() % 6) + 1;
				diceTotal = dice1 + dice2;
				std::cout << "  The Player and Enemy are both deducted " << diceTotal / 2 << " health points" << std::endl;
				std::cout << "  " << (12 - diceTotal) / 2 << " luck points have been deducted as a result." << std::endl;
				(*pPlayer).setHealth((*pPlayer).getHealth() - (diceTotal / 2));
				(*pEnemy1).setHealth((*pEnemy1).getHealth() - (diceTotal / 2));
				(*pPlayer).setPoxiness((*pPlayer).getPoxiness() - ((12 - diceTotal) / 2));
				std::cin.get();									// Pause the screen
			}
			draw();
			std::cout << "\n  After " << battleCounter << " Rounds of battle" << std::endl;
			battleCounter++;
			playerHealth = (*pPlayer).getHealth();
			enemyHealth = (*pEnemy1).getHealth();
			std::cout << "  Player Health: " << playerHealth << " Enemy Health: " << enemyHealth << std::endl;
			if (playerHealth > enemyHealth)
				std::cout << "  Player is winning the battle";
			else if (playerHealth < enemyHealth)
				std::cout << "  Enemy is winning the battle";
			else 
				std::cout << "  Player and Enemy are evenly matched";
			std::cin.get();									// Pause the screen			
		} 

		draw();
		std::cout << "\n  After " << battleCounter << " Rounds of battle" << std::endl;
		if (playerHealth > enemyHealth) {
			std::cout << "  Player has won the battle";
			//setGameResult(L1Complete);
			//level = 2;
			//GameOver();
			draw();
			spiel.l1CompleteKey();	// Get the key to exit the dungeon
		}
		else if (playerHealth < enemyHealth) {
			std::cout << "  Enemy has won the battle";
			//setGameResult(Lose);
			//GameOver();
		}
		else
			std::cout << "  Player and Enemy are evenly matched";
		std::cin.get();									// Pause the screen					
		} // end while
				
		SetConsoleTextAttribute(hstdout, 0x0F);					// Reset  - Black BG, White txt
}

// Cycle through the enemy and player objects and call the info function for each object
void Game::info() {
	if (gameState != Undecided){
		if (testMode == false) {
			// Message Heading
			SetConsoleTextAttribute(hstdout, 0xF1);								// White BG, Blue txt
			std::cout << std::setfill(' ') << std::setw(34) << "INFORMATION\t\t\t " << std::endl;
			SetConsoleTextAttribute(hstdout, 0x71);								// Grey BG, Blue txt

																				// Print the Name and Coordinates for each Game Object
			for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++) {
				SetConsoleTextAttribute(hstdout, 0x75);
				if ((*it)->getID() != "Sword" || (*it)->getID() != "Treasure") {
					std::cout << "    " << (*it)->getID();
					SetConsoleTextAttribute(hstdout, 0x71);
					std::cout << "\t\t\tCoordinates:\t " << std::endl <<
						"    Speed: " << (*it)->getSpeed() << " Health: " << (*it)->getHealth() <<
						"  \tX: " << (*it)->getX() << "  \tY: " << (*it)->getY() << "\t " << std::endl;
				}
			}

			// Press Enter To Continue
			SetConsoleTextAttribute(hstdout, 0x01);							   // Black BG, Blue text				
			std::cout << "\n\t     Press Enter To Continue\t\t " << std::endl;
			SetConsoleTextAttribute(hstdout, 0x0F);							   // Reset colour Black bg, White txt	
			std::cin.get();													   // Pause the screen

			ClearScreen();													   // Clear the screen

		}										   // Clear the screen
	}
}



// remove any objects from the list whose health is 0  (Using isAlive function);
void Game::clean() {
	// cycle through loop
	it = listOfGameObjects.begin(); // Iterator set to list start
	while ((it != listOfGameObjects.end()) && (!listOfGameObjects.empty()))								   // Cycle through list
	{
		if ((*it)->isAlive())											   // if it is alive iterate
			++it;														   // Increment iterator
		else {															   // Otherwise...
			//if ((*it)->getID() == "Gaoler ")
			//	level = 2;
			it = listOfGameObjects.erase(it);								// Erase object from list
		}
	}	// end while

	//it = listOfEnemies.begin();
	//while (it != listOfEnemies.end()) {										// Cycle through list
	//	if ((*it)->isAlive())											   // if it is alive iterate
	//		++it;														   // Increment iterator
	//	else															   // Otherwise...
	//		it = listOfEnemies.erase(it);									// Erase object from list
	//}	// end while
}	// end clean

	/*  2016-11-30:
		Set the enemy speed based on whether it's night or day time
		2016-11-28:
		Added, display if night or day and the current level for the player
		CA1:
		Display Number Of Loops for the game
	*/
void Game::LoopCounter() {
	//loopCount++;	// 2016-11-29 CA2 - Moved to update()
	SetConsoleTextAttribute(hstdout, 0x0F);				// Blue BG, White txt
	std::cout << "  ";
	SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, White txt

	std::cout << " Level " << level << ":  " << std::flush; // 2016-11-29 CA2: Add the level number to the information bar at top of screen

	if (loopCount % HOURS_PER_DAY < DAYLIGHT_HOURS) {
		std::cout << "DAY TIME     ";
		setDayTime(true);
		(*pEnemy1).setSpeed(DAY_SPEED);
	}
	else {
		std::cout << "NIGHT TIME   ";
		setDayTime(false);
		(*pEnemy1).setSpeed(NIGHT_SPEED);
	}
	std::cout << "Loop Count: " << std::setfill('0') << std::setw(3) << loopCount << "\t\t " << std::flush;
	std::cout << "\t";
}

/*	2016-12-01:
	Draw separate enemy health bars for each level

	2016-11-29:
	Add the to the display the stats for a player object including the skill and luck level
	Added 5 new enemy with 8 charachter health bars, and a boss with a 32 character health bar
	CA1:
	Display a health bar for the player and 4 enemy objects
*/
void Game::displayStatsBars() {
	/* Adds a countdown timer bar, indicating the length of time a treasure chest will remain on screen. */
	char treasure[] = { ' ','t','r','e','a','s','u','r','e',' ' };
	treasureBarSize = treasureKillTime - loopCount;
	if (loopCount >= treasureSpawnTime && loopCount < treasureKillTime) {
		SetConsoleTextAttribute(hstdout, 0xCF);
		for (int i = 0; i < treasureBarSize; i++) {
			std::cout << treasure[i];
		}
		SetConsoleTextAttribute(hstdout, 0x9F);
		for (int i = treasureBarSize; i < 10; i++) {
			std::cout << treasure[i];
		}
	}
	else
		std::cout << "        ";
	if (treasureKillTime <= loopCount)
		(*pTreasureChest).setHealth(0);

	SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, White txt
	std::cout << "\t\t      Skill   ";
	calcSkillBar();
	std::cout << " Strength ";
	calcStrengthBar();
	std::cout << "  Luck    ";
	calcPoxBar();
	std::cout << "     Player Health:   ";

	calcHealthBar(LARGE_BAR, "Player");
	/* Calculate Enemy Health Bars For Each Level */
	if (level == 1) {
		std::cout << " ";
		SetConsoleTextAttribute(hstdout, 0x0F);				// White BG, Black txt
		std::cout << "\n  ";								// End Of Line
		SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, White txt
		std::cout << std::setfill(' ') << std::setw(166) << "Gaoler Health:   ";
		calcHealthBar(LARGE_BAR, "Gaoler ");				// Enemy 1 health bar

	}
	else if (level == 2 && L2LightsOn == true && knightsAwake == true) {
		std::cout << " ";
		SetConsoleTextAttribute(hstdout, 0x0F);				// White BG, Black txt
		std::cout << "\n  ";								// End Of Line
		SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, White txt
		std::cout << std::setfill(' ') << std::setw(112) << "Sir Tom Health:     ";
		calcHealthBar(LARGE_BAR, "Sir Tom");				// Enemy 2 health bar
		std::cout << "     Sir Bob Health:  ";
		calcHealthBar(LARGE_BAR, "Sir Bob");				// Enemy 3 health bar

	}
	else if (level == 3) {
		std::cout << " ";
		SetConsoleTextAttribute(hstdout, 0x0F);			// White BG, Black txt
		std::cout << "\n  ";								// End Of Line
		SetConsoleTextAttribute(hstdout, 0x9F);			// Blue BG, White txt
		std::cout << std::setfill(' ') << std::setw(55) << "Enemy 4:     ";
		calcHealthBar(LARGE_BAR, "Enemy 4");				// Enemy 4 health bar
		std::cout << "     Enemy 5:            ";
		calcHealthBar(LARGE_BAR, "Enemy 5");				// Enemy 5 health bar
		std::cout << "     Enemy 6:         ";
		calcHealthBar(LARGE_BAR, "Enemy 6");				// Enemy 5 health bar

	}
	else if (level == 4) {
		std::cout << " ";
		SetConsoleTextAttribute(hstdout, 0x0F);				// White BG, Black txt
		std::cout << "\n  ";						// End Of Line
		SetConsoleTextAttribute(hstdout, 0x9F);				// Blue BG, White txt
		std::cout << " Gaoler ";
		//calcHealthBar(ENEMY_BAR, "Enemy 1");				// Enemy 1 health bar
		calcHealthBar(SMALL_BAR, "Gaoler ");				// Enemy 1 health bar
		std::cout << "  Sir Tom  ";
		calcHealthBar(SMALL_BAR, "Sir Tom");				// Enemy 2 health bar
		std::cout << "  Sir Bob ";
		calcHealthBar(SMALL_BAR, "Sir Bob");				// Enemy 3 health bar
		std::cout << "  Enemy 4 ";
		calcHealthBar(SMALL_BAR, "Enemy 4");				// Enemy 4 health bar
		std::cout << " ";						// End Of Line
												// 2nd Row Health Bars for New Enemies
		std::cout << "  Enemy 5 ";
		calcHealthBar(SMALL_BAR, "Enemy 5");				// Enemy 5 health bar
		std::cout << "  Enemy 6 ";
		calcHealthBar(SMALL_BAR, "Enemy 6");				// Enemy 6 health bar
		std::cout << "  Enemy 7 ";
		calcHealthBar(SMALL_BAR, "Enemy 7");				// Enemy 7 health bar
		std::cout << "  Enemy 8 ";
		calcHealthBar(SMALL_BAR, "Enemy 8");				// Enemy 8 health bar
		std::cout << "     Boss Health:     ";
		calcHealthBar(LARGE_BAR, "Boss");
	}
	std::cout << " " << std::endl;						// End Of Line
														//std::cout << "\n ";

	SetConsoleTextAttribute(hstdout, 0x0F);				// Black bg, White txt
}

/*	2016-11-29:
	Added more doors to the other rooms on the map
	2016-11-28:
	Updated the function so the sword is presented in torquise and it now points in all directions
	not just east and west.
	Added a door to the west side of the map, the player must unlock the door by defeating the enemy
	and retrieving the key, before he can progress to the next level
	2016-11-27:
	Updated the function to draw the players sword pointing in the direction the player is facing, 
	This gives the player a visual indication of the direction the player is heading in.
	Added 3 more grids to the display, the 4 grids are now representing 4 levels
	CA1:
	Draw the grid to display game objects positions
*/
void Game::drawGrid()
{
	// Set background text in the grid - for no paticular reason
	char* dungeon[25][25] = { { "* ","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","* " },
	{ "* ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  "," _","__","__","__","__","_.","__","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  "," \\","__","  ","  ","__","_|","  ","|_","_ ","  ","__","__","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  "," |","  ","  ","| "," |","  ","| "," \\","_/"," _","_ ","\\ ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  "," |","  ","  ","| "," |","  "," Y","  ","\\ "," _","__","/ ","  ","  ","  ","  ","  ","  ","* " },
	{ "| ","  ","  ","  ","  ","  "," |","__","__","| "," |","__","_|","  ","/\\","__","_ "," >","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","__","__","__","__","_ ","  ","  ","  ","  ","  ","  ","\\/","  ","__"," \\","/_","_ ","  ","  ","  ","  ","  " ,"* " },
	{ "* ","  ","\\_","  "," _","__"," \\","__","__","_ ","  "," _","__","__","_/","  ","|_","| "," |","  "," _","__","_ ","  ","* " },
	{ "* ","  ","/ ","  "," \\","  ","\\/","\\_","_ "," \\","  ","/ "," _","__","\\ ","  ","__","| "," |"," _","/ ","__"," \\","  ","* " },
	{ "* ","  ","\\ ","  ","  ","\\_","__","_/"," _","_ ","\\_","\\_","__"," \\"," |","  ","| ","| "," |","_\\","  ","__","_/","  "," |" },
	{ "* ","  "," \\","__","__","__","  ","(_","__","_ "," /","__","__","  ",">|","__","| ","|_","__","_/","\\_","__","  ","> ","* " },
	{ "* ","__","__","__","_ ","  ","\\/","  ","  "," \\","/ ","  ","  ","\\/","  ","  ","  ","  ","  ","  ","  ","  ","\\/","  ","* " },
	{ "* ","\\_","__","__"," \\"," _","_ ","__","  ","__","__","  ","__","__","  ","__","__","  ","__","__","  ","__","_ ","  ","* " },
	{ "| ", " |","  "," |","  ","| "," |","  ","\\/","  ","  ","\\/"," _","__","\\/"," _","_ ","\\/","  ","_ ","\\/","  "," \\","  ","* " },
	{ "* "," |","  "," `","  ","| "," |","  ","| ","  ","| ","( ","/_","/ ","( "," _","__","( "," <","_>","( "," |","  ","\\ ","* " },
	{ "* ","/_","__","__","_ ","|_","__","_/","|_","__","| "," \\","__","  ","/\\","__","_ "," \\","__","__","/_","_|","  ","/ ","* " },
	{ "* ", "  ", "  ", "  ", " \\","/ ","  ","  ","  ","  "," \\","/_","__","_/","  ","  "," \\","/ ","  ","  ","  ","  ","\\/","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","* " },
	{ "* ","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","* " } };

	char* hall[25][25] = { { "* ","* ","* ","* ","* ","* ","* ","* ","==","* ","* ","* ","* ","* ","* ","* ","==","* ","* ","* ","* ","* ","* ","* ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," |" },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ " *","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","  ","__","__","__","__","__","._","_ ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","\\_","_ ","  "," _","__","| "," |","__","  "," _","__","_ ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","| ","  "," |","  ","| "," |","  ","\\_","/ ","__"," \\","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","| ","  "," |","  ","| ","  ","Y "," \\","  ","__","_/","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","__","__","__","__","  ","  ","|_","__","_|","  ","|_","__","| "," /","\\_","__","  ","> ","  ","  "," _","_ ","  ","* " },
	{ "* ","\\_","__","__","  ","\\_","__","__","  "," _","__","  ","__","_\\","/_","__"," _","\\/"," _","__","__","/ "," |","_ ","* " },
	{ "* "," |","  "," |","  ","_\\","__","  ","\\ ","/ ","  ","\\/"," _","_ "," |","  ","| "," |","/ ","__"," \\","  "," _","_\\","* " },
	{ "  "," |","  "," |","  "," \\","/ ","__"," Y","  ","| ","< ","<_","| "," |","  ","| "," \\","  ","__","_/","| "," |"," *","* " },
	{ "* "," |","__","__","_ "," (","__","_ ","|_","__","| "," \\","__","  "," |","__","__","/ ","\\_","__","  ","|_","_|","  ","* " },
	{ "* ","  ","  ","  "," \\","/ "," _","_\\","/_","__"," \\","/ ","  ","|_",".>","_ "," .","__","  ","  ","\\/","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","/ ","  ","| ","  ","\\_","__","__","  ","| "," |"," |","  ","| ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  "," /","  ","  ","~ ","  "," \\","__","  ","\\ ","| "," |"," |","  ","| ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  "," \\","  ","  ","Y ","  "," /","/ ","__"," \\","| "," |","_|","  ","|_","_ ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","\\_","__","|_","  ","/(","__","__","  ","|_","__","_|","__","__","/ ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","\\/","  ","  ","  ","\\/","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ " *","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","* ","* ","* ","* ","* ","* ","* ","==","* ","* ","* ","* ","* ","* ","* ","==","* ","* ","* ","* ","* ","* ","* ","* " } };

	char* tower[25][25] = { { "* ","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","--","*","* ","* ","* ","* ","* ","* ","* " },
	{ "  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","__","__","_ ","_ ","  ","_ ","__","__","_ ","  ","  ","  ","  ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","  ","  "," |","_ ","  ","_|"," |"," |"," |","  ","__","_|","  ","  ","  ","  ","  ","  ","  " ,"* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  "," |"," |"," |"," |","_|"," |"," |","__","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  "," |"," |"," |","  ","_ "," |","  ","__","| ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  "," |"," |"," |"," |"," |"," |"," |","__","_ ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  "," \\","_/"," \\","_|"," |","_\\","__","__","/ ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  "," _","__","  ","__","_ ","__","_ ","__","__","__","__","__","_ ","__","__","_ ","_ ","  ","_ ","  ","  ","* " },
	{ "* ","  ","  "," |","  ","\\/","  ","|/"," _"," |","_ ","  ","_|","  ","_ "," |","  ","__","_|"," \\"," |"," |","  ","  ","* " },
	{ "* ","  ","  "," |"," .","  ",". ","/ ","/_","\\ ","\\|"," |"," |"," |"," |"," |"," |","__"," |","  ","\\|"," |","  "," *" ,"* " },
	{ "* ","  ","  "," |"," |","  ","| ","| ","| ","| ","_|"," |","_|"," |","/ ","/|"," |","__","_|"," |","\\ "," |","  ","  " ,"* " },
	{ "* ","  ","  "," \\","_|","  ","|_","\\_","| ","|_","\\_","__","/|","__","_/"," \\","__","__","/\\","_|"," \\","_/","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","__","__","_ ","__","__","_ ","_ ","  "," _"," _","__","__","__","__","__","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  "," |","_ ","  ","_|","  ","_ "," |"," |","  ","| ","| "," _","__","| ","__","_ ","\\ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  "," |"," |"," |"," |"," |"," |"," |","  ","| ","| ","|_","_ ","| ","|_","/ ","/ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  "," |"," |"," |"," |"," |"," |"," |","/\\","| ","| "," _","_|","| ","  "," /","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  "," |"," |"," \\"," \\","_/"," \\","  ","/\\","  ","| ","|_","__","| ","|\\"," \\","  ","  ","  ","  ","* " },
	{ "* ", "  ", "  ", "  ", "  ", " \\","_/","  ","\\_","__","/ ","\\/","  ","\\/","\\_","__","_/","\\_","| ","\\_","| ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  "," |" },
	{ "* ","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","* " } };

	char* arena[25][25] = { { "* ","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","* " },
	{ "* ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","__","__","__"," _","__","__","  ","__","_ ","__","__","_ ","_ ","  ","_ ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| "," _","  ","\\ "," _","__","|/"," _"," \\","_ ","  ","_|"," |"," |"," |","  ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","| ","| ","| ","| ","|_","_ ","/ ","/_","\\ ","\\|"," |"," |"," |","_|"," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| ","| ","| ","| "," _","_|","| "," _","  ","||"," |"," |","  ","_ "," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","| ","|/"," /","| ","|_","__","| ","| ","| ","||"," |"," |"," |"," |"," |","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","|_","__","/ ","\\_","__","_/","\\_","| ","|_","/\\","_/"," \\","_|"," |","_/","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","__","_ "," _","__","  ","__","_ ","__","__","_ ","__","__","_ ","  ","_ ","  ","_ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| "," \\","/ "," |"," /"," _"," \\","_ ","  ","_/","  ","__"," \\"," |"," |"," |"," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ",". "," ."," |","/ ","/_","\\ ","\\|"," |"," |"," /","  ","\\/"," |"," |","_|"," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ","|\\","/|"," |","| "," _","  ","||"," |"," |"," |","  ","  "," |","  ","_ "," |","  ","  "," *","* " },
	{ "* ","  ","  ","  ","| ","| "," |"," |","| ","| ","| ","||"," |"," |"," \\","__","/\\"," |"," |"," |"," |","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","\\_","| "," |","_/","\\_","| ","|_","/\\","_/","  ","\\_","__","_/"," \\","_|"," |","_/","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","__","_ "," _","__","__","_ ","__","__","_ ","_ ","  ","_ ","  ","__","_ ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  "," /"," _"," \\"," |"," _","__"," \\","  ","__","_|"," \\"," |"," |"," /"," _"," \\","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","/ ","/_","\\ ","\\|"," |","_/"," /"," |","__"," |","  ","\\|"," |","/ ","/_","\\ ","\\ ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| "," _","  ","||","  ","  ","/|","  ","__","||"," ."," `"," |","| "," _","  ","| ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","| ","| ","| ","||"," |","\\ ","\\|"," |","__","_|"," |","\\ "," |","| ","| ","| ","| ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","\\_","| ","|_","/\\","_|"," \\","_\\","__","__","/\\","_|"," \\","_/","\\_","| ","|_","/ ","  ","  "," *","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "* ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","* " },
	{ "  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","  ","  ","  ","  "," *","  ","  ","  ","* " },
	{ "* ","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","--","* ","* ","* ","* ","* ","* ","* ","* " } };
	

	/* Open Doors */
	if (level > 1) {
		dungeon[12][24] = "_ ";	// 2016-11-30 CA2 - Feasting Hall East Door
		dungeon[12][23] = " _";	// 2016-11-30 CA2 - Feasting Hall East Door
		hall[12][0] = "  ";		// 2016-11-30 CA2 - Feasting Hall East Door
	}
	else if (level > 2) {
		//hall[12][1] = "__";	// 2016-11-30 CA2 - Tower East Door
		hall[1][24] = "_ ";		// 2016-11-30 CA2 - Tower East Door
		hall[1][23] = " _";		// 2016-11-30 CA2 - Tower East Door
		tower[1][0] = "  ";		// 2016-11-30 CA2 - Tower East Door
	}
	else if (level > 3) {
		//hall[12][1] = "__";	// 2016-11-30 CA2 - Arena East Door
		tower[1][24] = "_ ";	// 2016-11-30 CA2 - Arena East Door
		tower[1][23] = " _";	// 2016-11-30 CA2 - Arena East Door
		arena[1][0] = "  ";		// 2016-11-30 CA2 - Arena East Door
	}

	// 2016-11-30 Add lights to west walls for each room
	if (!getDaylight()) {
		if(level == 1) {
			dungeon[4][0] = " *";
			dungeon[20][0] = " *";
		} else if (level == 3) {
			tower[4][0] = " *";
			tower[20][0] = " *";
		} else if (level == 4) {
			arena[4][0] = " *";
			arena[20][0] = " *";
		}
	}
	/* if in level 2 the knights are awake, and it is daytime */
	if (level == 2 && knightsAwake == true && getDaylight() == true) {
			hall[4][0] = "* ";
			hall[20][0] = "* ";
	}

	/*	2016-11-29:
		Set the enemy positions in each level, with 1 enemy in the dungeon level (Level 1)
		2 enemies in the Banquet Hall (Level 2), 3 enemies in the Maiden Tower (Level 3),
		and the Boss Level takes place in the Castle Arena (Level 4), where there is a Boss
		Enemy and a number of henchmen.
		CA1:
		Get Game Object Positions
	*/
	// Level 1 Game Object Positions
	if (level == 1) {
		for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
		{
			int x = (*it)->getX();					// Local variable to store x coord
			int y = (*it)->getY();					// local variable to store y coord

			if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == false)			// If the GameObject is Player represent it with an X
				dungeon[y][x] = "X ";				// COORDS REVERSED!!!
			else if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == true) {		// If the GameObject is Player represent it with an X
				if ((*pPlayer).getDirection() == West) {
					dungeon[y][x] = "X ";
					dungeon[y][x - 1] = "--";
				}
				else if ((*pPlayer).getDirection() == East) {
					dungeon[y][x] = " X";
					dungeon[y][x + 1] = "--";
				}
				else {
					dungeon[y][x] = "X ";
					if ((*pPlayer).getDirection() == NW) {
						dungeon[y - 1][x - 1] = " \\";
					}
					else if ((*pPlayer).getDirection() == North) {
						dungeon[y - 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == NE) {
						dungeon[y - 1][x] = " /";
					}
					else if ((*pPlayer).getDirection() == SW) {
						dungeon[y + 1][x - 1] = " /";
					}
					else if ((*pPlayer).getDirection() == South) {
						dungeon[y + 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == SE) {
						dungeon[y + 1][x] = " \\";
					}
				}
			}
			else if ((*it)->getID() == "Gaoler ")	// Represent Enemy 1 with E1
				dungeon[y][x] = "E1";
			/*	2016-11-30:
				The treasure chest will only be displayed for a period of time, decided by the lifespan assigned to it on creation
				It will spawn when the spawn time matches the loop count, and disappear when the killtime matches the loopcount
			*/
			else if ((*it)->getID() == "Treasure" && treasureSpawnTime <= loopCount && treasureKillTime > loopCount)	// Only display a treasure chest in the allotted time
				dungeon[y][x] = "$$";
			/*	2016-11-30:
				The player needts to have a lamp to find the sword, he will only think to look for a weapon
				after he fails to negotiate an escape with the guard
			*/
			else if ((*it)->getID() == "Sword" && l1EnemyInteraction == true && (*pPlayer).hasLamp == true)				// Represent Sword
				dungeon[y][x] = "+-";
			/*	2016-11-30:
				The lamp is drawn in the same position as one of the regular wall lamps in the dungeon
				If the player collects the lamp he can use it to find the sword
				It may also come in useful once I've had some more bright ideas << Yes, I did a lamp joke
			*/
			else if ((*it)->getID() == "Lamp" && (*pPlayer).hasLamp == false)											// Represent Lamp
				dungeon[y][x] = "**";
			else if ((*it)->getID() == "Key") {																			// Represent Key
				dungeon[y-1][x] = " F";
				dungeon[y][x] = " O";
			}
		}
	}
	// Level 2 Game Object Positions
	if (level == 2) {
		for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
		{
			int x = (*it)->getX();					// Local variable to store x coord
			int y = (*it)->getY();					// local variable to store y coord

			if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == false)			// If the GameObject is Player represent it with an X
				hall[y][x] = "X ";					// COORDS REVERSED!!!
			else if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == true) {		// If the GameObject is Player represent it with an X
				if ((*pPlayer).getDirection() == West) {
					hall[y][x] = "X ";
					hall[y][x - 1] = "--";
				}
				else if ((*pPlayer).getDirection() == East) {
					hall[y][x] = " X";
					hall[y][x + 1] = "--";
				}
				else {
					hall[y][x] = "X ";
					if ((*pPlayer).getDirection() == NW) {
						hall[y - 1][x - 1] = " \\";
					}
					else if ((*pPlayer).getDirection() == North) {
						hall[y - 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == NE) {
						hall[y - 1][x] = " /";
					}
					else if ((*pPlayer).getDirection() == SW) {
						hall[y + 1][x - 1] = " /";
					}
					else if ((*pPlayer).getDirection() == South) {
						hall[y + 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == SE) {
						hall[y + 1][x] = " \\";
					}
				}
			}

			if (revealL2Map == true) {					// If the player is on the 2nd level or the map has been found in a treasure chest
														// Draw some tables and chairs in the Banquet Hall
				hall[2][3] = "[|"; hall[2][7] = "[|";
				hall[3][3] = "[|"; hall[3][7] = "[|";
				hall[4][3] = "[|"; hall[4][7] = "[|";
				hall[1][4] = "__"; hall[1][8] = "__";
				hall[4][4] = "__"; hall[4][8] = "__";
				hall[2][5] = "|]"; hall[2][9] = "|]";
				hall[3][5] = "|]"; hall[3][9] = "|]";
				hall[4][5] = "|]"; hall[4][9] = "|]";

				hall[2][15] = "[|"; hall[2][19] = "[|";
				hall[3][15] = "[|"; hall[3][19] = "[|";
				hall[4][15] = "[|"; hall[4][19] = "[|";
				hall[1][16] = "__"; hall[1][20] = "__";
				hall[4][16] = "__"; hall[4][20] = "__";
				hall[2][17] = "|]"; hall[2][21] = "|]";
				hall[3][17] = "|]"; hall[3][21] = "|]";
				hall[4][17] = "|]"; hall[4][21] = "|]";

				hall[20][3] = "[|"; hall[20][7] = "[|";
				hall[21][3] = "[|"; hall[21][7] = "[|";
				hall[22][3] = "[|"; hall[22][7] = "[|";
				hall[19][4] = "__"; hall[19][8] = "__";
				hall[22][4] = "__"; hall[22][8] = "__";
				hall[20][5] = "|]"; hall[20][9] = "|]";
				hall[21][5] = "|]"; hall[21][9] = "|]";
				hall[22][5] = "|]"; hall[22][9] = "|]";

				hall[20][15] = "[|"; hall[20][19] = "[|";
				hall[21][15] = "[|"; hall[21][19] = "[|";
				hall[22][15] = "[|"; hall[22][19] = "[|";
				hall[19][16] = "__"; hall[19][20] = "__";
				hall[22][16] = "__"; hall[22][20] = "__";
				hall[20][17] = "|]"; hall[20][21] = "|]";
				hall[21][17] = "|]"; hall[21][21] = "|]";
				hall[22][17] = "|]"; hall[22][21] = "|]";
			}
			/* The knights are hidden in the dark until the lights are turned on */
		//if (knightsAwake) {
			if ((*it)->getID() == "Sir Tom" && knightsAwake == true)	// Represent Enemy 2 with E2
				hall[y][x] = "E2";
			else if ((*it)->getID() == "Sir Bob" && knightsAwake == true)	// Represent Enemy 3 with E3
				hall[y][x] = "E3";
			//}
			else if ((*it)->getID() == "Treasure")	// Represent Enemy 9 with E4
				hall[y][x] = "$$";

		}
	}
	// Level 3 Game Object Positions
	if (level == 3) {
		for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
		{
			int x = (*it)->getX();					// Local variable to store x coord
			int y = (*it)->getY();					// local variable to store y coord

			if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == false)				// If the GameObject is Player represent it with an X
				tower[y][x] = "X ";					// COORDS REVERSED!!!
			else if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == true) {			// If the GameObject is Player represent it with an X
				if ((*pPlayer).getDirection() == West) {
					tower[y][x] = "X ";
					tower[y][x - 1] = "--";
				}
				else if ((*pPlayer).getDirection() == East) {
					tower[y][x] = " X";
					tower[y][x + 1] = "--";
				}
				else {
					tower[y][x] = "X ";
					if ((*pPlayer).getDirection() == NW) {
						tower[y - 1][x - 1] = " \\";
					}
					else if ((*pPlayer).getDirection() == North) {
						tower[y - 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == NE) {
						tower[y - 1][x] = " /";
					}
					else if ((*pPlayer).getDirection() == SW) {
						tower[y + 1][x - 1] = " /";
					}
					else if ((*pPlayer).getDirection() == South) {
						tower[y + 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == SE) {
						tower[y + 1][x] = " \\";
					}
				}
			}
			else if ((*it)->getID() == "Enemy 4")	// Represent Enemy 4 with E4
				tower[y][x] = "E4";
			else if ((*it)->getID() == "Enemy 5")	// Represent Enemy 5 with E1
				tower[y][x] = "E5";
			else if ((*it)->getID() == "Enemy 6")	// Represent Enemy 6 with E2
				tower[y][x] = "E6";
			else if ((*it)->getID() == "Treasure")	// Represent Enemy 9 with E4
				tower[y][x] = "$$";
			else if ((*it)->getID() == "Sword")		// Represent Enemy 9 with E4
				tower[y][x] = "+-";
		}
	}
	
	if (level == 4) {
		for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
		{
			int x = (*it)->getX();					// Local variable to store x coord
			int y = (*it)->getY();					// local variable to store y coord

			if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == false)				// If the GameObject is Player represent it with an X
				tower[y][x] = "X ";					// COORDS REVERSED!!!
			else if ((*it)->getID() == "Player" && (*pPlayer).getHasSword() == true) {			// If the GameObject is Player represent it with an X
				if ((*pPlayer).getDirection() == West) {
					tower[y][x] = "X ";
					tower[y][x - 1] = "--";
				}
				else if ((*pPlayer).getDirection() == East) {
					tower[y][x] = " X";
					tower[y][x + 1] = "--";
				}
				else {
					tower[y][x] = "X ";
					if ((*pPlayer).getDirection() == NW) {
						tower[y - 1][x - 1] = " \\";
					}
					else if ((*pPlayer).getDirection() == North) {
						tower[y - 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == NE) {
						tower[y - 1][x] = " /";
					}
					else if ((*pPlayer).getDirection() == SW) {
						tower[y + 1][x - 1] = " /";
					}
					else if ((*pPlayer).getDirection() == South) {
						tower[y + 1][x] = "| ";
					}
					else if ((*pPlayer).getDirection() == SE) {
						tower[y + 1][x] = " \\";
					}
				}
			}
			else if ((*it)->getID() == "Enemy 4")	// Represent Enemy 4 with E4
				tower[y][x] = "E4";
			else if ((*it)->getID() == "Enemy 5")	// Represent Enemy 5 with E1
				tower[y][x] = "E5";
			else if ((*it)->getID() == "Enemy 6")	// Represent Enemy 6 with E2
				tower[y][x] = "E6";
			else if ((*it)->getID() == "Treasure")	// Represent Enemy 9 with E4
				tower[y][x] = "$$";
			else if ((*it)->getID() == "Sword")		// Represent Enemy 9 with E4
				tower[y][x] = "+-";
		}
	}

	// IMPACT POINT	 - store an impact point for each object to display where the object collided with the border
	for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); it++)
	{
		int impactX = (*it)->getImpactX();					// Get impact x coord
		int impactY = (*it)->getImpactY();					// Get impact y coord
		dungeon[impactY][impactX] = "@ ";
		dungeon[0][0] = "* ";								// Using 0s to reset impactX and impactY 		
															// reset impact point
		(*it)->setImpactX(0);								// reset impactX so impact points only draw once
		(*it)->setImpactY(0);								// reset impactY so impact points only draw once
	}

	/* PRINT THE MAP */
	SetConsoleTextAttribute(hstdout, 0x0F);					// Black bg, White txt
	std::cout << "  ";
	SetConsoleTextAttribute(hstdout, 0xF9);					// White bg, Blue txt -> Grid Heading
	std::cout << "       LEVEL 1 PLAYER & ENEMY POSITIONS:        ";
	std::cout << "         LEVEL 2 PLAYER & ENEMY POSITIONS:        ";
	std::cout << "         LEVEL 3 PLAYER & ENEMY POSITIONS:        ";
	std::cout << "        BOSS LEVEL PLAYER & ENEMY POSITIONS:       " << std::endl;
	SetConsoleTextAttribute(hstdout, 0x0F);					// Black bg, White txt

	// CA2 - Display an ASCII map
	for (int i = 0; i < 25; i++) {
		std::cout << "  ";	// Step the grid in two spaces to the right

// CA2 - Draw the 1st grid (Dungeon)
		for (int j = 0; j < 25; j++) {
			if (level == 1) {
				if (dungeon[i][j] == "X " || dungeon[i][j] == " X" || dungeon[i][j] == "-X" || dungeon[i][j] == "! ")						// X - represents the Player
					SetConsoleTextAttribute(hstdout, 0x0C);				// Black bg, Red txt
				else if (dungeon[i][j] == "E1" || dungeon[i][j] == "E2" || dungeon[i][j] == "E3" || dungeon[i][j] == "E4" || dungeon[i][j] == "E5" || dungeon[i][j] == "E6" || dungeon[i][j] == "E7" || dungeon[i][j] == "E8") {	// Enemies
					if (getDaylight()) 								// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x0A);			// Black bg, Green txt
					else
						SetConsoleTextAttribute(hstdout, 0x02);			// Black bg, Dark Green txt
					}
				else if (dungeon[i][j] == "EB")							// Enemy Boss
					SetConsoleTextAttribute(hstdout, 0x05);				// Black bg, Purple txt
				else if (dungeon[i][j] == "$$")							// $$ - represents a treasure chest
					SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
				else if (dungeon[i][j] == "+-")							// +- - Represenents a sword
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (dungeon[i][j] == "* ") {						// * - represents the border of the grid
					if (getDaylight())									// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x0C);			// Black bg, Light Red txt
					else
						SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
				}
				else if (dungeon[i][j] == " *") {						// * - Represents a wall lamp
					if (getDaylight())									// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt
					else
						SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt
				}
				/*	2016-11-30:
					If the player hasn't already added the lamp to his inventory 
					Draw it on the wall where one of the regular lamps would normally be
				*/
				else if (dungeon[i][j] == "**" && (*pPlayer).getHasLamp() == false) {	// ** - Represents the wall lamp for the player to collect
					if (getDaylight())									// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt
					else
						SetConsoleTextAttribute(hstdout, 0x0F);			// Black bg, White txt, the change in colour should make the lamp stand out from the others
				}
				/* Set the window colour to torquise in daytime and blue at nighttime */
				else if ((dungeon[i][j] == "| " && j == 0) || (dungeon[i][j] == "--" && (i == 0 || i == 24))) {	// -- - represents the windows
					if (getDaylight())									// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x0B);			// Black bg, Torquoise txt
					else
						SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Navy txt
				}
				//else if (dungeon[i][j] == "| " && i == 0)				// Windows
				//	SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				/*	CA1:
					Draw a rebound mark for when a Player or Enemy object hits the perimiter wall
				*/
				else if (dungeon[i][j] == "@ ")							// @ represents impact point on boundary
					SetConsoleTextAttribute(hstdout, 0x04);				// Black bg, Dark Red txt
				/*	2016-11-28:
					If the enemy has been defeated and the player has all the items necessary to complete the level 
					Draw the key Object
				*/
				else if (dungeon[i][j] == " O") {// Key for the door
																																				 //else if (dungeon[i][j] == " O" || dungeon[i][j] == " F")	// Key for the door
					if ((*pPlayer).getHasLamp() == true && (*pPlayer).getHasSword() == true)
						SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
					else
						SetConsoleTextAttribute(hstdout, 0x00);				// Black bg, Yellow txt
				}
				else if (dungeon[i][j] == " F") {// Key for the door
																																				 //else if (dungeon[i][j] == " O" || dungeon[i][j] == " F")	// Key for the door
					if ((*pPlayer).getHasLamp() == true && (*pPlayer).getHasSword() == true)
						SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
					else
						SetConsoleTextAttribute(hstdout, 0x00);				// Black bg, Yellow txt
				}
				/* Draw a locked door in the perimiter of the grid */
				else if (dungeon[i][j] == " |" && (i == 12 && j == 24)) {	// Locked Door
					if (getDaylight())
						SetConsoleTextAttribute(hstdout, 0x09);			// Black bg, Light Blue txt
					else
						SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Dark Blue txt
				}
				/* Unlocked door symbol */
				else if (dungeon[i][j] == "__" && (i == 12 && j == 23)) {	// Unlocked Door
					if (getDaylight())
						SetConsoleTextAttribute(hstdout, 0x09);			// Black bg, Light Blue txt
					else
						SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Dark Blue txt
				}
				/* CA2 - Draw the sword */
					else if (dungeon[i][j] == " /" && dungeon[i - 1][j + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SW)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == "| " && dungeon[i - 1][j] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == South)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == " \\" && dungeon[i - 1][j] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SE)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == "--" && dungeon[i][j + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == West)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == "--" && dungeon[i][j - 1] == " X" && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == East)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == "| " && dungeon[i + 1][j] == "X " && (*pPlayer).getHasSword() == true && ((*pPlayer).getDirection() == North || (*pPlayer).getDirection() == 5))
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == " /" && dungeon[i + 1][j] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == NE)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (dungeon[i][j] == " \\" && dungeon[i - 1][j] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SE)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if ((dungeon[i][j] == " \\" && dungeon[i + 1][j + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == NW))
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				//}
				/* The rest of the ASCII characters make up the text in the background of the rooms of the map */
				else													// Background text in the arena
					SetConsoleTextAttribute(hstdout, 0x08);				// Black bg, Grey txt
			}
			/* If it's daylight set colour bright red, if night-time dark red */
			else {
				if (getDaylight() == true)
					SetConsoleTextAttribute(hstdout, 0x0C);				// Black bg, Red txt
				else
					SetConsoleTextAttribute(hstdout, 0x04);				// Black bg, Dark Red txt}
				if (dungeon[i][j] == " *" || dungeon[i][j] == "**") 	// * - Represents a wall lamp && ** - Represents the lamp for the player to collect to find the sword
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt
			}
			std::cout << dungeon[i][j];									// Print each array position for dungeon
		}

// CA2 - Draw the 2nd grid (Banquet Hall) including windows, door, lamps, swords, treasure chests
		for (int k = 0; k < 25; k++) {
			/*	2016-11-30:
				If the player reveals a map in a treasure chest the 2nd level map can be fully revealed 
			*/

			if (level == 2 || revealL2Map == true) {					// If the player is on the 2nd level or the map has been found in a treasure chest
				// Draw some tables and chairs in the Banquet Hall
				/* TABLES AND CHAIRS*/
				{
					hall[2][3] = "[|"; hall[2][7] = "[|";
					hall[3][3] = "[|"; hall[3][7] = "[|";
					hall[4][3] = "[|"; hall[4][7] = "[|";
					hall[1][4] = "__"; hall[1][8] = "__";
					hall[4][4] = "__"; hall[4][8] = "__";
					hall[2][5] = "|]"; hall[2][9] = "|]";
					hall[3][5] = "|]"; hall[3][9] = "|]";
					hall[4][5] = "|]"; hall[4][9] = "|]";

					hall[2][15] = "[|"; hall[2][19] = "[|";
					hall[3][15] = "[|"; hall[3][19] = "[|";
					hall[4][15] = "[|"; hall[4][19] = "[|";
					hall[1][16] = "__"; hall[1][20] = "__";
					hall[4][16] = "__"; hall[4][20] = "__";
					hall[2][17] = "|]"; hall[2][21] = "|]";
					hall[3][17] = "|]"; hall[3][21] = "|]";
					hall[4][17] = "|]"; hall[4][21] = "|]";

					hall[20][3] = "[|"; hall[20][7] = "[|";
					hall[21][3] = "[|"; hall[21][7] = "[|";
					hall[22][3] = "[|"; hall[22][7] = "[|";
					hall[19][4] = "__"; hall[19][8] = "__";
					hall[22][4] = "__"; hall[22][8] = "__";
					hall[20][5] = "|]"; hall[20][9] = "|]";
					hall[21][5] = "|]"; hall[21][9] = "|]";
					hall[22][5] = "|]"; hall[22][9] = "|]";

					hall[20][15] = "[|"; hall[20][19] = "[|";
					hall[21][15] = "[|"; hall[21][19] = "[|";
					hall[22][15] = "[|"; hall[22][19] = "[|";
					hall[19][16] = "__"; hall[19][20] = "__";
					hall[22][16] = "__"; hall[22][20] = "__";
					hall[20][17] = "|]"; hall[20][21] = "|]";
					hall[21][17] = "|]"; hall[21][21] = "|]";
					hall[22][17] = "|]"; hall[22][21] = "|]";
				}
				
				/* TREASURE */
				if (hall[i][k] == "$$")									// $$ - represents a treasure chest
					SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
				else if (hall[i][k] == "+-")							// +- - Represenents a sword
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				/* WALL */
				else if (hall[i][k] == "* ") {							// * - represents the border of the grid
					SetConsoleTextAttribute(hstdout, 0x01); 			// Black bg, Blue txt
				if (getDaylight() == true && knightsAwake == true)		// Change colour for day and night
					SetConsoleTextAttribute(hstdout, 0x09);				// Black bg, Blue txt
				else
					SetConsoleTextAttribute(hstdout, 0x01);				// Black bg, Dark Blue txt
				}
				/* LAMPS */
				// North
				else if (hall[1][12] == " *" && (i == 1 && k == 12) && lamp1Lit) {
					SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow tx

					if (knightsAwake && getDaylight() == true)
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Yellow txt
					else if (knightsAwake && getDaylight() == false)
						SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt		
				}

				//South
				else if (hall[23][12] == " *" && (i == 23 && k == 12) && lamp2Lit) {				// OK
					SetConsoleTextAttribute(hstdout, 0x0E);				// Black bg, Yellow txt

					if (knightsAwake && getDaylight() == true)
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Yellow txt
					else if (knightsAwake && getDaylight() == false)
						SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt						
				}


				else if (((i == 4 && k == 0) || (i == 20 && k == 0)) && lamp3Lit) {
						if (lamp3Lit)
							SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt
						else if (knightsAwake && getDaylight() == true)
						{
							hall[0][4] = "* ";
							hall[0][20] = "* ";
						}

					SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt
				}
				else if (((i == 4 && k == 23) || (i == 20 && k == 23) || (i == 12 && k == 23)) && lamp4Lit) {
					SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt

					if (knightsAwake && getDaylight() == true)
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Yellow txt
					else if (knightsAwake && getDaylight() == false)
						SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt		
				}




				else if (hall[i][k] == "==" && (i == 0 || i == 24)) {	// -- - represents the windows
					if (getDaylight() == true && knightsAwake == true)									// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x0B);			// Black bg, Torquoise txt
					else
						SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Navy txt
				}
				else if (hall[i][k] == "@ ")							// @ represents impact point on boundary
					SetConsoleTextAttribute(hstdout, 0x04);				// Black bg, Dark Red txt
				/* KEY */
				else if (hall[i][k] == "O " || hall[i][k] == "F ")	// Key for the door
					SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
				/* DOOR */
				else if (hall[i][k] == "| " && (i == 12 && k == 0)) {	// Locked Door
					if (getDaylight() == true && knightsAwake == true)
						SetConsoleTextAttribute(hstdout, 0x0C);			// Black bg, Light Red txt
					else
						SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
				}
				else if (hall[i][k] == " |" && (i == 1 && k == 24)) {	// Locked Door
					if (getDaylight() == true && knightsAwake == true)
						SetConsoleTextAttribute(hstdout, 0x06);			// Black bg, Light Red txt
					else
						SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
				}
				else if (hall[i][k] == "__" && (i == 12 && k == 1)) {	// Unlocked Door
					if (getDaylight() == true && knightsAwake == true)
						SetConsoleTextAttribute(hstdout, 0x0C);			// Black bg, Light Red txt
					else
						SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
				}
				/* DRAW THE SWORD */
				else if (hall[i][k] == " /" && hall[i - 1][k + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SW)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == "| " && hall[i - 1][k] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == South)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == " \\" && hall[i - 1][k] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SE)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == "--" && hall[i][k + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == West)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == "--" && hall[i][k - 1] == " X" && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == East)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == "| " && hall[i + 1][k] == "X " && (*pPlayer).getHasSword() == true && ((*pPlayer).getDirection() == North || (*pPlayer).getDirection() == 5))
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == " /" && hall[i + 1][k] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == NE)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if (hall[i][k] == " \\" && hall[i - 1][k] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SE)
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				else if ((hall[i][k] == " \\" && hall[i + 1][k + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == NW))
					SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
				/* DRAW PLAYER RED */
				else if (hall[i][k] == "X " || hall[i][k] == " X" || hall[i][k] == "-X" || hall[i][k] == "! ")						// X - represents the Player
					SetConsoleTextAttribute(hstdout, 0x0C);				// Black bg, Red txt
				/* DRAW ENEMIES GREEN */
				else if (hall[i][k] == "E1" || hall[i][k] == "E2" || hall[i][k] == "E3") {	// Enemies
					if (getDaylight() == true && knightsAwake == true)	// Change colour for day and night
						SetConsoleTextAttribute(hstdout, 0x0A);			// Black bg, Green txt
					else if (getDaylight() == false)
						SetConsoleTextAttribute(hstdout, 0x02);			// Black bg, Dark Green txt
					else
						SetConsoleTextAttribute(hstdout, 0x02);			// Black bg, Dark Green txt
				}
				/* DRAW EVERYTHING ELSE GREY */
				else {
					if (getDaylight() == true && knightsAwake == true)
						SetConsoleTextAttribute(hstdout, 0x07);			// Black bg, Light Grey txt
					else
						SetConsoleTextAttribute(hstdout, 0x08);			// Black bg, Dark Grey txt
				}
			}			
			else {
				if (getDaylight())
					SetConsoleTextAttribute(hstdout, 0x09);			// Black bg, Light Grey txt
				else
					SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Dark Grey txt
				if (hall[i][k] == " *" && knightsAwake) 								// * - Represents a wall lamp
					SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt
			}
			
			std::cout << hall[i][k];
		}

// CA2 - Draw the 3rd grid (Maiden Tower)
		for (int l = 0; l < 25; l++) {
				if (getDaylight())
					SetConsoleTextAttribute(hstdout, 0x0A);			// Black bg, Light Grey txt
				else
					SetConsoleTextAttribute(hstdout, 0x02);			// Black bg, Dark Grey txt



				if (level == 2) {
					if (tower[i][l] == "X " || tower[i][l] == " X" || tower[i][l] == "-X" || tower[i][l] == "! ")						// X - represents the Player
						SetConsoleTextAttribute(hstdout, 0x0C);				// Black bg, Red txt
					else if (tower[i][l] == "E1" || tower[i][l] == "E2" || tower[i][l] == "E3") {	// Enemies
						if (getDaylight())									// Change colour for day and night
							SetConsoleTextAttribute(hstdout, 0x0A);			// Black bg, Green txt
						else
							SetConsoleTextAttribute(hstdout, 0x02);			// Black bg, Dark Green txt
					}
					else if (tower[i][l] == "$$")							// $$ - represents a treasure chest
						SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
					else if (tower[i][l] == "+-")							// +- - Represenents a sword
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == "* ") {							// * - represents the border of the grid
						SetConsoleTextAttribute(hstdout, 0x01); 			// Black bg, Blue txt{
						if (getDaylight())										// Change colour for day and night
							SetConsoleTextAttribute(hstdout, 0x09);				// Black bg, Blue txt
						else
							SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Dark Blue txt
					}
					else if (tower[i][l] == " *") {							// * - Represents a wall lamp
						if (getDaylight())									// Change colour for day and night
							SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt
						else
							SetConsoleTextAttribute(hstdout, 0x0E);			// Black bg, Yellow txt
					}
					else if (tower[i][l] == "--" && (i == 0 || i == 24)) {	// -- - represents the windows
						if (getDaylight())									// Change colour for day and night
							SetConsoleTextAttribute(hstdout, 0x0B);			// Black bg, Torquoise txt
						else
							SetConsoleTextAttribute(hstdout, 0x01);			// Black bg, Navy txt
					}
					else if (tower[i][l] == "@ ")							// @ represents impact point on boundary
						SetConsoleTextAttribute(hstdout, 0x04);				// Black bg, Dark Red txt
					else if (tower[i][l] == "O " || tower[i][l] == "F ")	// Key for the door
						SetConsoleTextAttribute(hstdout, 0x06);				// Black bg, Yellow txt
					else if (tower[i][l] == "| " && (i == 12 && l == 0)) {	// Locked Door
						if (getDaylight())
							SetConsoleTextAttribute(hstdout, 0x0C);			// Black bg, Light Red txt
						else
							SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
					}
					else if (tower[i][l] == " |" && (i == 1 && l == 24)) {	// Locked Door
						if (getDaylight())
							SetConsoleTextAttribute(hstdout, 0x06);			// Black bg, Light Red txt
						else
							SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
					}
					else if (tower[i][l] == "__" && (i == 12 && l == 1)) {	// Unlocked Door
						if (getDaylight())
							SetConsoleTextAttribute(hstdout, 0x0C);			// Black bg, Light Red txt
						else
							SetConsoleTextAttribute(hstdout, 0x04);			// Black bg, Dark Red txt
					}
					/* CA2 - Draw the sword */
					else if (tower[i][l] == " /" && tower[i - 1][l + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SW)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == "| " && tower[i - 1][l] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == South)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == " \\" && tower[i - 1][l] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SE)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == "--" && tower[i][l + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == West)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == "--" && tower[i][l - 1] == " X" && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == East)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == "| " && tower[i + 1][l] == "X " && (*pPlayer).getHasSword() == true && ((*pPlayer).getDirection() == North || (*pPlayer).getDirection() == 5))
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == " /" && tower[i + 1][l] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == NE)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if (tower[i][l] == " \\" && tower[i - 1][l] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == SE)
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else if ((tower[i][l] == " \\" && tower[i + 1][l + 1] == "X " && (*pPlayer).getHasSword() == true && (*pPlayer).getDirection() == NW))
						SetConsoleTextAttribute(hstdout, 0x0B);				// Black bg, Torquise txt
					else {
						if (getDaylight())
							SetConsoleTextAttribute(hstdout, 0x07);			// Black bg, Light Grey txt
						else
							SetConsoleTextAttribute(hstdout, 0x08);			// Black bg, Dark Grey txt
					}
				}
				else {
					if (getDaylight())
						SetConsoleTextAttribute(hstdout, 0x0A);			// Black bg, Light Green txt
					else
						SetConsoleTextAttribute(hstdout, 0x02);			// Black bg, Dark Green txt
					if (hall[i][l] == " *") 							// * - Represents a wall lamp
						SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt
				}
			std::cout << tower[i][l];
		}

// CA2 - Draw the 4th grid (Boss Level)
		for (int m = 0; m < 25; m++) {
			if (getDaylight())
				SetConsoleTextAttribute(hstdout, 0x0B);			// Black bg, Light Grey txt
			else
				SetConsoleTextAttribute(hstdout, 0x03);			// Black bg, Dark Grey txt
			if (arena[i][m] == " *") 							// * - Represents a wall lamp
				SetConsoleTextAttribute(hstdout, 0x00);			// Black bg, Black txt

			std::cout << arena[i][m];
		}
		std::cout << std::endl;								// New line
	}
}



/*  CA 1:
	Calculate the health bar size for the player and enemy objects
	An enemy bar is 8 characters long and a player or boss health bar is 32 characters
	If an enemy is killed the bar reads "R.I.P."
*/
void Game::calcHealthBar(int barSize, char* objectID)
{
	int posHealth=0, negHealth;
	char* barUnit = "_";

	std::list<GameObject*>::const_iterator it = listOfGameObjects.begin(); // Iterator set to start of list

	while (it != listOfGameObjects.end()) {				// Cycle through loop
		if ((*it)->getID() == objectID)	{				// If object matches the one passed to the function
			if (barSize == LARGE_BAR) {					// Player health bar size 32
				posHealth = (*it)->getHealth() / 5;		// positive  -  Divide Health by 5 to get each bar unit
				barUnit = "_";							// Blue line separates health Bars
				if (posHealth == 0 && (*it)->getHealth() > 0)
					posHealth = 1;						// CA2 - Don't draw empty bar unless player is dead
			}
			else {										// Enemy bar size 8
				posHealth = (*it)->getHealth() / 20;	// positive  -  Bar Size 8 -> divide by 20
				if (posHealth == 0 && (*it)->getHealth() > 0)
					posHealth = 1;						// CA2 - Don't draw empty bar unless enemy is dead
			}
		}
		++it;											// Increment iterator
	}

	// PRINT THE BARS	
	negHealth = barSize - posHealth;					// Calculate negative health
	SetConsoleTextAttribute(hstdout, 0xC0);				// Red BG, Black txt
	if (posHealth == 0 && barSize == SMALL_BAR)			// If Objects health is 0
		std::cout << " R.I.P. ";						// Its dead
	else if (posHealth == 0 && barSize == LARGE_BAR)	// If Objects health is 0
		std::cout << "             R.I.P.             ";// Its dead
	else {
		SetConsoleTextAttribute(hstdout, 0x29);			// Positive Green
		for (int i = 0; i < posHealth; i++)
			std::cout << barUnit;
		SetConsoleTextAttribute(hstdout, 0xC9);			// Negative Red
		for (int i = 0; i < negHealth; i++)
			std::cout << barUnit;
	}
	SetConsoleTextAttribute(hstdout, 0x9F);				// Reset colour, Blue BG, Black txt
}

/*	2016-01-29:
	Calculate the stat bar size to give a visual representation of the skill level of the player
	If the players skill is 0 an empty bar with the word "Novice" is displayed
	The bar size is 8 characters long
*/
void Game::calcSkillBar() {
	int posSkill = 0, negSkill;
	char* barUnit = "_";

	posSkill = (*pPlayer).getSkill() / 20;				// positive  -  Bar Size 8 -> divide by 20

														// PRINT THE BARS	
	negSkill = SMALL_BAR - posSkill;					// Calculate negative skill
	SetConsoleTextAttribute(hstdout, 0xB0);				// Red BG, Black txt
	if ((*pPlayer).getSkill() == 0)									// If players skill is 0
		std::cout << " Novice ";						// Player has no skill
	else {
		SetConsoleTextAttribute(hstdout, 0xB9);			// Positive Green
		for (int i = 0; i < posSkill; i++)
			std::cout << barUnit;
		SetConsoleTextAttribute(hstdout, 0xC9);			// Negative Red
		for (int i = 0; i < negSkill; i++)
			std::cout << barUnit;
	}
	SetConsoleTextAttribute(hstdout, 0x9F);				// Reset colour, Blue BG, White txt
}

/*	2016-01-29:
	Calculate the stat bar size to give a visual representation of the luck level of the player
	If the players luck is 0 an empty bar with the word "Wretch" is displayed
	The bar size is 8 characters long
*/
void Game::calcPoxBar() {
	int posPox = 0, negPox;
	char* barUnit = "_";

	posPox = (*pPlayer).getPoxiness() / 20;				// positive  -  Bar Size 8 -> divide by 20

														// PRINT THE BARS	
	negPox = SMALL_BAR - posPox;						// Calculate negative luck
	SetConsoleTextAttribute(hstdout, 0x30);				// Red BG, Black txt
	if ((*pPlayer).getPoxiness() == 0)									// If players luck is 0
		std::cout << " Wretch ";						// Player has no luck
	else {
		SetConsoleTextAttribute(hstdout, 0xB9);			// Positive Green
		for (int i = 0; i < posPox; i++)
			std::cout << barUnit;
		SetConsoleTextAttribute(hstdout, 0xC9);			// Negative Red
		for (int i = 0; i < negPox; i++)
			std::cout << barUnit;
	}
	SetConsoleTextAttribute(hstdout, 0x9F);				// Reset colour, Blue BG, White txt
}

/*	2016-01-29:
	Calculate the stat bar size to give a visual representation of the luck level of the player
	If the players strength is 0 an empty bar with the word "Weakling" is displayed
	The bar size is 8 characters long
*/
void Game::calcStrengthBar() {
	int posStrength = 0, negStrength;
	char* barUnit = "_";

	posStrength = (*pPlayer).getPoxiness() / 20;		// positive  -  Bar Size 8 -> divide by 20

														// PRINT THE BARS	
	negStrength = SMALL_BAR - posStrength;				// Calculate negative Strength
	SetConsoleTextAttribute(hstdout, 0x30);				// Red BG, Black txt
	if ((*pPlayer).getStrength() == 0)					// If players strength is 0
		std::cout << "Weakling";						// Player has no stength
	else {
		SetConsoleTextAttribute(hstdout, 0xB9);			// Positive Green
		for (int i = 0; i < posStrength; i++)
			std::cout << barUnit;
		SetConsoleTextAttribute(hstdout, 0xC9);			// Negative Red
		for (int i = 0; i < negStrength; i++)
			std::cout << barUnit;
	}
	SetConsoleTextAttribute(hstdout, 0x9F);				// Reset colour, Blue BG, White txt
}



/*	2016-11-29:
	Added level complete conditions, and messages to display
	CA1:
	Game Over Messages
*/
int Game::GameOver() {
	int result = getGameResult();									// Decide which message to display	

	if (hasKey)
		result = L1Complete;
	else if (result == Undecided) {
		for (it = listOfGameObjects.begin(); it != listOfGameObjects.end(); ++it) {
			if ((*it)->getID() == "Player" && listOfGameObjects.size() == 1) {	// No Enemies on list
				if (level == 1) {									// Level 1 Complete
					result = L1Complete;
				}
				else if (level == 2) {								// Level 2 Complete
					result = L2Complete;
				}
				else if (level == 3) {								// Level 3 Complete
					result = L3Complete;
				}
				else if (level == 4) {								// Level 4 Complete
					result = Win;									// Win Game
				}
			}
			if ((*listOfGameObjects.begin())->getID() != "Player")	// Player erased
				result = Lose;										// Lose Game
		}
	}

	if (result == L1Complete && level == 1) {
		ClearScreen();
		SetConsoleTextAttribute(hstdout, 0x9F);
		logo.drawLevel1();
		logo.drawComplete();
		SetConsoleTextAttribute(hstdout, 0x0F);
		spiel.l1Complete();						// Display the end of level text
		SetConsoleTextAttribute(hstdout, 0x0F);	// Reset Console text: Black BG, White txt

		++level;								// go to next level
		level2Setup();
	}
	else if (result == L2Complete && level == 1) {
		ClearScreen();
		SetConsoleTextAttribute(hstdout, 0x9F);
		logo.drawLevel2();
		logo.drawComplete();

		++level;								// go to next level
	}
	else if (result == Lose || result == Win) {
		ClearScreen();						// Clear the screen
		SetConsoleTextAttribute(hstdout, 0x9F);
		logo.drawGameOver();				// Display the game over logo
	}

	// Display different message for win lose draw
	if (result == Lose)						
		logo.drawLoser();					// Display Loser Logo
	else if (result == Win)
		logo.drawWinner();					// Display Winner Logo

	SetConsoleTextAttribute(hstdout, 0x0F);	// Reset Console text: Black BG, White txt

	return result;
	//setGameResult(result);
}

int Game::getGameResult() {
	return gameState;
}
void Game::setGameResult(int result) {
	gameState = result;
}

/* 2016-11-27:
	Functions to decide if it is day or nightime
*/
void Game::setDayTime(bool day) {
	isDayTime = day;
}
bool Game::getDaylight() {
	return isDayTime;
}
