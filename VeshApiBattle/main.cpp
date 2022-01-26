#include "battle.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <vector>



int CalculateStarter(Battle* b );

void main()
{
	// ----- Variables -----
	bool e = false;
	int charactersCreated = 0;
	char characterChoice = 'a';
	char itemChoice = 'a';
	int battleChoice = 0;
	bool battleHasFinished = false;
	bool emulatorEnd = false;
	std::vector<Battle*> battles;
	// --------------------------------------------------



	// ----- CREATE THE PLAYER'S PARTY -----
	printf_s("\n----- Create your party ----- \n\n");
	printf_s("Enter your name: ");
	std::string pName;
	std::cin >> pName;
	Player* player = new Player(pName);
	while (charactersCreated < 3 && characterChoice != 'n')
	{
		CharacterInfo cI;
		characterChoice = 'a';

		printf_s("\nCharacter %d Info \n", charactersCreated + 1);
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

		while (characterChoice != 'y' && characterChoice != 'n' && charactersCreated < 3)
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
	while (itemChoice != 'y')
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



	// ----- CREATE ALL BATTLES  !!!MANUALLY!!! -----
	// First we add the new battle to the vector
	battles.push_back(new Battle("Battle 1"));
	// We add the player we just created
	battles.at(0)->AddPlayer(player);
	//Then we create the enemy team
	battles.at(0)->CreateEnemy("Enemy");
	// We then add the needed characters for the enemy party
	CharacterInfo cI = { "Enemy 1", 10, 2, 1, 2 };
	battles.at(0)->GetEnemy()->CreateCharacter(cI);
	cI = { "Enemy 2", 10, 2, 1, 2 };
	battles.at(0)->GetEnemy()->CreateCharacter(cI);
	cI = { "Enemy 3", 10, 2, 1, 2 };
	battles.at(0)->GetEnemy()->CreateCharacter(cI);
	// --------------------------------------------------



	// ----- CHOOSE WHAT BATTLE TO TEST -----
	do {
		while (battleChoice == 0)
		{
			system("cls");

			if (e == true)
			{
				printf_s("Choose a valid number! \n\n");
				e = false;
			}
			printf_s("\n\n ----- What Battle do you want to simulate? -----\n");
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
		}
		// --------------------------------------------------



		// ----- BATTLE EMULATION -----
		battleChoice--;
		int starter = CalculateStarter(battles.at(battleChoice));
		do {
			system("cls");

			// ----- DRAW TEAMS -----
			printf(" ===========  Enemy Team  ===========");
			if (starter == 1)
			{
				printf("      This player starts");
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetEnemy()->GetCharacters().size(); i++)
			{
				printf("   %s   ", battles.at(battleChoice)->GetEnemy()->GetCharacterAt(i)->GetName().c_str());
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetEnemy()->GetCharacters().size(); i++)
			{
				printf("   %d HP     ", battles.at(battleChoice)->GetEnemy()->GetCharacterAt(i)->GetHP());
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetEnemy()->GetCharacters().size(); i++)
			{
				printf("   %d ATK     ", battles.at(battleChoice)->GetEnemy()->GetCharacterAt(i)->GetATK());
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetEnemy()->GetCharacters().size(); i++)
			{
				printf("   %d DEF     ", battles.at(battleChoice)->GetEnemy()->GetCharacterAt(i)->GetDEF());
			}
			printf("\n\n\n\n\n\n");
			for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetCharacters().size(); i++)
			{
				printf("   %s   ", battles.at(battleChoice)->GetPlayer()->GetCharacterAt(i)->GetName().c_str());
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetCharacters().size(); i++)
			{
				printf("   %d HP     ", battles.at(battleChoice)->GetPlayer()->GetCharacterAt(i)->GetHP());
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetCharacters().size(); i++)
			{
				printf("   %d ATK     ", battles.at(battleChoice)->GetPlayer()->GetCharacterAt(i)->GetATK());
			}
			printf("\n");
			for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetCharacters().size(); i++)
			{
				printf("   %d DEF     ", battles.at(battleChoice)->GetPlayer()->GetCharacterAt(i)->GetDEF());
			}
			printf("\n ===========  %s's Team  ===========", battles.at(battleChoice)->GetPlayer()->GetName().c_str());
			if (starter == 0)
			{
				printf("      This player starts");
			}
			printf("\n");
			printf("Objects in inventory: |");
			for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetObjects().size(); i++)
			{
				printf(" (%d) %s |", battles.at(battleChoice)->GetPlayer()->GetObjects().at(i)->GetID(), battles.at(battleChoice)->GetPlayer()->GetObjects().at(i)->GetName().c_str());
			}
			printf("\n\n");
			// -------------------------


			// ----- CHOOSE ACTION -----
			printf("Actions:\n");
			printf("1.- Attack\n");
			printf("2.- Use Object\n");
			printf("3.- Run\n");
			int o = 0;
			while (o != 1 && o != 2 && o != 3)
			{
				std::cin >> o;
			}

			switch (o)
			{
			case 1: // Attack
			{
				int attacker = 0;
				printf("Select an attacker: ( ");
				for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetCharacters().size(); i++)
				{
					printf("%d ", i + 1);
				}
				while (attacker <= 0 || attacker > battles.at(battleChoice)->GetPlayer()->GetCharacters().size() + 1)
				{
					std::cin >> attacker;
				}
				printf("Attacker selected: %s\n", battles.at(battleChoice)->GetPlayer()->GetCharacterAt(attacker - 1)->GetName().c_str());
				printf("Select a target: ( ");
				for (int i = 0; i < battles.at(battleChoice)->GetEnemy()->GetCharacters().size(); i++)
				{
					printf("%d ", i + 1);
				}
				printf(")  ");
				int target = 0;
				while (target <= 0 || target > battles.at(battleChoice)->GetPlayer()->GetCharacters().size() + 1)
				{
					std::cin >> target;
				}
				battles.at(battleChoice)->GetEnemy()->GetCharacterAt(target - 1)->ReceiveDamage(battles.at(battleChoice)->GetPlayer()->GetCharacterAt(attacker - 1)->GetATK());

				break;
			}
			case 2: // Use Object
			{
				int obj = 0;
				printf("\n Choose what object to use: ");
				while (obj <= 0 || obj > battles.at(battleChoice)->GetPlayer()->GetObjects().size() + 1)
				{
					std::cin >> obj;
				}
				printf("Object seleted: (%d) %s", obj, battles.at(battleChoice)->GetPlayer()->GetObjects().at(obj - 1)->GetName().c_str());
				printf("Select a target: ( ");
				for (int i = 0; i < battles.at(battleChoice)->GetPlayer()->GetCharacters().size(); i++)
				{
					printf("%d ", i + 1);
				}
				printf(")  ");
				int target = 0;
				while (target <= 0 || target > battles.at(battleChoice)->GetPlayer()->GetCharacters().size())
				{
					std::cin >> target;
				}
				battles.at(battleChoice)->GetPlayer()->GetCharacterAt(target - 1)->ApplyEffect(battles.at(battleChoice)->GetPlayer()->GetObjects().at(obj - 1)->GetEffect());

				break;
			}
			case 3: // Run
			{
				battleHasFinished = true;
				printf("\nYou finished the battle.\n");
				system("pause");
				break;
			}
			default:
				break;
			}
			// -------------------------

		} while (!battleHasFinished);
		// --------------------------------------------------
		
		
		battles.at(battleChoice)->GetPlayer()->ResetPlayer();
		battles.at(battleChoice)->GetEnemy()->ResetPlayer();
		system("cls");
		while (characterChoice != 'y' && characterChoice != 'n')
		{
			printf("\nDo you want to emulate another battle? (y/n)  ");
			std::cin >> characterChoice;
			if (characterChoice != 'y' && characterChoice != 'n')
			{
				printf_s("Enter a valid option.\n");
			}
			if (characterChoice == 'y')
			{
				emulatorEnd = true;
			}
		}

	} while (!emulatorEnd);

	system("pause");
}


// Returns 0 if the player starts and 1 if the enemy starts
int CalculateStarter(Battle* b)
{
	// Total player Speed
	int pSPD = 0;
	for (int i = 0; i < b->GetPlayer()->GetCharacters().size(); i++)
	{
		pSPD += b->GetPlayer()->GetCharacterAt(i)->GetSPD();
	}

	// Total enemy Speed
	int eSPD = 0;
	for (int i = 0; i < b->GetEnemy()->GetCharacters().size(); i++)
	{
		eSPD += b->GetEnemy()->GetCharacterAt(i)->GetSPD();
	}

	if (pSPD >= eSPD)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}