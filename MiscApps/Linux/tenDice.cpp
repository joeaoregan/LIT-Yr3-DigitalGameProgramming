// Joe O'Regan
// 09-09-2016
// 2 x 10 sided coloured dice ...in technicolor

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{	
	char rollAgain = 'y';
	
	srand(static_cast<unsigned int>(time(0)));  	// seed random number generator based on current time
	
	cout << endl << "     Generate a number    \n    Between 1 and 100     " << endl << endl;
	cout << "Note:\n If the red dice rolls \n a 10 this represents the \n value 0 in the 10s units" << endl << endl;
	
	do
	{
		int randomNumber1 = rand();					// select random number
		int randomNumber2 = rand();
	
		int redDice = (randomNumber1 % 10) + 1;		// value from 1 to 10
		int greenDice = (randomNumber2 % 10) + 1;
		
		if(redDice == 10) redDice = 0;				// if the red dice is a 10, value is 0
		int generatedNumber = (redDice * 10) + greenDice;
		
		cout << "The Red Dice Is: " << redDice << endl;		
		cout << "The Green Dice Is: " << greenDice << endl << endl;		
		cout << "Generated Number: " << generatedNumber << endl << endl;
		
		cout << "Roll Again? Y/N: ";
		cin >> rollAgain;		
		cout << endl;
		
	}while((rollAgain != 'n') && (rollAgain != 'N'));
	
    return 0;
}
