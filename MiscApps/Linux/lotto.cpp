#include <iostream>
#include <cstdlib>
#include <ctime>

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

int main()
{
	char retry = 'y';
	srand(static_cast<unsigned int>(time(0)));	// seed random number generator based on current time
	
	cout << endl << "        NATIONAL LOTTERY        " << endl;
	cout << "      Lotto Number Picker!" << endl;
		
	do
	{
	
		// Pick 1st number (don't need to check first number generated for uniqueness)
		int firstNumber = getNewNumber();
		numbersArray[0] = firstNumber;	
		
		cout << endl << "Number 1: " << firstNumber;	// Track random numbers
		
		getRandomNumber();
		sortArray();
		outputNumbers();
	
		cout << "Try Again? Y/N: ";
		cin >> retry;	
		cout << endl;		
	}while((retry != 'n') && (retry != 'N'));
		
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
	cout << endl << "Number " << pos + 1 << ": " << number;
	
	for (int i = 0; i < pos; ++i)
	{
		if(numbersArray[i] != number)
			numbersArray[pos] = number;	
		else
		{
			cout << "\tNOT UNIQUE!";
			int newUnique = getNewNumber();
			checkUnique(pos);
		}
	}
}

// Pick A Random Number
int getNewNumber()
{
	randomNumber = rand();			    // generate random number			
	number = (randomNumber % 47) + 1;	// get a number between 1 and 47
	
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
	cout << endl << endl << "The Lotto numbers selected are: ";
	for (int i = 0; i < 6; ++i)
	{
		cout << numbersArray[i];
		if (i < 5) cout << ", ";
	}
	cout << endl << endl;
}
