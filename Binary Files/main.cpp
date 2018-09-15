#include <iostream>
#include "Binary Files.h"
#include <string>

int main()
{

	saveData player1 = { "Dave", 6, 3, false, 134.55f };
	//helloWorld();
	//vectorz();
	//saveGame(player1);
	//loadGame("playerData.dat");

	bool keepGoing = true;

	while (keepGoing)
	{
		bestiaryPrint(1);
		char input;
		std::cin >> input;
		switch (input)
		{
		case '1':
			bestiaryAdd();
			break;
		case '2':
			bestiaryRemove();
			break;
		case '3':
			bestiaryView();
			break;
		case '4':
			bestiaryList();
			break;
		case '5':
			std::cout << "Take care! DON'T DIE. :)" << std::endl;
			keepGoing = false;
			break;
		default:
			break;
		}
		std::cin.clear();
		std::cin.ignore(50, '\n');
	}
	
	
	return 0;
}