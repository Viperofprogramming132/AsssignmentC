#include "cstdlib"
#include "cstring"
#include "DungeonDatabase.h"
#include "iostream"
#include "cstdint"
#include <string>
#include "fstream"
#include <random>

using namespace std;

Room::Room(Dungeon* d) : m_Dungeon(d)
{
	//Set all the directions to NULL to start
	m_dir1 = NULL;
	m_dir2 = NULL;
	m_dir3 = NULL;
	m_dir4 = NULL;
	m_dir5 = NULL;
	m_dir6 = NULL;
	m_dir7 = NULL;
	m_dir8 = NULL;
	string line;

	//Open the file Room Names
	ifstream myfile("Room Names.txt");

	//Create random
	random_device rd;									// only used once to initialise (seed) engine
	mt19937 rng(rd());									// random-number engine used (Mersenne-Twister in this case)
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

			num++;
		}
		myfile.close();
	}
}

//Sets the room in the given direction
bool Room::link(uint8_t dir, Room& room)
{
	//Check if it is complete
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

//The Following set of functions return the room in the requested direction
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

//Sets the name of the room
void Room::setName(string newName)
{
	m_Name = newName;
}

//Gets the name of the room
string Room::getName(void)
{
	return m_Name;
}

//Constructor for the player
Player::Player(Room* start) : m_Location(start)
{

}

//Gets the location of the player
Room* Player::getLocation()
{
	return m_Location;
}


//Moves the player to another room
string Player::move(char dir)
{
	string response = "";


	switch (dir)
	{
		case '1':
			//Checks if the direction does not have a room
			if (&m_Location->dir1() == NULL)
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
			if (&m_Location->dir2() == NULL)
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
			if (&m_Location->dir3() == NULL)
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
			if (&m_Location->dir4() == NULL)
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
			if (&m_Location->dir5() == NULL)
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
			if (&m_Location->dir6() == NULL)
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
			if (&m_Location->dir7() == NULL)
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
			if (&m_Location->dir8() == NULL)
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
void Player::setLocation(Room* room)
{
	m_Location = room;
}

//Sets the association with the player to the dungeon
void Player::setDungeon(Dungeon* d)
{
	m_Dungeon = d;
}

//Constructor for the dungeon taking the maximum rooms and the player that has been made
Dungeon::Dungeon(int maxRooms, Player* currentP) : m_MaxRooms(maxRooms), m_CurrentPlayer(currentP)
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
bool Dungeon::isComplete(char input)
{
	//Calls the move to allow the player to move
	if (m_Finish != m_CurrentPlayer->getLocation())
	{
		m_isComplete = false;
		system("CLS");
		cout << displayMenu(input) << endl;
		
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
string Dungeon::displayMenu(char input)
{
	string output;
	string moveOut = m_CurrentPlayer->move(input);
	output.append("1: Head North \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir1() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir1().getName());
	}

	output.append("\n2: Head North East \t\t");
	if (&m_CurrentPlayer->getLocation()->dir2() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir2().getName());
	}

	output.append("\n3: Head East \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir3() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir3().getName());
	}

	output.append("\n4: Head South East \t\t");
	if (&m_CurrentPlayer->getLocation()->dir4() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir4().getName());
	}

	output.append("\n5: Head South \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir5() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir5().getName());
	}

	output.append("\n6: Head South West \t\t");
	if (&m_CurrentPlayer->getLocation()->dir6() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir6().getName());
	}

	output.append("\n7: Head West \t\t\t");
	if (&m_CurrentPlayer->getLocation()->dir7() != NULL)
	{
		output.append(m_CurrentPlayer->getLocation()->dir7().getName());
	}

	output.append("\n8: Head North West \t\t");
	if (&m_CurrentPlayer->getLocation()->dir8() != NULL)
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
void Dungeon::setFinish(Room * finish)
{
	m_Finish = finish;
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
void Dungeon::setMaxRooms(int maxRooms)
{
	m_MaxRooms = maxRooms;
	m_Rooms.resize(m_MaxRooms);
	addRoom();
}

//Creates a room
void Dungeon::addRoom()
{
	for (int i = 0; i < m_MaxRooms;i++)
	{
		m_Rooms[i] = new Room(this);
	}
}
