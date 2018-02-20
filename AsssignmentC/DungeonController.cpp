#include "DungeonController.h"
#include "iostream"
#include <string>

Player* player = new Player();
Dungeon* dungeon = new Dungeon(10, player);

using namespace std;

DungeonController::DungeonController()
{
	player->setLocation(dungeon->getRooms()[0]);
	while (!dungeon->isComplete() && !dungeon->Exit())
	{

	}
}