#pragma once

#include <string>
#include <WindowsNumerics.h>



using namespace Windows::Foundation::Numerics;

class Object
{
public:

	Object(int _id);
	~Object();

	// Getters
	int GetID() { return id; };
	std::string GetName() { return name; };
	float4 GetEffect() { return effect; };

private:

	int id;
	std::string name;
	float4 effect = { 0.0f, 0.0f, 0.0f, 0.0f };
};