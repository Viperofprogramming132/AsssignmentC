#pragma once
#include "DungeonDatabase.h"

namespace Controllers
{
	class DungeonController
	{
		Maze::Player* m_player;
		Maze::Dungeon* m_Dungeon;
		void StaticDungeon(void);
		void TextDungeon(void);
		void RandomDungeon(int t_maxRooms);
		void CreateLinks(const string t_values[9]);
	public:
		DungeonController(void);
		void Run(void);
		~DungeonController(void);
	};
}
