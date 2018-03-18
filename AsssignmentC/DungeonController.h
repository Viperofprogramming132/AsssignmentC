#pragma once
#include "DungeonDatabase.h"

class DungeonController
{
	void StaticDungeon();
	void TextDungeon();
	void RandomDungeon(int maxRooms);
	void CreateLinks(const string values[9]);
public:
	DungeonController();
	~DungeonController();
};