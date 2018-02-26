#pragma once
#include "DungeonDatabase.h"

class DungeonController
{
	void StaticDungeon();
	void TextDungeon();
	void RandomDungeon(int maxRooms);
	void CreateLinks(string values[9]);
public:
	DungeonController();
	~DungeonController();
};