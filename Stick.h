#pragma once
#include "FullObjects.h"
class Stick:public FullObjects
{
private:
	float x, y;

public:
	Stick(float x, float y);
	std::string getType() override;
	void Draw()override;
};

