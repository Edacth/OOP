#include <iostream>
#include "BattleArena.h"



int main()
{
	unit team1[3];
	team1[0].initalize(100, 20, 'g');
	team1[1].initalize(100, 20, 'g');
	team1[2].initalize(100, 20, 'g');

	unit team2[3];
	team2[0].initalize(100, 20, 'h');
	team2[1].initalize(100, 20, 'h');
	team2[2].initalize(100, 20, 'h');

	team1[0].attackFoe(team2);
	printTeam(team1);
	printTeam(team2);

	return 0;
}