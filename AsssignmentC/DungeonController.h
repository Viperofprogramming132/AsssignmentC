#pragma once
#include "DungeonDatabase.h"

class DungeonController
{
	void StaticDungeon();
	void TextDungeon();
	void RandomDungeon(int maxRooms);
public:
	DungeonController();
};