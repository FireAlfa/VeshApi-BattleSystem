#pragma once

#include <string>
#include <vector>



struct CharacterInfo
{
	std::string name;
	int hp, atk, def, spd;

	void Reset()
	{
		name = " ";
		hp = 0;
		atk = 0;
		def = 0;
		spd = 0;
	}
};

enum class CharacterStatus
{
	NONE = 0,
	RESTED,
	TIRED,
};

class Character
{
public:

	Character(CharacterInfo _cInfo)
	{
		cInfo = _cInfo;
	}
	~Character() {}

public:

	CharacterStatus status = CharacterStatus::RESTED;

private:

	CharacterInfo cInfo;
};