#pragma once
#include"FullObjects.h"
class Ring:public FullObjects
{
private:
	float x, y;
public:
	Ring(float x, float y);
	void Draw() override;
	std::string getType() override;
};

