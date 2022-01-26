#include "battle.h"



Battle::Battle(std::string _name) : name(_name)
{

}
Battle::~Battle()
{

}

void Battle::AddPlayer(Player* p)
{
	if (!playerCreated)
	{
		players.insert(players.begin(), p);
	}

	playerCreated = true;
}

void Battle::CreateEnemy(std::string _name)
{
	Player* p = new Player(_name);

	AddEnemy(p);
}
void Battle::AddEnemy(Player* p)
{
	players.push_back(p);
}