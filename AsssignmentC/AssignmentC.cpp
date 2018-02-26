// CAssingment.cpp : Defines the entry point for the console application.
//

#include "cstdlib"
#include "DungeonController.h"


int main()
{
	bool repeat = true;
	char response;
	
	//Repeat till they say no
	while (repeat)
	{
		DungeonController* Dungeon = new DungeonController();

		system("CLS");

		cout << "Do you wish to play again\n1) Yes\n2) No" << endl;
		cin >> response;

		if (response == '1')
		{
			repeat = true;
		}
		else
		{
			repeat = false;
		}

		delete(Dungeon);
		system("CLS");
	}

	return 0;
}

