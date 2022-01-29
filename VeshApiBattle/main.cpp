#include "battle.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>



int CalculateStarter(Battle* b );
void DrawTeams(Player* player, Player* enemy, unsigned int starter, int turn);

int main()
{
	// ----- Variables -----
	srand(time(NULL));
	bool e = false;
	int charactersCreated = 0;
	char characterChoice = 'a';
	char itemChoice = 'a';
	unsigned int battleChoice = 0;
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
		std::cin >> cI.hp;
		printf_s("ATK: ");
		std::cin >> cI.atk;
		printf_s("DEF: ");
		std::cin >> cI.def;
		printf_s("SPD: ");
		std::cin >> cI.spd;
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
	while (itemChoice != 'n' && itemChoice != 'y')
	{
		printf_s("Does your party have any items? (y/n)  ");
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
		printf_s("Do you have another item? (y/n)  ");
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
	battles.at(0)->GetEnemy()->GetCharacterAt(2);
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
			for (unsigned int i = 0; i < battles.size(); i++)
			{
				printf_s("%d.- %s\n", i + 1, battles.at(i)->GetName().c_str());
			}
			printf_s("%d.- Exit\n", (int)battles.size() + 1);
			std::cin >> battleChoice;
			
			if (battleChoice > (battles.size() + 1) || battleChoice == 0)
			{
				battleChoice = 0;
				e = true;
			}
			if (battleChoice == battles.size() + 1)
			{
				battleHasFinished = true;
				emulatorEnd = true;
			}
		}
		// --------------------------------------------------



		// ----- BATTLE EMULATION -----
		battleChoice--;
		int starter, turn = 0;
		bool enemyAttacked = false;
		float2 playerAttacksEff;
		float2 aiAttacksEff;
		if (!battleHasFinished)
		{
			starter = CalculateStarter(battles.at(battleChoice));
			turn = starter;
		}

		while (!battleHasFinished)
		{
			system("cls");

			Player* player = battles.at(battleChoice)->GetPlayer();
			Player* enemy = battles.at(battleChoice)->GetEnemy();

			int randomAttacker = (rand() % enemy->GetCharacters().size());
			int randomTarget = (rand() % player->GetCharacters().size());

			// ----- DRAW TEAMS -----
			DrawTeams(player, enemy, starter, turn);
			// -------------------------


			if (enemyAttacked)
			{
				if (starter == 0)
				{
					printf("\n|| Enemy attacked %s with %s in turn %d ||\n", player->GetCharacterAt(randomTarget)->GetName().c_str(), enemy->GetCharacterAt(randomAttacker)->GetName().c_str(), turn);
					enemyAttacked = false;
				}
				else
				{
					printf("\n|| Enemy attacked %s with %s in turn %d ||\n", player->GetCharacterAt(randomTarget)->GetName().c_str(), enemy->GetCharacterAt(randomAttacker)->GetName().c_str(), turn - 1);
					enemyAttacked = false;
				}
			}

			printf("\nObjects in inventory: |");
			for (unsigned int i = 0; i < player->GetObjects().size(); i++)
			{
				printf(" (%d) %s |", player->GetObjects().at(i)->GetID(), player->GetObjects().at(i)->GetName().c_str());
			}
			printf("\n\n");


			// ----- ACTIONS -----
			
			// Player actions
			if (turn % 2 == 0)
			{
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
					unsigned int attacker = 0;
					printf("Select an attacker: ( ");
					for (unsigned int i = 0; i < player->GetCharacters().size(); i++)
					{
						printf("%d ", i + 1);
					}
					printf(")  ");
					while (attacker <= 0 || attacker > player->GetCharacters().size() + 1)
					{
						std::cin >> attacker;
					}
					printf("Attacker selected: %s\n", player->GetCharacterAt(attacker - 1)->GetName().c_str());
					printf("Select a target: ( ");
					for (unsigned int i = 0; i < enemy->GetCharacters().size(); i++)
					{
						printf("%d ", i + 1);
					}
					printf(")  ");
					unsigned int target = 0;
					while (target <= 0 || target > enemy->GetCharacters().size() + 1)
					{
						std::cin >> target;
					}
					playerAttacksEff = enemy->GetCharacterAt(target - 1)->ReceiveDamage(player->GetCharacterAt(attacker - 1)->GetATK());

					turn++;
					break;
				}
				case 2: // Use Object
				{
					unsigned int obj = 0;

					if (player->GetObjects().size() == 0)
					{
						printf("\nYou have no objects in your inventory.\n");
					}
					else {
						printf("\n Choose what object to use: ");
						while (obj <= 0 || obj > player->GetObjects().size() + 1)
						{
							std::cin >> obj;
						}
						printf("Object seleted: (%d) %s\n", obj, player->GetObjects().at(obj - 1)->GetName().c_str());
						printf("Select a target: ( ");
						for (unsigned int i = 0; i < player->GetCharacters().size(); i++)
						{
							printf("%d ", i + 1);
						}
						printf(")  ");
						unsigned int target = 0;
						while (target <= 0 || target > player->GetCharacters().size())
						{
							std::cin >> target;
						}
						player->GetCharacterAt(target - 1)->ApplyEffect(player->GetObjects().at(obj - 1)->GetEffect());
						player->RemoveObject(obj - 1);
					}
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
				
			}
			else
			{ // IA Actions
				playerAttacksEff = player->GetCharacterAt(randomTarget)->ReceiveDamage(enemy->GetCharacterAt(randomAttacker)->GetATK());
				enemyAttacked = true;
				turn++;
			}

			if (battleHasFinished)
			{
				player->ResetPlayer();
				enemy->ResetPlayer();
			}
		}
		// --------------------------------------------------
		
		
		system("cls");
		characterChoice = 'a';
		while (characterChoice != 'y' && characterChoice != 'n' && !emulatorEnd)
		{
			printf("\nDo you want to emulate another battle? (y/n)  ");
			std::cin >> characterChoice;
			if (characterChoice != 'y' && characterChoice != 'n')
			{
				printf_s("Enter a valid option.\n");
			}
			if (characterChoice == 'n')
			{
				emulatorEnd = true;
			}
			else
			{
				battleChoice = 0;
				battleHasFinished = false;
			}
		}

	} while (!emulatorEnd);


	return 0;
}


