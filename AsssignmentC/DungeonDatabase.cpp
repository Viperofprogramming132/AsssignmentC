#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>
#include <random>
#include "DungeonDatabase.h"

using namespace std;
using namespace Maze;

Room::Room(Dungeon* t_d) : m_Dungeon(t_d)
{
	//Set all the directions to NULL to start
	m_dir1 = nullptr;
	m_dir2 = nullptr;
	m_dir3 = nullptr;
	m_dir4 = nullptr;
	m_dir5 = nullptr;
	m_dir6 = nullptr;
	m_dir7 = nullptr;
	m_dir8 = nullptr;
	
}

void Room::InitiateObj()
{
	string line;

	//Open the file Room Names
	ifstream myfile("Room Names.txt");

	//Create random
	random_device rd;									
	mt19937 rng(rd());									
	uniform_int_distribution<int> roomNameGen(0, 99);

	//Create a random to use as the name
	int random = roomNameGen(rng);


	//Generate a random room name
	if (myfile.is_open())
	{
		int num = 0;
		while (getline(myfile, line))
		{
			if (num == random)
			{
				setName(line);
			}

			++num;
		}
		myfile.close();
	}
}

//Sets the room in the given direction
bool Room::link(uint8_t t_dir, Room& t_room)
{
	//Check if it is complete
	bool complete = false;

	switch (t_dir)
	{
		case 1:
			m_dir1 = &t_room;
			complete = true;
			break;
		case 2:
			m_dir2 = &t_room;
			complete = true;
			break;
		case 3:
			m_dir3 = &t_room;
			complete = true;
			break;
		case 4:
			m_dir4 = &t_room;
			complete = true;
			break;
		case 5:
			m_dir5 = &t_room;
			complete = true;
			break;
		case 6:
			m_dir6 = &t_room;
			complete = true;
			break;
		case 7:
			m_dir7 = &t_room;
			complete = true;
			break;
		case 8:
			m_dir8 = &t_room;
			complete = true;
			break;
	}

	return complete;
}


//The Following set of functions return the room in the requested direction
Room& Room::dir1(void) const
{
	return *m_dir1;
}
Room& Room::dir2(void) const
{
	return *m_dir2;
}
Room& Room::dir3(void) const
{
	return *m_dir3;
}
Room& Room::dir4(void) const
{
	return *m_dir4;
}
Room& Room::dir5(void) const
{
	return *m_dir5;
}
Room& Room::dir6(void) const
{
	return *m_dir6;
}
Room& Room::dir7(void) const
{
	return *m_dir7;
}
Room& Room::dir8(void) const
{
	return *m_dir8;
}

//Sets the name of the room
void Room::setName(string t_newName)
{
	m_Name = t_newName;
}

//Gets the name of the room
string Room::getName(void)
{
	return m_Name;
}

//Constructor for the player
Player::Player(Room* t_start) : m_Location(t_start)
{

}

//Gets the location of the player
Room* Player::getLocation()
{
	return m_Location;
}


//Moves the player to another room
string Player::move(char t_dir)
{
	string response = "";


	switch (t_dir)
	{
		case '1':
			//Checks if the direction does not have a room
			if (&m_Location->dir1() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir1());
			response = "You Went North to the " + m_Location->getName();
			break;
		case '2':
			//Checks if the direction does not have a room
			if (&m_Location->dir2() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir2());
			response = "You Went North East to the " + m_Location->getName();
			break;
		case '3':
			//Checks if the direction does not have a room
			if (&m_Location->dir3() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir3());
			response = "You Went East to the " + m_Location->getName();
			break;
		case '4':
			//Checks if the direction does not have a room
			if (&m_Location->dir4() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir4());
			response = "You Went South East to the " + m_Location->getName();
			break;
		case '5':
			//Checks if the direction does not have a room
			if (&m_Location->dir5() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir5());
			response = "You Went South to the " + m_Location->getName();
			break;
		case '6':
			//Checks if the direction does not have a room
			if (&m_Location->dir6() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir6());
			response = "You Went South West to the " + m_Location->getName();
			break;
		case '7':
			//Checks if the direction does not have a room
			if (&m_Location->dir7() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir7());
			response = "You Went West to the " + m_Location->getName();
			break;
		case '8':
			//Checks if the direction does not have a room
			if (&m_Location->dir8() == nullptr)
			{
				response = "There is nothing in that direction";
				break;
			}
			//Sets the players location to the new room and sets the response
			m_Location = &(m_Location->dir8());
			response = "You Went North West to the " + m_Location->getName();
			break;
		case 'Q':
		case 'q':
			//Sets the program to be exited
			m_Dungeon->ExitProgram();
			break;
		case 'H':
		case 'h':
			//Displays the help file
			cout << m_Dungeon->displayHelp() << endl;
			system("PAUSE");
			system("CLS");
			break;
		default:
			break;
	}

	return response;
}

