#pragma once
#include"FullObjects.h"
class Block:public FullObjects
{
private:
	float x, y, h=one_cell_size, w=one_cell_size;

public:
	Block(float x, float y);
	void Draw() override;
	std::string getType();
};

