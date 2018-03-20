#pragma once

#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;


namespace Maze
{
	class Room;
	class Dungeon;
	class Player;
	class Item;


	class Room
	{
		string m_Name;

		Dungeon* m_Dungeon;

		Room* m_dir1;
		Room* m_dir2;
		Room* m_dir3;
		Room* m_dir4;
		Room* m_dir5;
		Room* m_dir6;
		Room* m_dir7;
		Room* m_dir8;

		
	public:
		Room(Dungeon* t_d);

		bool link(uint8_t t_dir, Room& t_room);

		Room& dir1(void) const;
		Room& dir2(void) const;
		Room& dir3(void) const;
		Room& dir4(void) const;
		Room& dir5(void) const;
		Room& dir6(void) const;
		Room& dir7(void) const;
		Room& dir8(void) const;

		void InitiateObj(void);
		void setName(string t_name);
		string getName(void);
		virtual Room* teleport(void);
	};

	class SpecialRoom : public Room
	{
		Room* m_RandomRoom;
	public:
		SpecialRoom(Dungeon* t_d, int t_MaxRooms);
		Room* teleport(void);
	};

	class Player
	{
		Room* m_Location;
		Dungeon* m_Dungeon;
	public:
		Player(Room* start = nullptr);
		void setDungeon(Dungeon* t_d);
		Room* getLocation(void);
		void setLocation(Room* t_Room);
		string move(char t_dir);
	};

	class Dungeon
	{
		int m_MaxRooms;
		vector<Room*> m_Rooms;
		Room* m_Finish;
		Player* m_CurrentPlayer;
		bool m_isComplete = false;
		bool m_Exit = false;
		bool m_StaticDungeon = true;
		bool m_TextDungeon = false;
		bool m_RandomDungeon = false;
	public:
		Dungeon(int t_maxRooms, Player* t_currentP);
		~Dungeon(void);
		vector<Room*> getRooms(void);
		bool isComplete(char t_input);
		string displayHelp(void);
		void ExitProgram(void);
		bool Exit(void);
		bool getStaticDungeon(void);
		bool getTextDungeon(void);
		bool getRandomDungeon(void);
		void setFinish(Room* t_finish);
		void setStaticDun(void);
		void setTextDun(void);
		void setRanDun(void);
		void setMaxRooms(int t_maxRooms);
		void addRoom(void);
		string displayMenu(char t_input);
	};
}