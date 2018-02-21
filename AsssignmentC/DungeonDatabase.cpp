#include "cstdlib"
#include "cstring"
#include "DungeonDatabase.h"
#include "iostream"
#include "cstdint"
#include <string>
#include "fstream"

using namespace std;

Room::Room(Dungeon* d) : m_Dungeon(d)
{
	m_dir1 = NULL;
	m_dir2 = NULL;
	m_dir3 = NULL;
	m_dir4 = NULL;
	m_dir5 = NULL;
	m_dir6 = NULL;
	m_dir7 = NULL;
	m_dir8 = NULL;
	string line;

	ifstream myfile("Room Names.txt");

	int random = rand() % 100;
	if (myfile.is_open())
	{
		int num = 0;
		while (getline(myfile, line))
		{
			if (num == random)
			{
				setName(line);
			}

			num++;
		}
		myfile.close();
	}
}

bool Room::link(uint8_t dir, Room& room)
{
	bool complete = false;

	switch (dir)
	{
	case 1:
		m_dir1 = &room;
		complete = true;
		break;
	case 2:
		m_dir2 = &room;
		complete = true;
		break;
	case 3:
		m_dir3 = &room;
		complete = true;
		break;
	case 4:
		m_dir4 = &room;
		complete = true;
		break;
	case 5:
		m_dir5 = &room;
		complete = true;
		break;
	case 6:
		m_dir6 = &room;
		complete = true;
		break;
	case 7:
		m_dir7 = &room;
		complete = true;
		break;
	case 8:
		m_dir8 = &room;
		complete = true;
		break;
	}

	return complete;
}

Room& Room::dir1(void)
{
	return *m_dir1;
}
Room& Room::dir2(void)
{
	return *m_dir2;
}
Room& Room::dir3(void)
{
	return *m_dir3;
}
Room& Room::dir4(void)
{
	return *m_dir4;
}
Room& Room::dir5(void)
{
	return *m_dir5;
}
Room& Room::dir6(void)
{
	return *m_dir6;
}
Room& Room::dir7(void)
{
	return *m_dir7;
}
Room& Room::dir8(void)
{
	return *m_dir8;
}

void Room::setName(string newName)
{
	m_Name = newName;
}

string Room::getName(void)
{
	return m_Name;
}

Player::Player(Room* start) : m_Location(start)
{

}

Room* Player::getLocation()
{
	return m_Location;
}

string Player::move(char dir)
{
	string response = "";


	switch (dir)
	{
	case '1':
		if (&m_Location->dir1() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir1());
		response = "You Went North to the " + m_Location->getName();
		break;
	case '2':
		if (&m_Location->dir2() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir2());
		response = "You Went North East to the " + m_Location->getName();
		break;
	case '3':
		if (&m_Location->dir3() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir3());
		response = "You Went East to the " + m_Location->getName();
		break;
	case '4':
		if (&m_Location->dir4() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir4());
		response = "You Went South East to the " + m_Location->getName();
		break;
	case '5':
		if (&m_Location->dir5() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir5());
		response = "You Went South to the " + m_Location->getName();
		break;
	case '6':
		if (&m_Location->dir6() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir6());
		response = "You Went South West to the " + m_Location->getName();
		break;
	case '7':
		if (&m_Location->dir7() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir7());
		response = "You Went West to the " + m_Location->getName();
		break;
	case '8':
		if (&m_Location->dir8() == NULL)
		{
			response = "There is nothing in that direction";
			break;
		}
		m_Location = &(m_Location->dir8());
		response = "You Went North West to the " + m_Location->getName();
		break;
	case 'Q':
	case 'q':
		m_Dungeon->ExitProgram();
		break;
	case 'H':
	case 'h':
		cout << m_Dungeon->displayHelp() << endl;
		system("PAUSE");
		system("CLS");
		break;
	default:
		break;
	}

	return response;
}

void Player::setLocation(Room* room)
{
	m_Location = room;
}

void Player::setDungeon(Dungeon* d)
{
	m_Dungeon = d;
}

Dungeon::Dungeon(int maxRooms, Player* currentP) : m_MaxRooms(maxRooms), m_CurrentPlayer(currentP)
{
	m_Rooms.resize(m_MaxRooms);
	m_CurrentPlayer->setDungeon(this);
	addRoom();
}

bool Dungeon::isComplete(char input)
{
	
	if (m_Finish != m_CurrentPlayer->getLocation())
	{
		m_isComplete = false;
		system("CLS");
		cout << "1: Head North\n2: Head North East\n3: Head East\n4: Head South East\n5: Head South\n6: Head South West\n7: Head West\n8: Head North West\nQ: Quit\nH: Help\n" << m_CurrentPlayer->move(input) << endl;
	}
	if (m_Finish == m_CurrentPlayer->getLocation())
	{
		system("CLS");
		cout << "Congrats!\nYou found the end!";
		system("PAUSE");
		m_isComplete = true;
	}
	
	return m_isComplete;
}

vector<Room*> Dungeon::getRooms(void)
{
	return m_Rooms;
}

void Dungeon::ExitProgram(void)
{
	m_Exit = true;
}

bool Dungeon::Exit(void)
{
	return m_Exit;
}

string Dungeon::displayHelp(void)
{
	return ReadFile("Help.txt");
}

string Dungeon::ReadFile(string path)
{
	string line;
	string value;
	ifstream myfile("Help.txt");
	if (myfile.is_open())
	{

		while (getline(myfile, line))
		{
			value.append(line + "\n");
		}
		myfile.close();
	}
	return value;
}

bool Dungeon::getStaticDungeon()
{
	return m_StaticDungeon;
}

bool Dungeon::getTextDungeon()
{
	return m_TextDungeon;
}

bool Dungeon::getRandomDungeon()
{
	return m_RandomDungeon;
}

void Dungeon::setFinish(Room * finish)
{
	m_Finish = finish;
}

void Dungeon::setStaticDun()
{
	m_StaticDungeon = true;
	m_TextDungeon = false;
	m_RandomDungeon = false;
}

void Dungeon::setTextDun()
{
	m_StaticDungeon = false;
	m_TextDungeon = true;
	m_RandomDungeon = false;
}

void Dungeon::setRanDun()
{
	m_StaticDungeon = false;
	m_TextDungeon = false;
	m_RandomDungeon = true;
}

void Dungeon::setMaxRooms(int maxRooms)
{
	m_MaxRooms = maxRooms;
	m_Rooms.resize(m_MaxRooms);
	addRoom();
}

void Dungeon::addRoom()
{
	for (int i = 0; i < m_MaxRooms;i++)
	{
		m_Rooms[i] = new Room(this);
	}
}
