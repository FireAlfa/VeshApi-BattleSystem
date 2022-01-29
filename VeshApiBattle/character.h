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

	Character(CharacterInfo _cInfo);
	~Character();

	// Getters
	std::string GetName() { return cInfo.name; };
	int GetHP() { return (int)cInfo.hp; };
	int GetATK() { return (int)cInfo.atk; };
	int GetDEF() { return (int)cInfo.def; };
	int GetSPD() { return (int)cInfo.spd; };

	// Setters
	void ApplyEffect(float4 effect);
	float2 ReceiveDamage(int dmg);
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