//Sets the location of the player
void Player::setLocation(Room* t_room)
{
	m_Location = t_room;
}

//Sets the association with the player to the dungeon
void Player::setDungeon(Dungeon* t_d)
{
	m_Dungeon = t_d;
}

//Constructor for the dungeon taking the maximum rooms and the player that has been made
Dungeon::Dungeon(int t_maxRooms, Player* t_currentP) : m_MaxRooms(t_maxRooms), m_CurrentPlayer(t_currentP)
{
	m_Rooms.resize(m_MaxRooms);
	m_CurrentPlayer->setDungeon(this);
	addRoom();
}

//Destructor clearing the rooms and resizes it to 0 to clear memory
Dungeon::~Dungeon()
{
	m_Rooms.clear();
	m_Rooms.resize(1);
}

//Checks if the dungeon is complete
bool Dungeon::isComplete(char t_input)
{
	//Calls the move to allow the player to move
	if (m_Finish != m_CurrentPlayer->getLocation())
	{
		m_isComplete = false;
		system("CLS");
		cout << displayMenu(t_input) << endl;
		
	}
	//Checks if the end is reached
	if (m_Finish == m_CurrentPlayer->getLocation())
	{
		system("CLS");
		cout << "Congrats!\nYou found the end!\n";
		system("PAUSE");
		m_isComplete = true;
	}
	
	return m_isComplete;
}

//Writes out the menu showing what is in each direction
string Dungeon::displayMenu(char t_input)
{
	string output;
	string moveOut = m_CurrentPlayer->move(t_input);
	output.append("1: Head North \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir1() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir1().getName());
	}

	output.append("\n2: Head North East \t\t");
	if (&m_CurrentPlayer->getLocation()->dir2() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir2().getName());
	}

	output.append("\n3: Head East \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir3() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir3().getName());
	}

	output.append("\n4: Head South East \t\t");
	if (&m_CurrentPlayer->getLocation()->dir4() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir4().getName());
	}

	output.append("\n5: Head South \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir5() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir5().getName());
	}

	output.append("\n6: Head South West \t\t");
	if (&m_CurrentPlayer->getLocation()->dir6() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir6().getName());
	}

	output.append("\n7: Head West \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir7() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir7().getName());
	}

	output.append("\n8: Head North West \t\t");
	if (&m_CurrentPlayer->getLocation()->dir8() != nullptr)
	{
		output.append(m_CurrentPlayer->getLocation()->dir8().getName());
	}

	output.append("\nQ: Quit\nH: Help\n" + moveOut);

	return output;
}

//Gets the rooms
vector<Room*> Dungeon::getRooms(void)
{
	return m_Rooms;
}

//Sets the program to be exited
void Dungeon::ExitProgram(void)
{
	m_Exit = true;
}

//Gets exit
bool Dungeon::Exit(void)
{
	return m_Exit;
}

//Reads the help file
string Dungeon::displayHelp(void)
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

//The following functions gets the dungeon type
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

//Sets the exit to the given room
void Dungeon::setFinish(Room * t_finish)
{
	m_Finish = t_finish;
}

//The following set the dungeon type
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

//Sets the max rooms for the vector and generator the rooms 
void Dungeon::setMaxRooms(int t_maxRooms)
{
	m_MaxRooms = t_maxRooms;
	m_Rooms.resize(m_MaxRooms);
	addRoom();
}

//Creates a room
void Dungeon::addRoom()
{
	for (int i = 0; i < m_MaxRooms;++i)
	{
		m_Rooms[i] = new Room(this);
		m_Rooms[i]->InitiateObj();
	}
}
