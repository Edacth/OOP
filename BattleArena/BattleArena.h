#pragma once

//Global variables


class unit
{

private:
	int health; //Health of unit
	int attack;	//Attack value of unit
	char type; 	//Unit type

public:
	
	void takeDamage(int dam);
	void initalize(int h, int a, char t);
	void dealDamage(unit& target);
	void attackFoe(unit* opposingTeam);
	int getHealth();
};

void printTeam(unit* team);