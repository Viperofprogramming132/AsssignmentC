#include "DungeonController.h"
#include "iostream"
#include <string>
#include <ctime>

Player* player = new Player();
Dungeon* dungeon = new Dungeon(10, player);

using namespace std;



DungeonController::DungeonController()
{
	bool good = false;
	int response;
	
	while (!good)
	{
		cout << "Please Select a way to run the dungeon:\n1: Hard Coded\n2: Text File\n3: Random" << endl;
		cin >> response;

		
		switch (response)
		{
		case 1:
			dungeon->setStaticDun();
			good = true;
			break;
		case 2:
			dungeon->setTextDun();
			good = true;
			break;
		case 3:
			//throw new exception("Currently Not Implemented");
			cout << "How many rooms do you want in the dungeon or -1 for random: ";
			cin >> response;
			system("CLS");
			dungeon->setRanDun();
			good = true;
			break;
		default:
			cout << "Please Only enter 1, 2 or 3" << endl;
			system("pause");
			system("CLS");
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (dungeon->getStaticDungeon())
	{
		StaticDungeon();
	}
	else if (dungeon->getTextDungeon())
	{
		TextDungeon();
	}
	else if (dungeon->getRandomDungeon())
	{
		RandomDungeon(response);
	}
	char input = 'y';
	player->setLocation(dungeon->getRooms()[0]);
	while (!dungeon->isComplete(input) && !dungeon->Exit())
	{
		cin >> input;
	}
}


void DungeonController::StaticDungeon()
{
	vector<Room*> rooms = dungeon->getRooms();

	rooms[0]->link(1, *rooms[1]);
	rooms[1]->link(5, *rooms[0]);

	rooms[1]->link(2, *rooms[2]);
	rooms[2]->link(6, *rooms[1]);

	rooms[1]->link(3, *rooms[3]);
	rooms[3]->link(7, *rooms[1]);

	rooms[1]->link(4, *rooms[4]);
	rooms[4]->link(8, *rooms[1]);

	rooms[1]->link(1, *rooms[5]);
	rooms[5]->link(5, *rooms[1]);

	rooms[5]->link(1, *rooms[6]);
	rooms[6]->link(5, *rooms[5]);

	rooms[6]->link(2, *rooms[7]);
	rooms[7]->link(6, *rooms[6]);

	rooms[7]->link(3, *rooms[8]);
	rooms[8]->link(7, *rooms[7]);

	rooms[8]->link(4, *rooms[9]);
	rooms[9]->link(8, *rooms[8]);


	dungeon->setFinish(rooms[9]);
}

void DungeonController::TextDungeon()
{

}

void DungeonController::RandomDungeon(int maxRooms)
{
	srand(time(0));
	if (maxRooms == -1)
	{
		maxRooms = rand() % 50;
	}
	dungeon->setMaxRooms(maxRooms);
}
