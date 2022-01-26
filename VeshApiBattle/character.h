#pragma once

#include <string>
#include <vector>



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
	int GetHP() { return cInfo.hp; };
	int GetATK() { return cInfo.atk; };
	int GetDEF() { return cInfo.def; };
	int GetSPD() { return cInfo.spd; };

	// Setters
	void ApplyEffect(float4 effect)
	{
		cInfo.hp += effect.x;
		cInfo.atk += effect.y;
		cInfo.def += effect.z;
		cInfo.spd += effect.w;
	}
	void SetName(std::string n) { cInfo.name = n; };
	void SetHP(int v) { cInfo.hp = v; };
	void SetATK(int v) { cInfo.atk = v; };
	void SetDEF(int v) { cInfo.def = v; };
	void SetSPD(int v) { cInfo.spd = v; };

public:

	CharacterStatus status = CharacterStatus::RESTED;

private:

	CharacterInfo cInfo;
};