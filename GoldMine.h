#include "Box.h"
#include "dynamicList.h"
#include <iostream>
#include <string>
using namespace std;

class GoldMine
{
	public:
		GoldMine();
		void randomRowColumn(int &row, int &column);
		void setMyBox(char c);
		void setRainbow();
		void setGold();
		void setCoal();
		string rainbowMessage();
		bool revealSelection(int row, int column);
		void printGoldMine();
		int getGold(){return gold;};
		friend class dynamicList<Box>;
		friend class Box;
	private:
		dynamicList<Box> gm[6]; //creates the array of boxes
		int gold; //holds the initial amount of gold 1000 - 9000
		int potofGold; //holds the pot of gold default amount 90000
};


