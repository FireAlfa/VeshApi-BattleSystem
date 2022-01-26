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

}