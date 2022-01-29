#include "character.h"



Character::Character(CharacterInfo _cInfo)
{
	cInfo = _cInfo;
}
Character::~Character()
{

}

void Character::ApplyEffect(float4 effect)
{
	cInfo.hp += (int)effect.x;
	cInfo.atk += (int)effect.y;
	cInfo.def += (int)effect.z;
	cInfo.spd += (int)effect.w;
}

float2 Character::ReceiveDamage(int dmg)
{
	int atk = rand() % 20;
	int def = rand() % 20;

	if (atk == 0 || atk == 1 || def == 0) // atk 0 & 1 -> miss atk, def 0 -> perfect block
		dmg = 0;

	if (atk == 19) // atk 19 -> critical attack
		dmg = (float)dmg + 0.5f * (float)dmg;

	if (def != 19 && def != 0) // def 19 -> normal damage, def != 19 -> no defense
		dmg -= (int)cInfo.def;

	if (dmg > 0)
		cInfo.hp -= (float)dmg;

	if (cInfo.hp < 0)
		cInfo.hp = 0;

	float fatk = 0; // Normal attack
	if (atk == 0 || atk == 1)
		fatk = 1; // Missed attack
	if (atk == 19)
		fatk = 2; // Critical attack

	float fdef = 0; // Normal defense
	if (def != 19 && def != 0)
		fdef = 1; // Blunder block
	if (def == 0)
		fdef = 2; // Perfect block

	return { fatk, fdef };
}