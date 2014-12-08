#include "GoldMine.h"
#include <iostream>

using namespace std;

int main()
{
	string choice; //Choice for Playing Again
	bool Win = false; //Whether or not the player has won
	do{
		system("clear");
				
		cout << "GAME START...Press Enter to Continue" << endl;;
		cin.ignore();
		
		GoldMine MyGame;
		
		//Setting Boxes
		MyGame.setMyBox('R');
		MyGame.setMyBox('G');
		MyGame.setMyBox('C');
	
		cout << "Game Startup Successful" << endl;
		cout << "Press Enter to Continue" << endl;
		cin.ignore();
	
		system("clear");
		Win = false;
		cout << "Welcome to GoldMine!" << endl;
		cout << "Hurry and find the pot of gold before the leprechaun steals all of your gold pieces!" << endl;
		int gold = MyGame.getGold();
		cout << "Current Gold: " << gold << endl << endl;
		string r;
		string c;
		MyGame.printGoldMine();
		do{
			cout << "Please enter row: ";
			cin >> r;
			if ((r != ".")&&(r.size() < 2)&&(r <= "5"))
			{
				cout << "Please enter column: ";
				cin >> c;
				if ((c != ".")&&(c.size() < 2)&&(c <= "5"))
				{
					//Convert string into int
					int row = atoi(r.c_str());
					int column = atoi(c.c_str());
					system("clear");
					Win = MyGame.revealSelection(row, column);
					MyGame.printGoldMine();
				}
				else
				{
					cout << "ERROR: Input either out of bounds or incorrect format" << endl;
				} 
			}
			else 
			{
				cout << "ERROR: Input either out of bounds or incorrect format" << endl;
			}
			
			gold = MyGame.getGold();
		}while ((!(gold <= 0))&&(Win!= true)); //While gold is not either negative or 0 and while the player has not won
		do{
			cout << "Play Again? Y/N: ";
			cin >> choice;
			if (((choice != "Y")&&(choice != "N"))&&((choice != "y")&&(choice != "n")))
			{	
				cout << "ERROR: Input in incorrect format" << endl;
			}
			}while(((choice!="N")&&(choice!="n"))&&((choice!="Y")&&(choice!="y")));

	}while	((choice != "N")&&(choice != "n"));

	return 0;

}

