#include <iostream>
#include "BattleArena.h"
#include <windows.h>



int main()
{
	int team1Living;
	int team2Living;
	int teamSize = 3;
	int turnCount = 0;

	unit team1[3];
	team1[0].initalize(100, 20, "Goblin1");
	team1[1].initalize(200, 20, "Goblin2");
	team1[2].initalize(20, 20, "Goblin3");

	unit team2[3];
	team2[0].initalize(100, 20, "Human1");
	team2[1].initalize(100, 20, "Human2");
	team2[2].initalize(100, 20, "Human3");
	//sortArray(team1, teamSize);
	//sortArray(team2, teamSize);
	
	
	while ( (countAlive(team1, teamSize) >= 1) &&  (countAlive(team2, teamSize) >= 1))
	{
		turnCount++;
		std::cout << "     -=== TURN: " << turnCount << " ===-" << std::endl;

		//Have team1 attack
		for (int i = 0; i < teamSize; i++)
		{
			if (team1[i].isAlive())
			{
				team1[i].attackFoe(team2);
				sortArray(team2, teamSize);
			}
			
		}

		//Have team2 attack
		for (int i = 0; i < teamSize; i++)
		{
			if (team2[i].isAlive())
			{
				team2[i].attackFoe(team1);
				sortArray(team1, teamSize);
			}
			
		}
		

		printTeam(team1);
		printTeam(team2);
		system("pause");
	}
	
		std::cout << "The battle is over. ";
	if (countAlive(team1, teamSize) >= 1)
	{
		std::cout << "The goblins are victorous" << std::endl;
	}
	else
	{
		std::cout << "The humans are victorous" << std::endl;
	}

	return 0;
}



/*
void sortArray(int* arr)
{


	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
*/