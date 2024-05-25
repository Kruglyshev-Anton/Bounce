#pragma once
#include "FullObjects.h"
class Spider:public FullObjects
{
private:
	float x, y;

public:
	Spider(float x, float y);
	std::string getType() override;
	void Draw()override;
};

