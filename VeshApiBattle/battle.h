#pragma once

#include "player.h"



class Battle
{
public:

	Battle(std::string _name);
	~Battle();

	void AddPlayer(Player* p);
	void CreateEnemy(std::string _name);

	// Getters
	std::string GetName() { return name; };
	Player* GetPlayer() { return players.at(0); };
	Player* GetEnemy() { return players.at(1); };
	Player* GetEnemyAt(int i) { return players.at(i); };

private:

	
	void AddEnemy(Player* p);

private:

	bool playerCreated = false;
	std::string name = "New Battle";
	std::vector<Player*> players;
	int turn = 0;
};