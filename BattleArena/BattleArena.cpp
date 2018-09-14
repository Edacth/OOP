#include <iostream>
#include "BattleArena.h"
#include <random>
#include <time.h>


void unit::takeDamage(int dam)
{
	health -= dam;
}

void unit::initalize(int h, int a, std::string t)
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
	srand(time(NULL));
	int rand = std::rand() % countAlive(opposingTeam, 3);
	std::cout << type << " attacks " << opposingTeam[rand].type << " for " << attack << std::endl;
	unit& target = opposingTeam[rand];
	dealDamage(target);
}

int unit::getHealth()
{
	return health;
}

bool unit::isAlive()
{
	if (health <= 0)
	{
		return false;
	}
	return true;
}

void printTeam(unit* team)
{
	int length = 3;
	for (int i = 0; i < length; i++)
	{
		std::cout << "-----------" << std::endl;
		std::cout << "Name " << team[i].type << std::endl;
		std::cout << "Health " << team[i].getHealth() << std::endl;
	}
	
}

int countAlive(unit * team, size_t arrSize)
{
	int count = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (team[i].isAlive())
		{
			count++;
		}
		//cout << i << " is " << (squadArr[i].isAlive() ? "alive" : "dead") << endl;
	}

	return count;
}

void sortArray(unit* arr, int length)
{


	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (arr[j].health > arr[j - 1].health)
			{
				unit temp;
				temp.health = arr[j].health;
				temp.attack = arr[j].attack;
				temp.type = arr[j].type;


				arr[j].health = arr[j - 1].health;
				arr[j].attack = arr[j - 1].attack;
				arr[j].type = arr[j - 1].type;


				arr[j - 1].health = temp.health;
				arr[j - 1].attack = temp.attack;
				arr[j - 1].type = temp.type;
			}
		}
	}
}