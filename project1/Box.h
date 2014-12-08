#include <iostream>
#include <cstdlib>
using namespace std;

class Box
{
	public:
		Box();
		bool getVisited() const;
		void setVisited(bool visited);
		int getGoldLost() const;
		void setGoldLost();
		char getCharacter() const;
		void setCharacter(char special);
		void printBox();
		friend bool operator== (Box left, Box right);
		friend class GoldMine;
	private:
		char character;
		int goldLost;
		bool selected;
};
