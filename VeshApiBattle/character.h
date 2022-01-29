#pragma once

#include <string>
#include <vector>
#include <WindowsNumerics.h>



using namespace Windows::Foundation::Numerics;

struct CharacterInfo
{
	std::string name = "EmptyChar";
	float hp = 0, atk = 0, def = 0, spd = 0;

	void Reset()
	{
		name = "EmptyChar";
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

	// Getters
	std::string GetName() { return cInfo.name; };
	int GetHP() { return (int)cInfo.hp; };
	int GetATK() { return (int)cInfo.atk; };
	int GetDEF() { return (int)cInfo.def; };
	int GetSPD() { return (int)cInfo.spd; };

	// Setters
	void ApplyEffect(float4 effect)
	{
		cInfo.hp += (int)effect.x;
		cInfo.atk += (int)effect.y;
		cInfo.def += (int)effect.z;
		cInfo.spd += (int)effect.w;
	}
	void ReceiveDamage(int dmg)
	{
		int miss = rand() % 10;
		int crit = rand() % 20;
		int block = rand() % 20;
		int blunder = rand() % 20;

		if (miss == 0 || block == 0)
			dmg = 0;

		if (crit == 0)
			dmg = (float)dmg + 0.5f * (float)dmg;

		if (blunder != 0)
			dmg -= (int)cInfo.def;

		if (dmg > 0)
				cInfo.hp -= (float)dmg;

		if (cInfo.hp < 0)
			cInfo.hp = 0;
	}
	void SetName(std::string n) { cInfo.name = n; };
	void SetHP(int v) { cInfo.hp = (float)v; };
	void SetATK(int v) { cInfo.atk = (float)v; };
	void SetDEF(int v) { cInfo.def = (float)v; };
	void SetSPD(int v) { cInfo.spd = (float)v; };

public:

	CharacterStatus status = CharacterStatus::RESTED;

private:

	CharacterInfo cInfo;
};