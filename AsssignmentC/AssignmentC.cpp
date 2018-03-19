// CAssingment.cpp : Defines the entry point for the console application.
//

#include "cstdlib"
#include "DungeonController.h"

//Thanks to https://gist.github.com/lefticus/10191322 for the code standards

int main()
{
	Controllers::DungeonController* Dungeon = new Controllers::DungeonController();
	Dungeon->Run();

	return 0;
}

