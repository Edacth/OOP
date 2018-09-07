#include <iostream>
#include "BattleArena.h"

void unit::takeDamage(int dam)
{
	health -= dam;
}

void unit::initalize(int h, int a, char t)
{
	health = h;
	attack = a;
	type = t;
}

void unit::dealDamage(unit& target)
{
	target.takeDamage(attack);
}

void unit::attackFoe(unit* opposingTeam)
{
	unit& target = opposingTeam[0];
	dealDamage(target);
}

int unit::getHealth()
{
	return health;
}

void printTeam(unit* team)
{
	int length = 3;
	for (int i = 0; i < length; i++)
	{
		std::cout << "-----------" << std::endl;
		std::cout << "Health " << team[i].getHealth() << std::endl;
	}
	
}