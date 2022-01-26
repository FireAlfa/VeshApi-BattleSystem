#pragma once

#include "character.h"
#include "object.h"



class Player
{
public:

	Player(std::string _name);
	~Player();

	void CreateCharacter(CharacterInfo cI);
	void CreateObject(int id;

private:

	void AddCharacter(Character* c);
	void AddObject(Object* o);

private:

	std::string name;
	std::vector<Character*> characters;
	std::vector<Object*> objects;
};