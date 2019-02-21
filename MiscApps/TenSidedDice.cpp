// Joe O'Regan
// 09-09-2016
// 2 x 10 sided coloured dice ...in technicolor

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>	// for coloured text

using namespace std;

int main()
{	
	char rollAgain = 'y';
	
	// ADD COLOURS:
	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );	
	// Original colours
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	
	srand(static_cast<unsigned int>(time(0)));  	// seed random number generator based on current time
	
	SetConsoleTextAttribute( hstdout, 0xF9 );		// blue text
	cout << endl << "     Generate a number    \n    Between 1 and 100     " << endl << endl;
	SetConsoleTextAttribute( hstdout, 0x08 );		// black bg, grey txt
	cout << "Note:\n If the red dice rolls \n a 10 this represents the \n value 0 in the 10s units" << endl << endl;
	
	do
	{
		int randomNumber1 = rand();					// select random number
		int randomNumber2 = rand();
	
		int redDice = (randomNumber1 % 10) + 1;		// value from 1 to 10
		int greenDice = (randomNumber2 % 10) + 1;
		
		if(redDice == 10) redDice = 0;				// if the red dice is a 10, value is 0
		int generatedNumber = (redDice * 10) + greenDice;
		
		SetConsoleTextAttribute( hstdout, 0x0F );	// white text
		cout << "The ";
		SetConsoleTextAttribute( hstdout, 0x0C );	// red text
		cout << "Red Dice";
		SetConsoleTextAttribute( hstdout, 0x0F );
		cout << " Is: " << redDice << endl;
		
		cout << "The ";
		SetConsoleTextAttribute( hstdout, 0x0A );	// green text
		cout << "Green Dice";
		SetConsoleTextAttribute( hstdout, 0x0F );
		cout << " Is: " << greenDice << endl << endl;
		
		SetConsoleTextAttribute( hstdout, 0x0F );
		cout << "Generated Number: " << generatedNumber << endl << endl;
		
		cout << "Roll Again? Y/N: ";
		cin >> rollAgain;
		
		cout << endl;
		
	}while((rollAgain != 'n') && (rollAgain != 'N'));
	
	// Reset colours
	FlushConsoleInputBuffer( hstdin );
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );

    return 0;
}
