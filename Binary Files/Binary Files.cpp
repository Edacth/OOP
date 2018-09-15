#include <iostream>
#include "Binary Files.h"
#include <string.h>
#include <fstream>

void helloWorld()
{
	std::string str1 = "Hello world";
	int arraySize = str1.length();

	std::fstream fout("hello.dat", std::ios::out | std::ios::binary);
	if (!fout.good())
	{
		return;
	}
		for (int i = 0; i < arraySize; i++)
		{
			fout.write((char*)&str1[i], sizeof(char));
		}
		fout.flush();
		fout.close();
	
	
}

struct Vector3{
	float x, y, z;
};

void vectorz() {
	Vector3 myVecArray[] = { { 0, 1, 2 },{ 1, 2, 3 },{ 4, 5, 6 },{ 32, 1, 98 } };
	int arraySize = sizeof(myVecArray) / sizeof(Vector3);

	std::ofstream fout("data.dat", std::ios::out | std::ios::binary);
	if (fout.good()) {
		for (int i = 0; i < arraySize; i++) {
			fout.write((char*)&myVecArray[i], sizeof(Vector3));
		}
		fout.flush();
		fout.close();
	}
}

void saveGame(saveData data)
{
	int arraySize = sizeof(data);

	std::ofstream fout("playerData.dat", std::ios::out | std::ios::binary);
	if (!fout.good())
	{
		return;
	}
		//for (int i = 0; i < arraySize; i++) {
			fout.write((char*)&data, sizeof(saveData));
		//}
		//fout.flush();
		fout.close();
}

void loadGame(std::string path)
{
	saveData mySave;
	std::ifstream fin(path, std::ios::in | std::ios::binary);
	if (!fin.good())
	{
		return;
	}
	while(!fin.eof() && fin.peek() != EOF) {
		fin.read((char*)&mySave, sizeof(saveData));
		std::cout << mySave.playerName << " " << mySave.deathCount 
			<< " " << mySave.deepestFloor << " " << mySave.hasBeenBeatenGame 
			<< " " << mySave.timePlayed << std::endl;
	}
	fin.close();
}

void bestiaryPrint(int a)
{
	switch (a)
	{
	case 1: 
		std::cout << "What would you like to do?" << std::endl << std::endl;
		std::cout << "1) Add a monster by ID" << std::endl;
		std::cout << "2) Remove a monster by ID" << std::endl;
		std::cout << "3) Visit a monster by ID" << std::endl;
		std::cout << "4) Browse monsters" << std::endl;
		std::cout << "5) Exit" << std::endl;
		std::cout << std::endl << "> ";

		break;
	case 2:

	default:
		break;
	}
}

void bestiaryAdd()
{
	beasiaryEntry myEntry;
	std::string filePath;

	while (true) {
		std::cout << "Enter the ID of the new Monster (This will overwrite existing IDs)" << std::endl << " >";
		std::cin >> myEntry.ID;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			std::cin.ignore(50, '\n');
			std::cin.clear();
			
			continue;
		}
		else { break; }
	}

	/*std::cout << "Enter the ID of the new Monster (This will overwrite existing IDs)" << std::endl << " >";
	std::cin >> myEntry.ID;
	std::cin.clear();
	std::cin.ignore(50, '\n');
	while ( !(myEntry.ID <= 10 && myEntry.ID >= 1) )
	{
		std::cout << "Please enter a positive integer" << std::endl << " >";
		std::cin >> myEntry.ID;
		std::cin.clear();
		std::cin.ignore(50, '\n');
	}*/

	
	std::cout << "Enter the name of the new Monster" << std::endl << " >";
	std::cin.getline(myEntry.name, 20);
	std::cin.ignore(50, '\n');
	std::cin.clear();
	
	
	
	std::cout << "Enter some flavor text" << std::endl << " >";
	std::cin.getline(myEntry.flavorText, 50);
	std::cin.clear();


	filePath = "bestiary\\" + std::to_string(myEntry.ID) + ".dat";
	//std::cout << filePath << std::endl;
	std::ofstream fout(filePath, std::ios::out | std::ios::binary);
	if (!fout.good())
	{
		return;
	}
	fout.write((char*)&myEntry, sizeof(beasiaryEntry));

	fout.flush();
	fout.close();
}

void bestiaryRemove()
{
	int ID;
	std::cout << "Enter the ID of the monster you wish to delete" << std::endl;
	std::cin >> ID;
	std::string filePath = "bestiary\\" + std::to_string(ID) + ".dat";
	remove(filePath.c_str());
}

void bestiaryView()
{
	int ID;
	std::cout << "Enter the ID of the monster to view" << std::endl;
	std::cin >> ID;

	beasiaryEntry myEntry;
	std::string filePath = "bestiary\\" + std::to_string(ID) + ".dat";

	std::ifstream fin(filePath, std::ios::in | std::ios::binary);
	if (!fin.good())
	{
		std::cout << "That entry does not exist." << std::endl;
		return;
	}
	while (!fin.eof() && fin.peek() != EOF) {
		fin.read((char*)&myEntry, sizeof(beasiaryEntry));
		
	}
	std::cout << "-------------" << std::endl;
	std::cout << myEntry.ID << " " << myEntry.name << " - " << myEntry.flavorText
		<< std::endl << std::endl << std::endl << "-------------" << std::endl;
	fin.close();
}

void bestiaryList()
{
	int min, max;
	std::cout << "Enter a range of ids to view" << std::endl;
	std::cin >> min;
	std::cin >> max;

	for (int i = 1; i < 11; i++)
	{
		beasiaryEntry myEntry;
		std::string filePath = "bestiary\\" + std::to_string(i) + ".dat";

		std::ifstream fin(filePath, std::ios::in | std::ios::binary);
		if (fin.good())
		{
			while (!fin.eof() && fin.peek() != EOF) {
				fin.read((char*)&myEntry, sizeof(beasiaryEntry));

			}
			std::cout << i << " " << myEntry.name << std::endl;
			fin.close();
		}
		else
		{
			std::cout << i << " NO ENTRY" << std::endl;
		}
		
		
	}
}