#pragma once

#include "cstdlib"
#include "cstring"
#include "cstdint"
#include "iostream"
#include <vector>

using namespace std;
class Room;
class Dungeon;
class Player;

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
	Room(Dungeon* d);

	bool viewed;

	bool link(uint8_t dir, Room& room);

	Room& dir1(void);
	Room& dir2(void);
	Room& dir3(void);
	Room& dir4(void);
	Room& dir5(void);
	Room& dir6(void);
	Room& dir7(void);
	Room& dir8(void);

	void setName(string name);
	string getName();
};

class Player
{
	Room* m_Location;
	Dungeon* m_Dungeon;
public:
	Player(Room* start = NULL);
	void setDungeon(Dungeon* d);
	Room* getLocation();
	void setLocation(Room*);
	string move(char dir);
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
	Dungeon(int maxRooms, Player* currentP);
	~Dungeon();
	vector<Room*> getRooms(void);
	bool isComplete(char input);
	string displayHelp(void);
	void ExitProgram(void);
	bool Exit(void);
	string ReadFile(string path);
	bool getStaticDungeon();
	bool getTextDungeon();
	bool getRandomDungeon();
	void setFinish(Room* finish);
	void setStaticDun();
	void setTextDun();
	void setRanDun();
	void setMaxRooms(int maxRooms);
	void addRoom();
	string displayMenu(char input);
};