// Returns 0 if the player starts and 1 if the enemy starts
int CalculateStarter(Battle* b)
{
	// Total player Speed
	int pSPD = 0;
	for (unsigned int i = 0; i < b->GetPlayer()->GetCharacters().size(); i++)
	{
		pSPD += b->GetPlayer()->GetCharacterAt(i)->GetSPD();
	}

	// Total enemy Speed
	int eSPD = 0;
	for (unsigned int i = 0; i < b->GetEnemy()->GetCharacters().size(); i++)
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

void DrawTeams(Player* player, Player* enemy, unsigned int starter, int turn)
{
	if (starter == 0)
		turn += 1;

	printf("                Turn %d\n", turn);

	printf(" ===========  Enemy Team  ===========");
	if (starter == 1)
	{
		printf("      This player starts");
	}
	printf("\n");
	for (unsigned int i = 0; i < enemy->GetCharacters().size(); i++)
	{
		printf("   %s   ", enemy->GetCharacterAt(i)->GetName().c_str());
	}
	printf("\n");
	for (unsigned int i = 0; i < enemy->GetCharacters().size(); i++)
	{
		printf("   %d HP     ", enemy->GetCharacterAt(i)->GetHP());
	}
	printf("\n");
	for (unsigned int i = 0; i < enemy->GetCharacters().size(); i++)
	{
		printf("   %d ATK     ", enemy->GetCharacterAt(i)->GetATK());
	}
	printf("\n");
	for (unsigned int i = 0; i < enemy->GetCharacters().size(); i++)
	{
		printf("   %d DEF     ", enemy->GetCharacterAt(i)->GetDEF());
	}
	printf("\n\n\n\n\n\n");
	for (unsigned int i = 0; i < player->GetCharacters().size(); i++)
	{
		printf("   %s   ", player->GetCharacterAt(i)->GetName().c_str());
	};
	printf("\n");
	for (unsigned int i = 0; i < player->GetCharacters().size(); i++)
	{
		printf("   %d HP     ", player->GetCharacterAt(i)->GetHP());
	}
	printf("\n");
	for (unsigned int i = 0; i < player->GetCharacters().size(); i++)
	{
		printf("   %d ATK     ", player->GetCharacterAt(i)->GetATK());
	}
	printf("\n");
	for (unsigned int i = 0; i < player->GetCharacters().size(); i++)
	{
		printf("   %d DEF     ", player->GetCharacterAt(i)->GetDEF());
	}
	printf("\n ===========  %s's Team  ===========", player->GetName().c_str());
	if (starter == 0)
	{
		printf("      This player starts");
	}
	printf("\n");
}