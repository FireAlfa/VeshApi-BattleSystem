#include "player.h"



Player::Player(std::string _name)
{
	name = _name;
}

Player::~Player()
{

}

void Player::CreateCharacter(CharacterInfo cI)
{
	Character* c = new Character(cI);

	AddCharacter(c);
}
void Player::AddCharacter(Character* c)
{
	characters.push_back(c);
}

void Player::CreateObject(int id)
{
	Object* o = new Object(id);

	AddObject(o);
}
void Player::AddObject(Object* o)
{
	objects.push_back(o);
	creationObjects.push_back(o);
}
void Player::RemoveObject(int i)
{
	objects.erase(objects.begin() + i);
}