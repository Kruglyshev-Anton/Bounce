#pragma once
#include"FullObjects.h"
class Ball:public FullObjects
{
private:
	float x, y;

public:
	Ball(float x, float y);
	std::string getType() override;
	void Draw()override;
};

