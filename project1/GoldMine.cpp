#include "GoldMine.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>
using namespace std;


GoldMine::GoldMine()
{
	Box temp;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			//Insert Boxes in array
			gm[i].InsertAt(temp, j);
		}
	}

	//Random Number Generator
	const int UPPER_LIMIT = 9000;
	const int LOWER_LIMIT = 1000;

	srand(time(0));
	cout << "Initializing Starting Gold...Press Enter to Continue";
	cin.ignore();
	gold = ( rand() % UPPER_LIMIT) + LOWER_LIMIT;
	potofGold = UPPER_LIMIT;
	cout << "SUCCESS" << endl;
	
}

void GoldMine::randomRowColumn(int &row, int &column)
{
	const int UPPER_LIMIT = 5;
	const int LOWER_LIMIT = 0;
	
	srand(time(0));
	//Allow time to pass so that random number generator 
	//does not produce two same numbers
	cout << "Generating Random Row....Press Enter to Continue";
	cin.ignore();
	
	row = (rand() % UPPER_LIMIT)+ LOWER_LIMIT;
	cout << "Generating Random Column....Press Enter to Continue";
	cin.ignore();
	column = (rand() % UPPER_LIMIT) + LOWER_LIMIT; 	
}

void GoldMine::setMyBox(char c)
{
	
	if (c == 'N')
	{
		//do nothing, Box is already set to N
	}
	else if (c == 'R')
	{
		setRainbow();
	}
	else if (c == 'G')
	{
		setGold();
	}
	else if (c == 'C')
	{
		setCoal();
	}

}

void GoldMine::setRainbow()
{
	int row = 0;
	int column = 0;
	cout << "Initializing Rainbow" << endl;
	randomRowColumn(row, column);
	cout << "SUCCESS" << endl;
	Box Rainbow;
	Rainbow = gm[row].getItem(column);
	Rainbow.setCharacter('R');
	gm[row].InsertAt(Rainbow, column);
	//Rainbow Cheat!
	cout << "Rainbow = Row: " << row << " Column: " << column <<endl;	
}

void GoldMine::setGold()
{
	int row = 0;
	int column = 0;
	cout << "Initializing Gold" << endl;
	randomRowColumn(row, column);
	if (gm[row].getItem(column).getCharacter() == 'R')
	{
		//Prevents box from overlapping because of identical coordinates
		cout << "Reinitializing...Press Enter to Continue";
		cin.ignore();
		randomRowColumn(row, column);

	}
	else
	{
		cout << "SUCCESS" << endl;
	}
	Box Gold;
	Gold = gm[row].getItem(column);
	Gold.setCharacter('G');
	gm[row].InsertAt(Gold, column);
	//Gold Cheat!
	cout << "Gold = Row: " << row << " Column: " << column << endl;
	
}

void GoldMine::setCoal()
{
	int row = 0;
	int column = 0;
	cout << "Initializing Coal" << endl;
	randomRowColumn(row, column);
	if ((gm[row].getItem(column).getCharacter() == 'R')||(gm[row].getItem(column).getCharacter() == 'G'))
	{
		//Prevents box from overlapping because of identical coordinates
		cout << "Reinitializing...Press Enter to Continue";
		cin.ignore();
		randomRowColumn(row, column);
	}
	else
	{
		cout << "SUCCESS" << endl;
	}
	Box Coal;
	Coal = gm[row].getItem(column);
	Coal.setCharacter('C');
	gm[row].InsertAt(Coal, column);
	//Coal Cheat!
	cout << "Coal = Row: " << row << " Column: " << column << endl;
	
}

string GoldMine::rainbowMessage()
{
	int row;
	int column;
	Box find;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			//Find where Gold is
			find = gm[i].getItem(j);
			if (find.character == 'G')
			{
				row = i;
				column = j;
				break;
			}
		}
	}
		
	if ((row <= 2)&&(column <=2))
	{
		return  "Gold is located in the upper left!";
	}
	else if (((row >= 3)&&(column <=2)))
	{
		return  "Gold is located in the lower left!";
	}
	else if ((row <=2)&&((column >= 3)&&(column <=5)))
	{
		return "Gold is located in the upper right!";
	}
	else if ((row >=3)&&((column >= 3)&&(column <=5)))
	{
		return "Gold is located in the lower right!";
	} 
	else
	{
		return "Error";
	}
	
			

}

bool GoldMine::revealSelection(int row, int column)
{
	Box print1;
	//Get box at specific location
	print1 = gm[row].getItem(column);
	
	if (print1.getVisited() == true)
	{
		cout << "You already looked here!" << endl;
		return false;
		printGoldMine();
	}
	else
	{
		print1.setGoldLost();	
		int gl = print1.getGoldLost();
		if (print1.getCharacter() == 'N')
		{
			cout << "Nothing here." << endl;
			cout << "The leprechuan stole " << gl << " gold pieces from you!" << endl;
			gold = (gold - gl);
			potofGold = potofGold - gl;
			cout << "Current Gold: " << gold << endl;
			print1.setVisited(true);
			//Update box data and insert back into array
			gm[row].InsertAt(print1, column);
			return false;
		}
	
		else if (print1.getCharacter() == 'R')
		{
			cout << "You found the rainbow!" << endl;
			cout << rainbowMessage() << endl;
			print1.setVisited(true);
			//Update box data and insert back into array
			gm[row].InsertAt(print1, column);
			cout << "Current Gold: " << gold << endl << endl;
			return false;
		}
		else if (print1.getCharacter() == 'C')
		{
			cout << "You found coal..." << endl;
			cout << "The leprechaun knocked you out with the ooal and stole all your gold!" << endl;
			cout << "You Lose!" << endl;
			gold = 0;
			print1.setVisited(true);
			//Update box data and insert back into array
			gm[row].InsertAt(print1, column);
			cout << "Current Gold: " << gold << endl << endl;
			return true;
		}
		else if (print1.getCharacter() == 'G')
		{
			cout << "You found the pot of gold! Congrats! You win!" << endl;
			gold = gold + potofGold;
			print1.setVisited(true);
			gm[row].InsertAt(print1, column);
			cout << "Pot of Gold: " << potofGold << endl;
			cout << "Current Gold: " << gold << endl << endl;
			return true;
		}
	}
		
		 
			

}

void GoldMine::printGoldMine()
{
	int row;
	int column;
	Box find;
	//Create Grid!
	char grid[6][6];
	//Prints column label
	cout << "   0  1  2  3  4  5" << endl;
	for (int i = 0; i < 6; i++)
	{
		//Prints row label
		cout << i;
		cout << "  ";
		for (int j = 0; j < 6; j++)
		{
			//Get the box at specific row and column
			//Get Character at each box and set grid with appropriate symbol
			find = gm[i].getItem(j);
			if (find.getVisited() == true)
			{
				if(find.getCharacter() == 'N')
				{
					grid[i][j] = '-';
				}
				else if (find.getCharacter() == 'R')
				{
					grid[i][j] = 'R';
				}
				else if (find.getCharacter() == 'G')
				{
					grid[i][j] = 'G';
				}
				else if (find.getCharacter() == 'C')
				{
					grid[i][j] = 'C';
				}
			}
			else
			{	
				//Default *
				grid[i][j] = '*';
			}
			cout << grid[i][j];
			cout << "  ";
		}
		cout << endl;
	}
	
}

