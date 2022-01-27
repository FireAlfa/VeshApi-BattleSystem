#pragma once

#include "character.h"
#include "object.h"



class Player
{
public:

	Player(std::string _name);
	~Player();

	void CreateCharacter(CharacterInfo cI);
	void CreateObject(int id);
	void RemoveObject(int i);

	void ResetPlayer() { characters = creationCharacters; objects = creationObjects; };

	// Getters
	Character* GetCharacterAt(int i) { return characters.at(i); };
	std::vector<Character*> GetCharacters() { return characters; };
	std::vector<Object*> GetObjects() { return objects; };
	std::string GetName() { return name; };

private:

	void AddCharacter(Character* c);
	void AddObject(Object* o);

private:

	std::string name;
	std::vector<Character*> characters;
	std::vector<Character*> creationCharacters;
	std::vector<Object*> objects;
	std::vector<Object*> creationObjects;
};