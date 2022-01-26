#include "object.h"



Object::Object(int _id) : id(_id)
{
	// You get the id from the object table
	// Each item has a name and an effect
	// Each float of the effect corresponds to a stat
	// { HP, ATK, DEF, SPD }
	switch (id)
	{
	case 1:
		name = "Item1";
		effect = { 0.0f, 0.0f, 0.0f, 0.0f };
		break;
	case 2:
		name = "Item2";
		effect = { 0.0f, 0.0f, 0.0f, 0.0f };
		break;
	case 3:
		name = "Item3";
		effect = { 0.0f, 0.0f, 0.0f, 0.0f };
		break;
	case 4:
		name = "Item4";
		effect = { 0.0f, 0.0f, 0.0f, 0.0f };
		break;
	case 5:
		name = "Item5";
		effect = { 0.0f, 0.0f, 0.0f, 0.0f };
		break;
	case 6:
		name = "Item6";
		effect = { 0.0f, 0.0f, 0.0f, 0.0f };
		break;
	default:
		break;
	}
}
Object::~Object()
{

}