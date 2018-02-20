#include "DungeonController.h"
#include "iostream"
#include <string>

Player* player = new Player();
Dungeon* dungeon = new Dungeon(10, player);

using namespace std;



DungeonController::DungeonController()
{
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
		RandomDungeon();
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

void DungeonController::RandomDungeon()
{

}
