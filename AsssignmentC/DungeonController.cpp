#include "DungeonController.h"
#include "iostream"
#include <string>
#include "fstream"
#include <random>

//Create the player and the dungeon
Player* player = new Player();
Dungeon* dungeon = new Dungeon(10, player);

using namespace std;



DungeonController::DungeonController()
{
	//Used to check if the input is good
	bool good = false;
	int response;
	
	while (!good)
	{
		cout << "Please Select a way to run the dungeon:\n1: Hard Coded\n2: Text File\n3: Random" << endl;
		cin >> response;

		
		switch (response)
		{
			case 1:
				dungeon->setStaticDun();
				good = true;
				break;
			case 2:
				dungeon->setTextDun();
				good = true;
				break;
			case 3:
				cout << "How many rooms do you want in the dungeon or -1 for random: ";
				cin >> response;
				system("CLS");
				dungeon->setRanDun();
				good = true;
				break;
			default:
				cout << "Please Only enter 1, 2 or 3" << endl;
				system("pause");
				system("CLS");
				break;
		}

		//Clears the input as you need to when working with ints
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}

	
	//Sets the dungeon to the selected type
	if (dungeon->getStaticDungeon())
	{
		StaticDungeon();
	}
	else if (dungeon->getTextDungeon())
	{
		TextDungeon();
	}
	else if (dungeon->getRandomDungeon())
	{
		RandomDungeon(response);
	}


	char input = 'y';

	player->setLocation(dungeon->getRooms()[0]);

	//Loop till close or done
	while (!dungeon->isComplete(input) && !dungeon->Exit())
	{
		cin >> input;
	}
}

//Destructor to delete the player and dungeon
DungeonController::~DungeonController()
{
	delete(player);
	delete(dungeon);
}


void DungeonController::StaticDungeon()
{
	dungeon->setMaxRooms(10);
	vector<Room*> rooms = dungeon->getRooms();

	//Links the rooms for the static system

	//Room 1
	rooms[0]->link(1, *rooms[1]);
	rooms[1]->link(5, *rooms[0]);

	//Room 2
	rooms[1]->link(2, *rooms[2]);
	rooms[2]->link(6, *rooms[1]);

	//Room 3
	rooms[1]->link(3, *rooms[3]);
	rooms[3]->link(7, *rooms[1]);

	//Room 4
	rooms[1]->link(4, *rooms[4]);
	rooms[4]->link(8, *rooms[1]);

	//Room 5
	rooms[1]->link(1, *rooms[5]);
	rooms[5]->link(5, *rooms[1]);

	//Room 6
	rooms[5]->link(1, *rooms[6]);
	rooms[6]->link(5, *rooms[5]);

	//Room 7
	rooms[6]->link(2, *rooms[7]);
	rooms[7]->link(6, *rooms[6]);

	//Room 8
	rooms[7]->link(3, *rooms[8]);
	rooms[8]->link(7, *rooms[7]);

	//Room 9
	rooms[8]->link(4, *rooms[9]);
	rooms[9]->link(8, *rooms[8]);


	dungeon->setFinish(rooms[9]);
}

void DungeonController::TextDungeon()
{
	//Create a stream to the dungeon text file
	ifstream myfile("Dungeon.txt");

	string line;
	string value[9];

	//Set the seperator for the text file
	string delimiter = ",";

	int num = 0;

	//Open to count the amount of lines it has
	myfile.open("Dungeon.txt");
	dungeon->setMaxRooms((int) count(istreambuf_iterator<char>(myfile), istreambuf_iterator<char>(), '\n') + 1);
	myfile.close();

	try
	{
		//Reopen the file
		myfile.open("Dungeon.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				//Split the string into the numbers split by the delimiter
				num = 0;
				size_t pos = 0;
				string token;
				while ((pos = line.find(delimiter)) != string::npos) {
					token = line.substr(0, pos);
					value[num] = token;
					line.erase(0, pos + delimiter.length());
					num++;
				}

				//Creates the links in the rooms
				CreateLinks(value);
			}
			//Closes the files
			myfile.close();
		}
	}
	catch(exception e)
	{
		system("CLS");
		cout << "Error occured: Failed to load file (Incorrect Format?) Exiting Program" << endl;
		dungeon->ExitProgram();
		system("pause");
	}
	//Sets the finish to the last room
	dungeon->setFinish(dungeon->getRooms().back());
}

void DungeonController::RandomDungeon(int maxRooms)
{
	int rooms;
	int roomNum;

	random_device rd;									// only used once to initialise (seed) engine
	mt19937 rng(rd());									// random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> maxRoomsGen(10, 100);
	uniform_int_distribution<int> connectionGen(1, 4);
	

	//Check if needs random rooms
	if (maxRooms == -1)
	{
		maxRooms = maxRoomsGen(rng);
	}
	uniform_int_distribution<int> roomConGen(1, maxRooms);

	try
	{


		//Sets the max Rooms for the vector
		dungeon->setMaxRooms(maxRooms);
		vector<Room*> allRooms = dungeon->getRooms();

		//For each Room generate how many connections it has
		for (int i = 0; i < maxRooms;i++)
		{
			rooms = connectionGen(rng);

			//Stop it getting stuck in a loop
			if (i < maxRooms - 1)
			{
				//For each link, link a room to another
				for (int j = 0; j < rooms;j++)
				{

					//Random for room num
					roomNum = roomConGen(rng);
					--roomNum;


					//Make sure it is not the same room or one below making sure it always heads forward
					if (i != roomNum && roomNum > i)
					{
						//Link the room and the return
						allRooms[i]->link(j + 1, *allRooms[roomNum]);
						allRooms[roomNum]->link(j + 5, *allRooms[i]);
					}
					else
					{
						j--;
					}
				}
			}
		}

		//Set the last room as the finish
		dungeon->setFinish(allRooms.back());
	}
	catch (exception e)
	{
		system("CLS");
		cout << "Error occured: Failed to create random dungeon (Unknown Reason Cant recreate) Exiting Program" << endl;
		dungeon->ExitProgram();
		system("pause");
	}
}

void DungeonController::CreateLinks(string values[9])
{
	int roomNum = stoi(values[0]);
	vector<Room*> rooms = dungeon->getRooms();

	//For each room create the link read from file
	for (int i = 1; i < 9; i++)
	{
		//Check if there is no link
		if (values[i] != "-")
		{
			//Create link
			rooms[roomNum - 1]->link(i, *rooms[stoi(values[i])-1]);
		}
	}
}
