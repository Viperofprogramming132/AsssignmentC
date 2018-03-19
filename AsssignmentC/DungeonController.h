#pragma once
#include "DungeonDatabase.h"

class DungeonController
{
	Player* m_player;
	Dungeon* m_dungeon;
	void StaticDungeon(void);
	void TextDungeon(void);
	void RandomDungeon(int t_maxRooms);
	void CreateLinks(const string t_values[9]);
public:
	DungeonController(void);
	void Run(void);
	~DungeonController(void);
};