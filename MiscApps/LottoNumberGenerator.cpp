// Joe O'Regan
// 13-09-2016

// selects random numbers
// sorts the numbers

// Fixed not taking out duplicates but restarts function
// Added colour for numbers
// Tracks the numbers to show where unique numbers were replaced
// Tagged the number that isn't unique


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>	// for coloured text
#include <iomanip>		// add fill at start of coloured numbers, because it just looks wrong

using namespace std;

// Functions
void getRandomNumber();
void checkUnique(int num);
void sortArray();			// OK
void outputNumbers();		// OK
int getNewNumber();			// OK

// Global Variables
int numbersArray[6] = {0, 0, 0, 0, 0, 0};		// initialise numbers to 0;
int arrayPosition = 0;	// FOR EACH POSITION OF THE ARRAY GENERATE A NEW NUMBER
int number, randomNumber;
// Colour Stuff
HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

int main()
{
	char retry = 'y';	
	
	// Keep track of oginal colours
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );
	
	srand(static_cast<unsigned int>(time(0)));	// seed random number generator based on current time
	
	SetConsoleTextAttribute( hstdout, 0xF1 );	// White bg, navy txt
	cout << endl << "        NATIONAL LOTTERY        " << endl;
	SetConsoleTextAttribute( hstdout, 0x0A );	// black bg, green txt
	cout << "      Lotto Number Picker!" << endl;
	SetConsoleTextAttribute( hstdout, 0x0F );	// black bg, white txt
		
	do
	{
	
		// Pick 1st number (don't need to check first number generated for uniqueness)
		int firstNumber = getNewNumber();
		numbersArray[0] = firstNumber;	
		
		SetConsoleTextAttribute( hstdout, 0x08 );	// black bg, grey txt
		cout << endl << "Number 1: ";		
		SetConsoleTextAttribute( hstdout, 0x0F );	// black bg, white txt
		cout << firstNumber;	// Track random numbers
		
		getRandomNumber();
		sortArray();
		outputNumbers();
	
		cout << "Try Again? Y/N: ";
		cin >> retry;	
		cout << endl;		
	}while((retry != 'n') && (retry != 'N'));
	
	// Reset colours
	FlushConsoleInputBuffer( hstdin );
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
	
    return 0;
}

// NEED TO RESTART THIS FUNCTION IF NUMBERS ARE DUPLICATE!!!
// generate the next 5 random numbers
void getRandomNumber()
{
	for(int arrayPosition = 1; arrayPosition < 6; ++arrayPosition)
	{
		getNewNumber();
		checkUnique(arrayPosition);		
	}
}

void checkUnique(int pos)
{
	// Track Random numbers
	SetConsoleTextAttribute( hstdout, 0x08 );	// black bg, grey txt
	cout << endl << "Number " << pos + 1 << ": ";
	SetConsoleTextAttribute( hstdout, 0x0F );	// black bg, white txt
	cout << number;
	
	for (int i = 0; i < pos; ++i)
	{
		if(numbersArray[i] != number)
			numbersArray[pos] = number;	
		else
		{
			SetConsoleTextAttribute( hstdout, 0x0C );	// black bg, red txt
			cout << "\tNOT UNIQUE!";
			SetConsoleTextAttribute( hstdout, 0x0F );	// black bg, white txt
			int newUnique = getNewNumber();
			checkUnique(pos);
		}
	}
}

// Pick A Random Number
int getNewNumber()
{
	randomNumber = rand();					// generate random number			
	number = (randomNumber % 47) + 1;		// get a number between 1 and 47
	
	return number;
}

// Sort the array of numbers in ascending order
void sortArray()
{
	int temp;
	for(int i=0;i<6;i++)
	{
		for (int j = 0; j < (6 - i - 1); j++)
		{	
			if (numbersArray[j] > numbersArray[j + 1])
	       	{
	           temp = numbersArray[j];
	           numbersArray[j] = numbersArray[j + 1];
	           numbersArray[j + 1] = temp;
	        }
		}
	}
}

// Output the random numbers array
void outputNumbers()
{
	cout << endl << endl << "The ";
	SetConsoleTextAttribute( hstdout, 0x0A );	// green bg, white txt
	cout << "Lotto";
	SetConsoleTextAttribute( hstdout, 0x0F );	// black bg, white txt
	cout << " numbers selected are: " << endl;
	for (int i = 0; i < 6; ++i)
	{
		int displayNumber = numbersArray[i];
		if(displayNumber % 4 == 2)
			SetConsoleTextAttribute( hstdout, 0xCF );	// red bg, white txt
		else if(displayNumber % 4 == 1)
			SetConsoleTextAttribute( hstdout, 0xAF );	// green bg, white txt
		else if(displayNumber % 4 == 3)
			SetConsoleTextAttribute( hstdout, 0x9F );	// blue bg, white txt
		else if(displayNumber % 4 == 0)
			SetConsoleTextAttribute( hstdout, 0xE0 );	// yellow(orange) bg, white txt
		
		cout << setfill('0') << setw(2);
		cout << displayNumber;
		SetConsoleTextAttribute( hstdout, 0x0F );	// black bg, white txt
		
		if (i < 5) cout << ", ";
	}
	cout << endl << endl;
}
