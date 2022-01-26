#include "battle.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <vector>



void main()
{
	// Variables
	bool e = false;
	int charactersCreated = 0;
	char characterChoice = 'a';
	char itemChoice = 'a';
	int battleChoice = 0;
	std::vector<Battle*> battles;


	// ----- CREATE THE PLAYER'S PARTY -----
	printf_s("\n\n----- Create your party ----- \n\n");
	printf_s("Enter your name: ");
	std::string pName;
	std::cin >> pName;
	Player* player = new Player(pName);
	while (charactersCreated < 3 && characterChoice != 'n')
	{
		CharacterInfo cI;

		printf_s("Character %d Info: \n", charactersCreated + 1);
		printf_s("Name: ");
		std::cin >> cI.name;
		printf_s("HP: ");
		scanf_s("%d", &cI.hp);
		printf_s("ATK: ");
		scanf_s("%d", &cI.atk);
		printf_s("DEF: ");
		scanf_s("%d", &cI.def);
		printf_s("SPD: ");
		scanf_s("%d", &cI.spd);
		printf_s("\n");

		charactersCreated++;
		player->CreateCharacter(cI);
		cI.Reset();

		while (characterChoice != 'y' && characterChoice != 'n')
		{
			printf_s("You can have up to 3 characters in a party, do you want to create another one? (y/n)  ");
			std::cin >> characterChoice;
			if (characterChoice != 'y' && characterChoice != 'n')
			{
				printf_s("Enter a valid option.\n");
			}
		}
	}
	printf_s("\n");
	while (itemChoice != 'n')
	{
		printf_s("\Does your party have any items? (y/n)  ");
		std::cin >> itemChoice;
		if (itemChoice != 'y' && itemChoice != 'n')
		{
			printf_s("Enter a valid option.\n");
		}
	}
	while (itemChoice == 'y')
	{
		int id;
		printf_s("Insert item ID: ");
		std::cin >> id;
		player->CreateObject(id);
		printf_s("\Do you have another item? (y/n)  ");
		std::cin >> itemChoice;
		if (itemChoice != 'y' && itemChoice != 'n')
		{
			printf_s("Enter a valid option.\n");
		}
	}
	

	// --------------------------------------------------



	// ----- CREATE ALL BATTLES -----
	// First we add the new battle to the vector
	battles.push_back(new Battle("Battle 1"));
	//Then we create the enemy team
	battles.at(0)->CreateEnemy("Enemy");
	// We then add the needed characters for the enemy
	CharacterInfo cI = { "Enemy 1", 10, 2, 1, 2 };
	battles.at(0)->GetEnemy()->CreateCharacter(cI);
	// --------------------------------------------------



	// ----- CHOOSE WHAT BATTLE TO TEST -----
	while (battleChoice == 0)
	{
		if (e == true)
		{
			printf_s("Choose a valid number! \n\n");
			e = false;
		}
		printf_s("What Battle do you want to simulate?\n");
		for (int i = 0; i < battles.size(); i++)
		{
			printf_s("%d.- %s\n", i + 1, battles.at(i)->GetName().c_str());
		}
		scanf_s("%d", &battleChoice);

		if (battleChoice > battles.size() || battleChoice == 0)
		{
			battleChoice = 0;
			e = true;
		}

		system("cls");
	}
	// --------------------------------------------------

	system("pause");
}


void CreateBattles(std::vector<Battle*> )
{


}