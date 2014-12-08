#include "Box.h"

bool operator== (Box left, Box right)
{
	if (left.character == right.character)
		return true;
	else
		return false;
}
Box::Box()
{
	//Set Default Values
	character = 'N';
	goldLost = 0;
	selected = false;
	
}

void Box::printBox()
{
	//For Checking and Debugging Purposes
	cout << character << endl;
	cout << goldLost << endl;
}

bool Box::getVisited() const
{
	return selected;
}

void Box::setVisited(bool visited)
{
	if (visited == true)
	{
		selected = true;
	}
	else if (visited == false)
	{
		selected = false;
	}

}

int Box::getGoldLost() const
{
	return goldLost;
}

void Box::setGoldLost()
{
	//Random Number Generator
	const int UPPER_LIMIT = 100;
	const int LOWER_LIMIT = 10;
	
	srand(time(0));
	
	//goldLost is generated randomly
	goldLost = (rand() % UPPER_LIMIT) + LOWER_LIMIT;

}

char Box::getCharacter() const
{
	return character;

}

void Box::setCharacter(char special)
{
	if (special == 'C')
	{
		character = 'C';
	}
	else if (special == 'G')
	{
		character = 'G';
	}
	else if (special == 'R')
	{
		character = 'R';
	}

}



