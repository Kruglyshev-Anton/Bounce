#pragma once
#include "Block.h"
class TriangleBlock:public FullObjects
{
private:
	float x, y;
	int config;

public:
	TriangleBlock(float x, float y, int config);
	void Draw() override;
	std::string getType() override;
};

